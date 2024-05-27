
#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

#include "Arduino.h"

#include "BitsAndDroidsFlightConnector.h"

BitsAndDroidsFlightConnector::BitsAndDroidsFlightConnector() {
  this->serial = &Serial;
}

#if !defined(ARDUINO_SAM_DUE) && !defined(ESP32)
BitsAndDroidsFlightConnector::BitsAndDroidsFlightConnector(
    SoftwareSerial *serial) {
  this->serial = serial;
}
#elif defined(ARDUINO_SAM_DUE)
BitsAndDroidsFlightConnector::BitsAndDroidsFlightConnector(Serial_ *serial) {
  this->serial = serial;
}
#elif defined(ESP32)
BitsAndDroidsFlightConnector::BitsAndDroidsFlightConnector(
    HardwareSerial *serial) {
  this->serial = &Serial;
}
#else
BitsAndDroidsFlightConnector::BitsAndDroidsFlightConnector(
    SoftwareSerial *serial) {
  this->serial = serial;
}
#endif

int BitsAndDroidsFlightConnector::smoothPot(byte potPin) {
  int readings[samples] = {};
  total = 0;
  for (int &reading : readings) {
    total = total - reading;
    reading = analogRead(potPin);
    total = total + reading;
    delay(1);
  }
  average = total / samples;
  return average;
}

void BitsAndDroidsFlightConnector::sendSetYokeAxis(byte elevatorPin,
                                                   byte aileronPin) {

  elevator = smoothPot(elevatorPin);

  aileron = smoothPot(aileronPin);

  if (abs(elevator - oldElevator) > analogDiff ||
      abs(oldAileron - aileron) > analogDiff) {
    packagedData = sprintf(valuesBuffer, "%s %i %i", "103", elevator, aileron);
    oldElevator = elevator;
    oldAileron = aileron;
    this->serial->println(valuesBuffer);
  }
}

void BitsAndDroidsFlightConnector::sendCombinedThrottleValues() {
  packagedData = sprintf(valuesBuffer, "%s %i %i %i %i", "199", engines[0],
                         engines[1], engines[2], engines[3]);
  this->serial->println(valuesBuffer);
}

void BitsAndDroidsFlightConnector::sendCombinedPropValues() {
  packagedData = sprintf(valuesBuffer, "%s %i %i", "198", props[0], props[1]);
  this->serial->println(valuesBuffer);
}

void BitsAndDroidsFlightConnector::sendCombinedMixtureValues() {
  packagedData = sprintf(valuesBuffer, "%s %i %i", "115", mixturePercentage[0],
                         mixturePercentage[1]);
  this->serial->println(valuesBuffer);
}

void BitsAndDroidsFlightConnector::sendFlaps() {
  packagedData = sprintf(valuesBuffer, "%s %i", "421", flaps);
  this->serial->println(valuesBuffer);
}

void BitsAndDroidsFlightConnector::sendSetElevatorTrimPot(byte potPin,
                                                          int minVal,
                                                          int maxVal) {
  currentTrim = (EMA_a * analogRead(potPin)) + ((1 - EMA_a) * currentTrim);
  if (currentTrim != oldTrim) {
    int trimFormatted = calculateAxis(currentTrim, 0, 1023);
    packagedData = sprintf(valuesBuffer, "%s %i", "900", trimFormatted);
    oldTrim = currentTrim;
    this->serial->println(valuesBuffer);
  }
}

void BitsAndDroidsFlightConnector::sendSetBrakePot(byte leftPin,
                                                   byte rightPin) {
  currentLeftBrake = smoothPot(leftPin);
  currentRightBrake = smoothPot(rightPin);

  bool changed = false;
  if (abs(oldLeftBrake - currentLeftBrake) > analogDiff) {
    oldLeftBrake = currentLeftBrake;
    changed = true;
  }
  if (abs(oldRightBrake - currentRightBrake) > analogDiff) {
    oldRightBrake = currentRightBrake;
    changed = true;
  }
  if (changed) {
    packagedData = sprintf(valuesBuffer, "%s %i %i", "902", currentLeftBrake,
                           currentRightBrake);
    this->serial->println(valuesBuffer);
  }
}

void BitsAndDroidsFlightConnector::sendSetRudderPot(byte potPin) {
  currentRudder = smoothPot(potPin);
  if (abs(currentRudder - oldRudderAxis) > analogDiff) {
    packagedData = sprintf(valuesBuffer, "%s %i", "901", currentRudder);
    oldRudderAxis = currentRudder;
    this->serial->println(valuesBuffer);
  }
}

void BitsAndDroidsFlightConnector::sendSetKohlmanAltimeterInHg(float value) {
  float mbValue = value * 33.8639;
  int valueToSend = mbValue * 16;
  packagedData = sprintf(valuesBuffer, "%s %d", "377", valueToSend);
  this->serial->println(valuesBuffer);
}

void BitsAndDroidsFlightConnector::sendSetKohlmanAltimeterMb(float value) {
  int valueToSend = value * 16;
  packagedData = sprintf(valuesBuffer, "%s %d", "377", valueToSend);
  this->serial->println(valuesBuffer);
}

int BitsAndDroidsFlightConnector::calculateAxis(int value, int minVal,
                                                int maxVal) {
  return map(value, minVal, maxVal, -16383, 16383);
}

void BitsAndDroidsFlightConnector::sendSetElevatorTrim(int value) {
  packagedData = sprintf(valuesBuffer, "%s %i", "900", value);
  this->serial->println(valuesBuffer);
}

bool convBool(const String &input) {
  if (input == "0") {
    return false;
  } else {
    return true;
  }
}

void BitsAndDroidsFlightConnector::dataHandling() {

  if (this->serial->available() > 0) {
    receivedValue = this->serial->readStringUntil('\n');
    switchHandling();
  }
}

void BitsAndDroidsFlightConnector::switchHandling() {

  prefix = receivedValue.substring(0, 4);
  cutValue = receivedValue.substring(4);
  int prefixVal = prefix.toInt();
  lastPrefix = prefixVal;

  switch (prefixVal) {
  // Ap
  case 4000: {
    fuelLevel = cutValue.toInt();
    break;
  }

  case 1003: {
    lightTaxiOn = true;
    break;
  }
  // lights
  case 133: {
    lightTaxiOn = convBool(cutValue);
    break;
  }
  case 134: {
    lightStrobeOn = convBool(cutValue);
    break;
  }

  case 135: {
    lightPanelOn = convBool(cutValue);
    break;
  }
  case 136: {
    lightRecognitionOn = convBool(cutValue);
    break;
  }
  case 137: {
    lightWingOn = convBool(cutValue);
    break;
  }
  case 138: {
    lightLogoOn = convBool(cutValue);
    break;
  }
  case 139: {
    lightCabinOn = convBool(cutValue);
    break;
  }
  case 140: {
    lightHeadOn = convBool(cutValue);
    break;
  }
  case 141: {
    lightBrakeOn = convBool(cutValue);
    break;
  }
  case 142: {
    lightNavOn = convBool(cutValue);
    break;
  }
  case 143: {
    lightBeaconOn = convBool(cutValue);
    break;
  }
  case 144: {
    lightLandingOn = convBool(cutValue);
    break;
  }
  case 275: {
    fuelTotalPercentage = cutValue.toInt();
    break;
  }
  case 312: {
    feetAboveGround = cutValue.toInt();
    break;
  }
  case 323: {
    onGround = convBool(cutValue);
    break;
  }
  // ambient
  case 650: {
    ambientPressure = cutValue.toInt();
    break;
  }
  case 651: {
    ambientTemperature = cutValue.toFloat();
    break;
  }
  case 652: {
    ambientWindVelocity = cutValue.toFloat();
    break;
  }
  case 653: {
    ambientWindDirection = cutValue.toInt();
    break;
  }
  case 654: {
    ambientPrecipRate = cutValue.toInt();
    break;
  }
  case 655: {
    ambientPrecipState = cutValue.toInt();
    break;
  }
  case 656: {
    headingGyro = cutValue.toInt();
    break;
  }
  case 657: {
    headingMag = cutValue.toInt();
    break;
  }
  case 658: {
    headingTrue = cutValue.toInt();
    break;
  }
  case 659: {
    indicatedAltitudeCalibrated = cutValue.toInt();
    break;
  }

  // time
  case 338: {
    localTime = cutValue;
    break;
  }
  case 339: {
    timezoneOffset = cutValue.toInt();
    break;
  }
  case 340: {
    zuluTime = cutValue;
    break;
  }
    // warnings
  case 333: {
    stallWarning = convBool(cutValue);
    break;
  }
  case 334: {
    overspeedWarning = convBool(cutValue);
    break;
  }
    // GPS
  case 454: {
    gpsCourseToSteer = cutValue.toInt();
  }

    // Flaps
  case 510: {
    flapsHandlePct = cutValue.toInt();
    break;
  }
  case 511: {
    flapsHandleIndex = cutValue.toInt();
    break;
  }
  case 512: {
    flapsNumHandlePos = cutValue.toInt();
    break;
  }
  case 513: {
    trailingEdgeFlapsLeftPercent = cutValue.toInt();
    break;
  }
  case 514: {
    trailingEdgeFlapsRightPercent = cutValue.toInt();
    break;
  }
  case 515: {
    trailingEdgeFlapsLeftAngle = cutValue.toInt();
    break;
  }
  case 516: {
    trailingEdgeFlapsRightAngle = cutValue.toInt();
    break;
  }
  case 517: {
    leadingEdgeFlapsLeftPct = cutValue.toInt();
    break;
  }
  case 518: {
    leadingEdgeFlapsRightPct = cutValue.toInt();
    break;
  }
  case 519: {
    leadingEdgeFlapsLeftAngle = cutValue.toInt();
    break;
  }
  case 520: {
    leadingEdgeFlapsRightAngle = cutValue.toInt();
    break;
  }

    // Gears
  case 526: {
    gearHandlePos = convBool(cutValue);
    break;
  }
  case 527: {
    gearHydraulicPressure = cutValue.toInt();
    break;
  }
  case 528: {
    tailWheelLock = convBool(cutValue);
    break;
  }
  case 529: {
    gearCenterPositionPct = cutValue.toInt();
    break;
  }
  case 530: {
    gearLeftPositionPct = cutValue.toInt();
    break;
  }
  case 531: {
    gearRightPositionPct = cutValue.toInt();
    break;
  }
  case 532: {
    gearTailPositionPct = cutValue.toInt();
    break;
  }
  case 533: {
    gearAuxPosition = cutValue.toInt();
    gearAuxPosition = cutValue.toInt();
    break;
  }
  case 536: {
    gearTotalPct = cutValue.toInt();
    break;
  }

    // AP
  case 576: {
    APAvailable = convBool(cutValue);
    break;
  }
  case 577: {
    APMasterOn = convBool(cutValue);
    break;
  }
  case 579: {
    APWingLevelerOn = convBool(cutValue);
    break;
  }
  case 580: {
    APNav1LockOn = convBool(cutValue);
    break;
  }
  case 581: {
    APHeadingLockOn = convBool(cutValue);
    break;
  }
  case 583: {
    APAltitudeLockOn = convBool(cutValue);
    break;
  }

  case 585: {
    APAttitudeLockOn = convBool(cutValue);
    break;
  }
  case 586: {
    APGlideslopeHoldOn = convBool(cutValue);
    break;
  }
  case 588: {
    APApproachHoldOn = convBool(cutValue);
    break;
  }
  case 589: {
    APBackcourseHoldOn = convBool(cutValue);
    break;
  }
  case 591: {
    APFlightDirectorOn = convBool(cutValue);
    break;
  }
  case 594: {
    APAirspeedHoldOn = convBool(cutValue);
    break;
  }
  case 596: {
    APMachHoldOn = convBool(cutValue);
    break;
  }
  case 598: {
    APYawDampenerOn = convBool(cutValue);
    break;
  }
  case 600: {
    APAutothrottleArm = convBool(cutValue);
    break;
  }
  case 601: {
    APTakeoffPowerOn = convBool(cutValue);
    break;
  }
  case 602: {
    APAutothrottleOn = convBool(cutValue);
    break;
  }
  case 604: {
    APVerticalHoldOn = convBool(cutValue);
    break;
  }
  case 605: {
    APRPMHoldOn = convBool(cutValue);
    break;
  }

    // Rudder trim
  case 498: {
    elevatorTrimPos = cutValue.toInt();
    break;
  }
  case 500: {
    elevatorTrimPct = cutValue.toInt();
    break;
  }
  case 562: {
    aileronTrimDegr = cutValue.toInt();
    break;
  }
  case 563: {
    aileronTrimPct = cutValue.toInt();
    break;
  }
  case 566: {
    rudderTrimDegr = cutValue.toInt();
    break;
  }
  case 567: {
    rudderTrimPct = cutValue.toInt();
    break;
  }

  case 330: {
    trueVerticalSpeed = cutValue.toInt();
    break;
  }

  case 326: {
    indicatedAirspeed = cutValue.toInt();
    break;
  }
  case 335: {
    indicatedAltitude = cutValue.toInt();
    break;
  }
  case 336: {
    indicatedAltitude2 = cutValue.toInt();
    break;
  }

  case 337: {
    kohlmanAltimeter = cutValue.toInt();
    break;
  }
  case 344: {
    indicatedHeading = cutValue.toInt();
    break;
  }
  case 345: {
    varometerRate = cutValue.toInt();
    break;
  }
  case 430: {
    indicatedGPSGroundspeed = cutValue.toInt();
    break;
  }
  case 582: {
    apHeadingLock = cutValue.toInt();
    break;
  }
  case 584: {
    apAltLock = cutValue.toInt();
    break;
  }
  case 590: {
    apVerticalSpeed = cutValue.toInt();
    break;
  }
  case 632: {
    barPressure = cutValue.toInt();
    break;
  }
  case 900: {
    activeCom1 = cutValue.toInt();
    break;
  }
  case 901: {
    standByCom1 = cutValue.toInt();
    break;
  }
  case 902: {
    activeCom2 = cutValue.toInt();
    break;
  }
  case 903: {
    standByCom2 = cutValue.toInt();
    break;
  }
  case 910: {
    activeNav1 = cutValue.toInt();
    break;
  }
  case 911: {
    standbyNav1 = cutValue.toInt();
    break;
  }
  case 912: {
    activeNav2 = cutValue.toInt();
    break;
  }
  case 913: {
    standbyNav2 = cutValue.toInt();
    break;
  }
  case 914: {
    navRadialError1 = cutValue.toInt();
    break;
  }
  case 915: {
    navVorLationalt1 = cutValue.toInt();
    break;
  }
    // DME
  case 950: {
    navDme1 = cutValue;
    break;
  }
  case 951: {
    navDme2 = cutValue;
    break;
  }
  case 952: {
    navDmeSpeed1 = cutValue;
    break;
  }
  case 953: {
    navDmeSpeed2 = cutValue;
    break;
  }

    // ADF
  case 954: {
    adfActiveFreq1 = cutValue.toInt();
    break;
  }
  case 955: {
    adfStandbyFreq1 = cutValue.toInt();
    break;
  }
  case 956: {
    adfRadial1 = cutValue;
    break;
  }
  case 957: {
    adfSignal1 = cutValue;
    break;
  }
  case 958: {
    adfActiveFreq2 = cutValue.toInt();
    break;
  }
  case 959: {
    adfStandbyFreq2 = cutValue.toInt();
    break;
  }
  case 960: {
    adfRadial2 = cutValue;
    break;
  }
  case 961: {
    adfSignal2 = cutValue;
    break;
  }

    // Transponder
  case 962: {
    transponderCode1 = cutValue;
    break;
  }
  case 963: {
    transponderCode2 = cutValue;
    break;
  }
  case 608: {
    transponderIdent1 = cutValue.toInt() != 0;
    break;
  }
  case 609: {
    transponderState1 = cutValue.toInt();
    break;
  }
  case 610: {
    transponderIdent2 = cutValue.toInt() != 0;
    break;
  }
  case 611: {
    transponderState2 = cutValue.toInt();
    break;
  }

    // PLANE DATA
  case 999: {
    planeName = cutValue;
    break;
  }

  case 606: {
    navObs1 = cutValue.toInt();
    break;
  }
  case 607: {
    navObs2 = cutValue.toInt();
    break;
  }
  case 234: {
    fuelTankCenterLevel = cutValue.toInt();
    break;
  }
  case 235: {
    fuelTankCenter2Level = cutValue.toInt();
    break;
  }

  case 236: {
    fuelTankCenter3Level = cutValue.toInt();
    break;
  }

  case 237: {
    fuelTankLeftMainLevel = cutValue.toInt();
    break;
  }

  case 238: {
    fuelTankLeftAuxLevel = cutValue.toInt();
    break;
  }

  case 239: {
    fuelTankLeftTipLevel = cutValue.toInt();
    break;
  }

  case 240: {
    fuelTankRightMainLevel = cutValue.toInt();
    break;
  }

  case 241: {
    fuelTankRightAuxLevel = cutValue.toInt();
    break;
  }

  case 242: {
    fuelTankRightTipLevel = cutValue.toInt();
    break;
  }

  case 243: {
    fuelTankExternal1Level = cutValue.toInt();
    break;
  }

  case 244: {
    fuelTankExternal2Level = cutValue.toInt();
    break;
  }

  case 245: {
    fuelTankCenterCapacity = cutValue.toInt();
    break;
  }

  case 246: {
    fuelTankCenter2Capacity = cutValue.toInt();
    break;
  }

  case 247: {
    fuelTankCenter3Capacity = cutValue.toInt();
    break;
  }

  case 248: {
    fuelTankLeftMainCapacity = cutValue.toInt();
    break;
  }

  case 249: {
    fuelTankLeftAuxCapacity = cutValue.toInt();
    break;
  }

  case 250: {
    fuelTankLeftTipCapacity = cutValue.toInt();
    break;
  }

  case 251: {
    fuelTankRightMainCapacity = cutValue.toInt();
    break;
  }

  case 252: {
    fuelTankRightAuxCapacity = cutValue.toInt();
    break;
  }

  case 253: {
    fuelTankRightTipCapacity = cutValue.toInt();
    break;
  }

  case 254: {
    fuelTankExternal1Capacity = cutValue.toInt();
    break;
  }

  case 255: {
    fuelTankExternal2Capacity = cutValue.toInt();
    break;
  }

  case 256: {
    fuelTankLeftCapacity = cutValue.toFloat();
    break;
  }
  case 257: {
    fuelTankRightCapacity = cutValue.toFloat();
    break;
  }
  case 258: {
    fuelTankCenterQuantity = cutValue.toInt();
    break;
  }
  case 259: {
    fuelTankCenter2Quantity = cutValue.toInt();
    break;
  }
  case 260: {
    fuelTankCenter3Quantity = cutValue.toInt();
    break;
  }
  case 261: {
    fuelTankLeftMainQuantity = cutValue.toInt();
    break;
  }

  case 262: {
    fuelTankLeftAuxQuantity = cutValue.toInt();
    break;
  }

  case 263: {
    fuelTankLeftTipQuantity = cutValue.toInt();
    break;
  }

  case 264: {
    fuelTankRightMainQuantity = cutValue.toInt();
    break;
  }

  case 265: {
    fuelTankRightAuxCapacity = cutValue.toInt();
    break;
  }

  case 266: {
    fuelTankRightTipQuantity = cutValue.toInt();
    break;
  }

  case 267: {
    fuelTankExternal1Quantity = cutValue.toInt();
    break;
  }
  case 268: {
    fuelTankExternal2Quantity = cutValue.toInt();
    break;
  }

  case 269: {
    fuelTankLeftQuantity = cutValue.toFloat();
    break;
  }
  case 270: {
    fuelTankRightQuantity = cutValue.toFloat();
    break;
  }
  case 271: {
    fuelTankTotalQuantity = cutValue.toInt();
    break;
  }
  case 505: {
    parkingBrakeIndicator = convBool(cutValue);
    break;
  }
  case 1000: {
    masterCautionOn = convBool(cutValue);
    break;
  }
  case 1001: {
    masterWarningOn = convBool(cutValue);
    break;
  }
  // DO NOT REMOVE THIS COMMENT ITS USED BY THE CONNECTOR TO GENERATE CUSTOM
  // EVENTS
  // START CASE TEMPLATE
  // END CASE TEMPLATE
  default:
    break;
  }
}

void BitsAndDroidsFlightConnector::propsInputHandling(int propPin1,
                                                      int propPin2) {
  bool changed = false;
  propValue1 = smoothPot(propPin1);
  propValue2 = smoothPot(propPin2);
  if (propValue1 != oldPropValue1 || propValue2 != oldPropValue2) {

    if (abs(propValue1 - oldPropValue1) > 2) {
      props[0] = propValue1;
      oldPropValue1 = propValue1;
      changed = true;
    }
    if (abs(propValue2 - oldPropValue2) > 2) {
      props[1] = propValue2;
      oldPropValue2 = propValue2;
      changed = true;
    }
    if (changed) {
      sendCombinedPropValues();
    }
  }
}

void BitsAndDroidsFlightConnector::mixtureInputHandling(int mixturePin1,
                                                        int mixturePin2) {
  bool changed = false;
  mixtureValue1 = smoothPot(mixturePin1);
  mixtureValue2 = smoothPot(mixturePin2);
  if (mixtureValue1 != oldMixtureValue1 || mixtureValue2 != oldMixtureValue2) {

    if (abs(mixtureValue1 - oldMixtureValue1) > 2) {
      mixturePercentage[0] = mixtureValue1;
      oldMixtureValue1 = mixtureValue1;
      changed = true;
    }
    if (abs(mixtureValue2 - oldMixtureValue2) > 2) {
      mixturePercentage[1] = mixtureValue2;
      oldMixtureValue2 = mixtureValue2;
      changed = true;
    }
    if (changed) {
      sendCombinedMixtureValues();
    }
  }
}

void BitsAndDroidsFlightConnector::simpleInputHandling(int throttlePin) {
  value = smoothPot(throttlePin);

  if (value != oldValue && abs(oldValue - value) > 1) {
    oldValue = value;

    engines[0] = value;
    engines[1] = value;
    engines[2] = value;
    engines[3] = value;

    sendCombinedThrottleValues();
  }
}

void BitsAndDroidsFlightConnector::setPotFlaps(byte flapsPin) {
  flaps = smoothPot(flapsPin);
  if (flaps != oldFlaps && abs(oldFlaps - flaps) > 2) {
    oldFlaps = flaps;
    sendFlaps();
  }
}

void BitsAndDroidsFlightConnector::advancedInputHandling(int eng1Pin,
                                                         int eng2Pin,
                                                         int eng3Pin,
                                                         int eng4Pin) {
  valueEng1 = smoothPot(eng1Pin);
  valueEng2 = smoothPot(eng2Pin);
  valueEng3 = smoothPot(eng3Pin);
  valueEng4 = smoothPot(eng4Pin);
  bool changed = false;

  if (valueEng1 != oldValueEng1) {
    oldValueEng1 = valueEng1;
    engines[0] = valueEng1;
    changed = true;
  }
  if (valueEng2 != oldValueEng2) {
    oldValueEng2 = valueEng2;
    engines[1] = valueEng2;
    changed = true;
  }
  if (valueEng3 != oldValueEng3) {
    oldValueEng3 = valueEng3;
    engines[2] = valueEng3;
    changed = true;
  }
  if (valueEng4 != oldValueEng4) {
    oldValueEng4 = valueEng4;
    engines[3] = valueEng4;
    changed = true;
  }

  if (changed) {
    sendCombinedThrottleValues();
  }
}

void BitsAndDroidsFlightConnector::superAdvancedInputHandling(
    byte eng1Percentage, byte eng2Percentage, byte eng3Percentage,
    byte eng4Percentage) {
  engines[0] = eng1Percentage;
  engines[1] = eng2Percentage;
  engines[2] = eng3Percentage;
  engines[3] = eng4Percentage;
  sendCombinedThrottleValues();
}

// Set jitter algorithm EMA_a
void BitsAndDroidsFlightConnector::setEMA_a(float a) { EMA_a = a; }

void BitsAndDroidsFlightConnector::send(int command) {
  Serial.println(command);
}

String BitsAndDroidsFlightConnector::convertToFreq(const String &unprocFreq) {
  String stringA = unprocFreq.substring(0, 3);
  String stringB = unprocFreq.substring(3);
  return stringA + "." + stringB;
}

String
BitsAndDroidsFlightConnector::convertToNavFreq(const String &unprocFreq) {
  String stringA = unprocFreq.substring(0, 3);
  String stringB = unprocFreq.substring(3, 5);
  return stringA + "." + stringB;
}
// RECEIVING VALUES
// GPS

//----------------------
// TRANSMIT FUNCTIONS
// AP

#pragma clang diagnostic pop
