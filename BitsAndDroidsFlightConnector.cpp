#include "Arduino.h"
#include "BitsAndDroidsFlightConnector.h"



BitsAndDroidsFlightConnector::BitsAndDroidsFlightConnector(
    bool isLeonardoMicro) {
  if (isLeonardoMicro) {
    Serial.begin(115200);
    Serial.setTimeout(50);
  }
}
void BitsAndDroidsFlightConnector::sendCombinedThrottleValues() {
  packagedData = sprintf(valuesBuffer, "%s %i %i %i %i %i", "199", engines[0],
                         engines[1], engines[2], engines[3], mixturePercentage);
  Serial.println(valuesBuffer);
}
void BitsAndDroidsFlightConnector::sendCombinedPropValues() {
  packagedData = sprintf(valuesBuffer, "%s %i %i", "198", props[0], props[1]);
  Serial.println(valuesBuffer);
}

byte BitsAndDroidsFlightConnector::getPercentage(int value, float maxVal) {
  byte percentage = ((value / 100.0) / (maxVal / 100.0)) * 100;
  if (percentage == 99) {
    percentage = 100;
  }
  return percentage;
}

bool convBool(String input) {
  if (input == "0") {
    return false;
  } else {
    return true;
  }
}

void BitsAndDroidsFlightConnector::dataHandling() {
  if (Serial.available() > 0) {
    String value = Serial.readStringUntil('\n');
    String prefix = value.substring(0, 3);
    String receivedValue = value.substring(3);
    int prefixVal = prefix.toInt();
    lastPrefix = prefixVal;

    switch (prefixVal) {
      // Ap

      // lights
      case 33: {
        lightTaxiOn = convBool(receivedValue);
        break;
      }
      case 34: {
        lightStrobeOn = convBool(receivedValue);
        break;
      }

      case 35: {
        lightPanelOn = convBool(receivedValue);
        break;
      }
      case 36: {
        lightRecognitionOn = convBool(receivedValue);
        break;
      }
      case 37: {
        lightWingOn = convBool(receivedValue);
        break;
      }
      case 38: {
        lightLogoOn = convBool(receivedValue);
        break;
      }
      case 39: {
        lightCabinOn = convBool(receivedValue);
        break;
      }
      case 40: {
        lightHeadOn = convBool(receivedValue);
        break;
      }
      case 41: {
        lightBrakeOn = convBool(receivedValue);
        break;
      }
      case 42: {
        lightNavOn = convBool(receivedValue);
        break;
      }
      case 43: {
        lightBeaconOn = convBool(receivedValue);
        break;
      }
      case 44: {
        lightLandingOn = convBool(receivedValue);
        break;
      }
      case 275: {
        fuelTotalPercentage = receivedValue;
        break;
      }

        // warnings
      case 333: {
        stallWarning = convBool(receivedValue);
        break;
      }
      case 334: {
        overspeedWarning = convBool(receivedValue);
        break;
      }

      // Flaps
      case 510: {
        flapsHandlePct = receivedValue;
        break;
      }
      case 511: {
        flapsHandleIndex = receivedValue;
        break;
      }
      case 512: {
        flapsNumHandlePos = receivedValue;
        break;
      }
      case 513: {
        trailingEdgeFlapsLeftPercent = receivedValue;
        break;
      }
      case 514: {
        trailingEdgeFlapsRightPercent = receivedValue;
        break;
      }
      case 515: {
        trailingEdgeFlapsLeftAngle = receivedValue;
        break;
      }
      case 516: {
        trailingEdgeFlapsRightAngle = receivedValue;
        break;
      }
      case 517: {
        leadingEdgeFlapsLeftPct = receivedValue;
        break;
      }
      case 518: {
        leadingEdgeFlapsRightPct = receivedValue;
        break;
      }
      case 519: {
        leadingEdgeFlapsLeftAngle = receivedValue;
        break;
      }
      case 520: {
        leadingEdgeFlapsRightAngle = receivedValue;
        break;
      }

      // Gears
      case 526: {
        gearHandlePos = convBool(receivedValue);
        break;
      }
      case 527: {
        gearHydraulicPressure = receivedValue;
        break;
      }
      case 528: {
        tailWheelLock = convBool(receivedValue);
        break;
      }
      case 529: {
        gearCenterPositionPct = receivedValue;
        break;
      }
      case 530: {
        gearLeftPositionPct = receivedValue;
        break;
      }
      case 531: {
        gearRightPositionPct = receivedValue;
        break;
      }
      case 532: {
        gearTailPositionPct = receivedValue;
        break;
      }
      case 533: {
        gearAuxPosition = receivedValue;
        break;
      }
      case 536: {
        gearTotalPct = receivedValue;
        break;
      }

      // AP
      case 576: {
        APAvailable = convBool(receivedValue);
        break;
      }
      case 577: {
        APMasterOn = convBool(receivedValue);
        break;
      }
      case 579: {
        APWingLevelerOn = convBool(receivedValue);
        break;
      }
      case 580: {
        APNav1LockOn = convBool(receivedValue);
        break;
      }
      case 581: {
        APHeadingLockOn = convBool(receivedValue);
        break;
      }
      case 583: {
        APAltitudeLockOn = convBool(receivedValue);
        break;
      }
      case 585: {
        APAttitudeLockOn = convBool(receivedValue);
        break;
      }
      case 586: {
        APGlideslopeHoldOn = convBool(receivedValue);
        break;
      }
      case 588: {
        APApproachHoldOn = convBool(receivedValue);
        break;
      }
      case 589: {
        APBackcourseHoldOn = convBool(receivedValue);
        break;
      }
      case 591: {
        APFlightDirectorOn = convBool(receivedValue);
        break;
      }
      case 594: {
        APAirspeedHoldOn = convBool(receivedValue);
        break;
      }
      case 596: {
        APMachHoldOn = convBool(receivedValue);
        break;
      }
      case 598: {
        APYawDampenerOn = convBool(receivedValue);
        break;
      }
      case 600: {
        APAutothrottleArm = convBool(receivedValue);
        break;
      }
      case 601: {
        APTakeoffPowerOn = convBool(receivedValue);
        break;
      }
      case 602: {
        APAutothrottleOn = convBool(receivedValue);
        break;
      }
      case 604: {
        APVerticalHoldOn = convBool(receivedValue);
        break;
      }
      case 605: {
        APRPMHoldOn = convBool(receivedValue);
        break;
      }

      // Rudder trim
      case 498: {
        elevatorTrimPos = receivedValue;
        break;
      }
      case 500: {
        elevatorTrimPct = receivedValue;
        break;
      }
      case 562: {
        aileronTrimDegr = receivedValue;
        break;
      }
      case 563: {
        aileronTrimPct = receivedValue;
        break;
      }
      case 566: {
        rudderTrimDegr = receivedValue;
        break;
      }
      case 567: {
        rudderTrimPct = receivedValue;
        break;
      }

      case 330: {
        trueVerticalSpeed = receivedValue;
        break;
      }

      case 326: {
        indicatedAirspeed = receivedValue;
        break;
      }
      case 335: {
        indicatedAltitude = receivedValue;
        break;
      }

      case 337: {
        kohlmanAltimeter = inhg(receivedValue);
        break;
      }
      case 344: {
        indicatedHeading = receivedValue;
        break;
      }
      case 430: {
        indicatedGPSGroundspeed = receivedValue;
        break;
      }
      case 582: {
        apHeadingLock = receivedValue;
        break;
      }
      case 584: {
        apAltLock = receivedValue;
        break;
      }
      case 590: {
        apVerticalSpeed = receivedValue;
        break;
      }
      case 632: {
        barPressure = receivedValue;
        break;
      }
      case 900: {
        activeCom1 = convertToFreq(receivedValue);
        break;
      }
      case 901: {
        standByCom1 = convertToFreq(receivedValue);
        break;
      }
      case 902: {
        activeCom2 = convertToFreq(receivedValue);
        break;
      }
      case 903: {
        standByCom2 = convertToFreq(receivedValue);
        break;
      }
      case 910: {
        activeNav1 = convertToNavFreq(receivedValue);
        break;
      }
      case 911: {
        standbyNav1 = convertToNavFreq(receivedValue);
        break;
      }
      case 912: {
        activeNav2 = convertToNavFreq(receivedValue);
        break;
      }
      case 913: {
        standbyNav2 = convertToNavFreq(receivedValue);
        break;
      }
      case 914: {
        navRadialError1 = receivedValue;
        break;
      }
      case 915: {
        navVorLationalt1 = receivedValue;
        break;
      }
        // DME
      case 950: {
        navDme1 = receivedValue;
        break;
      }
      case 951: {
        navDme2 = receivedValue;
        break;
      }
      case 952: {
        navDmeSpeed1 = receivedValue;
        break;
      }
      case 953: {
        navDmeSpeed2 = receivedValue;
        break;
      }

        // ADF
      case 954: {
        adfActiveFreq1 = receivedValue;
        break;
      }
      case 955: {
        adfStandbyFreq1 = receivedValue;
        break;
      }
      case 956: {
        adfRadial1 = receivedValue;
        break;
      }
      case 957: {
        adfSignal1 = receivedValue;
        break;
      }
      case 958: {
        adfActiveFreq2 = convertToNavFreq(receivedValue);
        break;
      }
      case 959: {
        adfStandbyFreq2 = convertToNavFreq(receivedValue);
        break;
      }
      case 960: {
        adfRadial2 = receivedValue;
        break;
      }
      case 961: {
        adfSignal2 = receivedValue;
        break;
      }

      // Transponder
      case 962: {
        transponderCode1 = receivedValue;
        break;
      }
      case 963: {
        transponderCode2 = receivedValue;
        break;
      }

      // PLANE DATA
      case 999: {
        planeName = receivedValue;
        break;
      }

      default:
        break;
    }
  }
}

void BitsAndDroidsFlightConnector::propsInputHandling(int propPin1,
                                                      int propPin2,
                                                      float maxVal) {
  propValue1 = (EMA_a * analogRead(propPin1)) + ((1 - EMA_a) * propValue1);
  propValue2 = (EMA_a * analogRead(propPin2)) + ((1 - EMA_a) * propValue2);
  if (propValue1 != oldPropValue1 || propValue2 != oldPropValue2) {
    oldPropValue1 = propValue1;
    oldPropValue2 = propValue2;

    prop1 = getPercentage(propValue1, maxVal);
    prop2 = getPercentage(propValue2, maxVal);

    props[0] = prop1;
    props[1] = prop2;

    sendCombinedPropValues();
  }
}
void BitsAndDroidsFlightConnector::simpleInputHandling(int throttlePin,
                                                       float maxVal) {
  value = (EMA_a * analogRead(throttlePin)) + ((1 - EMA_a) * value);

  if (value != oldValue) {
    oldValue = value;
    engine1 = getPercentage(value, maxVal);
    engine2 = getPercentage(value, maxVal);
    engine3 = getPercentage(value, maxVal);
    engine4 = getPercentage(value, maxVal);
    mixturePercentage = getPercentage(value, maxVal);

    engines[0] = engine1;
    engines[1] = engine2;
    engines[2] = engine3;
    engines[3] = engine4;

    sendCombinedThrottleValues();
  }
}
void BitsAndDroidsFlightConnector::advancedInputHandling(
    int eng1Pin, int eng2Pin, int eng3Pin, int eng4Pin, int mixturePin,
    float maxVal) {
  valueEng1 = (EMA_a * analogRead(eng1Pin)) + ((1 - EMA_a) * valueEng1);
  valueEng2 = (EMA_a * analogRead(eng2Pin)) + ((1 - EMA_a) * valueEng2);
  valueEng3 = (EMA_a * analogRead(eng3Pin)) + ((1 - EMA_a) * valueEng3);
  valueEng4 = (EMA_a * analogRead(eng4Pin)) + ((1 - EMA_a) * valueEng4);

  mixtureValue =
      (EMA_a * analogRead(mixturePin)) + ((1 - EMA_a) * mixtureValue);

  bool changed = false;

  if (valueEng1 != oldValueEng1) {
    oldValueEng1 = valueEng1;
    engine1 = getPercentage(valueEng1, maxVal);
    engines[0] = engine1;
    changed = true;
  }
  if (valueEng2 != oldValueEng2) {
    oldValueEng2 = valueEng2;
    engine2 = getPercentage(valueEng2, maxVal);
    engines[1] = engine2;
    changed = true;
  }
  if (valueEng3 != oldValueEng3) {
    oldValueEng3 = valueEng3;
    engine3 = getPercentage(valueEng3, maxVal);
    engines[2] = engine3;
    changed = true;
  }
  if (valueEng4 != oldValueEng4) {
    oldValueEng4 = valueEng4;
    engine4 = getPercentage(valueEng4, maxVal);
    engines[3] = engine4;
    changed = true;
  }
  if (mixtureValue != oldMixtureValue) {
    oldMixtureValue = mixtureValue;
    mixturePercentage = getPercentage(mixtureValue, maxVal);
    changed = true;
  }
  if (changed) {
    sendCombinedThrottleValues();
  }
}
void BitsAndDroidsFlightConnector::superAdvancedInputHandling(
    byte eng1Percentage, byte eng2Percentage, byte eng3Percentage,
    byte eng4Percentage, byte receivedMixturePercentage) {
  engines[0] = eng1Percentage;
  engines[1] = eng2Percentage;
  engines[2] = eng3Percentage;
  engines[3] = eng4Percentage;
  mixturePercentage = receivedMixturePercentage;
  sendCombinedThrottleValues();
}

String BitsAndDroidsFlightConnector::convertToFreq(String unprocFreq) {
  String stringA = unprocFreq.substring(0, 3);
  String stringB = unprocFreq.substring(3);
  return stringA + "." + stringB;
}
String BitsAndDroidsFlightConnector::convertToNavFreq(String unprocFreq) {
  String stringA = unprocFreq.substring(0, 3);
  String stringB = unprocFreq.substring(3, 5);
  return stringA + "." + stringB;
}
String BitsAndDroidsFlightConnector::inhg(String unprocInhg) {
  int valOfAltm = unprocInhg.toInt();

  String correction = unprocInhg.substring(3);

  int valOfCorrection = correction.toInt();

  if (valOfCorrection > 5) {
    // if its bigger add 10
    valOfAltm += 10;
  }
  // remove the last digit that
  valOfAltm = (valOfAltm - valOfCorrection) / 10;
  String valString = String(valOfAltm);
  String stringA = valString.substring(0, 2);
  String stringB = valString.substring(2);
  return stringA + "." + stringB;
}
int BitsAndDroidsFlightConnector::getLastPrefix() { return lastPrefix; }
// Set jitter algorithm EMA_a
void BitsAndDroidsFlightConnector::setEMA_a(float a) { EMA_a = a; }
// RECEIVING VALUES

// Ap
String BitsAndDroidsFlightConnector::getApVerticalSpeed() {
  return apVerticalSpeed;
}
String BitsAndDroidsFlightConnector::getApAltLock() { return apAltLock; }

bool BitsAndDroidsFlightConnector::getAPAvailable() { return APAvailable; }
bool BitsAndDroidsFlightConnector::getAPMasterOn() { return APMasterOn; }
bool BitsAndDroidsFlightConnector::getAPWingLevelerOn() {
  return APWingLevelerOn;
}
bool BitsAndDroidsFlightConnector::getAPNav1LockOn() { return APNav1LockOn; }
bool BitsAndDroidsFlightConnector::getAPHeadingLockOn() {
  return APHeadingLockOn;
}
bool BitsAndDroidsFlightConnector::getAPAltitudeLockOn() {
  return APAltitudeLockOn;
}
bool BitsAndDroidsFlightConnector::getAPAttitudeLockOn() {
  return APAttitudeLockOn;
}
bool BitsAndDroidsFlightConnector::getAPGlideslopeHoldOn() {
  return APGlideslopeHoldOn;
}
bool BitsAndDroidsFlightConnector::getAPApproachHoldOn() {
  return APApproachHoldOn;
}
bool BitsAndDroidsFlightConnector::getAPBackcourseHoldOn() {
  return APBackcourseHoldOn;
}
bool BitsAndDroidsFlightConnector::getAPFlightDirectorOn() {
  return APFlightDirectorOn;
}
bool BitsAndDroidsFlightConnector::getAPAirspeedHoldOn() {
  return APAirspeedHoldOn;
}
bool BitsAndDroidsFlightConnector::getAPMachHoldOn() { return APMachHoldOn; }
bool BitsAndDroidsFlightConnector::getAPYawDampenerOn() {
  return APYawDampenerOn;
}
bool BitsAndDroidsFlightConnector::getAPAutothrottleArm() {
  return APAutothrottleArm;
}
bool BitsAndDroidsFlightConnector::getAPTakeoffPowerOn() {
  return APTakeoffPowerOn;
}
bool BitsAndDroidsFlightConnector::getAPAutothrottleOn() {
  return APAutothrottleOn;
}
bool BitsAndDroidsFlightConnector::getAPVerticalHoldOn() {
  return APVerticalHoldOn;
}
bool BitsAndDroidsFlightConnector::getAPRPMHoldOn() { return APRPMHoldOn; }

// Avionics
String BitsAndDroidsFlightConnector::getApHeadingLock() {
  return apHeadingLock;
}
String BitsAndDroidsFlightConnector::getKohlmanAltimeter() {
  return kohlmanAltimeter;
}
String BitsAndDroidsFlightConnector::getBarPressure() { return barPressure; }
String BitsAndDroidsFlightConnector::getIndicatedAirspeed() {
  return indicatedAirspeed;
}
String BitsAndDroidsFlightConnector::getIndicatedAltitude() {
  return indicatedAltitude;
}
String BitsAndDroidsFlightConnector::getIndicatedHeading() {
  return indicatedHeading;
}
String BitsAndDroidsFlightConnector::getIndicatedGPSGroundspeed() {
  return indicatedGPSGroundspeed;
}
String BitsAndDroidsFlightConnector::getTrueVerticalSpeed() {
  return trueVerticalSpeed;
}
String BitsAndDroidsFlightConnector::getFuelTotalPercentage() {
  return fuelTotalPercentage;
}

// lights
bool BitsAndDroidsFlightConnector::getLightTaxiOn() { return lightTaxiOn; }
bool BitsAndDroidsFlightConnector::getLightStrobeOn() { return lightStrobeOn; }
bool BitsAndDroidsFlightConnector::getLightPanelOn() { return lightPanelOn; }
bool BitsAndDroidsFlightConnector::getLightRecognitionOn() {
  return lightRecognitionOn;
}
bool BitsAndDroidsFlightConnector::getLightWingOn() { return lightWingOn; }
bool BitsAndDroidsFlightConnector::getLightLogoOn() { return lightLogoOn; }
bool BitsAndDroidsFlightConnector::getLightCabinOn() { return lightCabinOn; }
bool BitsAndDroidsFlightConnector::getLightHeadOn() { return lightHeadOn; }
bool BitsAndDroidsFlightConnector::getLightBrakeOn() { return lightBrakeOn; }
bool BitsAndDroidsFlightConnector::getLightNavOn() { return lightNavOn; }
bool BitsAndDroidsFlightConnector::getLightBeaconOn() { return lightBeaconOn; }
bool BitsAndDroidsFlightConnector::getLightLandingOn() {
  return lightLandingOn;
}

// Coms
String BitsAndDroidsFlightConnector::getActiveCom1() { return activeCom1; }
String BitsAndDroidsFlightConnector::getActiveCom2() { return activeCom2; }
String BitsAndDroidsFlightConnector::getStandbyCom1() { return standByCom1; }
String BitsAndDroidsFlightConnector::getStandbyCom2() { return standByCom2; }
String BitsAndDroidsFlightConnector::getActiveNav1() { return activeNav1; }
String BitsAndDroidsFlightConnector::getActiveNav2() { return activeNav2; }
String BitsAndDroidsFlightConnector::getStandbyNav1() { return standbyNav1; }
String BitsAndDroidsFlightConnector::getStandbyNav2() { return standbyNav2; }
String BitsAndDroidsFlightConnector::getNavRadialError1() {
  return navRadialError1;
}
String BitsAndDroidsFlightConnector::getNavVorLationalt1() {
  return navVorLationalt1;
}

// DME
String BitsAndDroidsFlightConnector::getNavDme1() { return navDme1; }
String BitsAndDroidsFlightConnector::getNavDme2() { return navDme2; }
String BitsAndDroidsFlightConnector::getNavDmeSpeed1() { return navDmeSpeed1; }
String BitsAndDroidsFlightConnector::getNavDmeSpeed2() { return navDmeSpeed2; }

// ADF
String BitsAndDroidsFlightConnector::getAdfActiveFreq1() {
  return adfActiveFreq1;
}
String BitsAndDroidsFlightConnector::getAdfStandbyFreq1() {
  return adfStandbyFreq1;
}
String BitsAndDroidsFlightConnector::getAdfRadial1() { return adfRadial1; }
String BitsAndDroidsFlightConnector::getAdfSignal1() { return adfSignal1; }
String BitsAndDroidsFlightConnector::getAdfActiveFreq2() {
  return adfActiveFreq2;
}
String BitsAndDroidsFlightConnector::getAdfStandbyFreq2() {
  return adfStandbyFreq2;
}
String BitsAndDroidsFlightConnector::getAdfRadial2() { return adfRadial2; }
String BitsAndDroidsFlightConnector::getAdfSignal2() { return adfSignal2; }

// Transponder
String BitsAndDroidsFlightConnector::getTransponderCode1() {
  return transponderCode1;
}
String BitsAndDroidsFlightConnector::getTransponderCode2() {
  return transponderCode2;
}

// Warnings
bool BitsAndDroidsFlightConnector::getStallWarningOn() { return stallWarning; }
bool BitsAndDroidsFlightConnector::getOverspeedWarningOn() {
  return overspeedWarning;
}

// Flaps
String BitsAndDroidsFlightConnector::getFlapsHandlePct() {
  return flapsHandlePct;
}
String BitsAndDroidsFlightConnector::getFlapsHandleIndex() {
  return flapsHandleIndex;
}
String BitsAndDroidsFlightConnector::getFlapsNumHandlePos() {
  return flapsNumHandlePos;
}
String BitsAndDroidsFlightConnector::getTrailingEdgeFlapsLeftPercent() {
  return trailingEdgeFlapsLeftPercent;
}
String BitsAndDroidsFlightConnector::getTrailingEdgeFlapsRightPercent() {
  return trailingEdgeFlapsRightPercent;
}
String BitsAndDroidsFlightConnector::getTrailingEdgeFlapsLeftAngle() {
  return trailingEdgeFlapsLeftAngle;
}
String BitsAndDroidsFlightConnector::getTrailingEdgeFlapsRightAngle() {
  return trailingEdgeFlapsRightAngle;
}
String BitsAndDroidsFlightConnector::getLeadingEdgeFlapsLeftPct() {
  return leadingEdgeFlapsLeftPct;
}
String BitsAndDroidsFlightConnector::getLeadingEdgeFlapsRightPct() {
  return leadingEdgeFlapsRightPct;
}
String BitsAndDroidsFlightConnector::getLeadingEdgeFlapsLeftAngle() {
  return leadingEdgeFlapsLeftAngle;
}
String BitsAndDroidsFlightConnector::getLeadingEdgeFlapsRightAngle() {
  return leadingEdgeFlapsRightAngle;
}

// Gears
bool BitsAndDroidsFlightConnector::getGearHandlePos() { return gearHandlePos; }
String BitsAndDroidsFlightConnector::getGearHydraulicPressure() {
  return gearHydraulicPressure;
}
bool BitsAndDroidsFlightConnector::getTailWheelLock() { return tailWheelLock; }
String BitsAndDroidsFlightConnector::getGearCenterPositionPct() {
  return gearCenterPositionPct;
}
String BitsAndDroidsFlightConnector::getGearLeftPositionPct() {
  return gearLeftPositionPct;
}
String BitsAndDroidsFlightConnector::getGearRightPositionPct() {
  return gearRightPositionPct;
}
String BitsAndDroidsFlightConnector::getGearTailPositionPct() {
  return gearTailPositionPct;
}
String BitsAndDroidsFlightConnector::getGearAuxPosition() {
  return gearAuxPosition;
}
String BitsAndDroidsFlightConnector::getGearTotalPct() { return gearTotalPct; }

// Rudder/Trim
String BitsAndDroidsFlightConnector::getAileronTrimPct() {
  return aileronTrimPct;
}
String BitsAndDroidsFlightConnector::getAileronTrimDegr() {
  return aileronTrimDegr;
}
String BitsAndDroidsFlightConnector::getRudderTrimDegr() {
  return rudderTrimDegr;
}
String BitsAndDroidsFlightConnector::getRudderTrimPct() {
  return rudderTrimPct;
}
String BitsAndDroidsFlightConnector::getElevatorTrimPos() {
  return elevatorTrimPos;
}
String BitsAndDroidsFlightConnector::getElevatorTrimPct() {
  return elevatorTrimPct;
}

// Plane data
String BitsAndDroidsFlightConnector::getPlaneName() { return planeName; }

//----------------------
// TRANSMIT FUNCTIONS
// AP
int BitsAndDroidsFlightConnector::sendApMasterOn() { return valSendApMasterOn; }
int BitsAndDroidsFlightConnector::sendApPanelHeadingLock() {
  return valSendApPanelHeadingLock;
}
int BitsAndDroidsFlightConnector::sendAPPanelAltitudeHold() {
  return valSendAPPanelAltitudeHold;
}
int BitsAndDroidsFlightConnector::sendAPAttitudeHoldOn() {
  return valSendAPAttitudeHoldOn;
}
int BitsAndDroidsFlightConnector::sendAPLocHoldOn() {
  return valSendAPLocHoldOn;
}
int BitsAndDroidsFlightConnector::sendAPAprHoldOn() {
  return valSendAPAprHoldOn;
}
int BitsAndDroidsFlightConnector::sendAPHeadingHoldOn() {
  return valSendAPHeadingHoldOn;
}
int BitsAndDroidsFlightConnector::sendAltitudeHoldOn() {
  return valSendAPAltitudeHold;
}
int BitsAndDroidsFlightConnector::sendApWingLevelerOn() {
  return valSendApWingLevelerOn;
}
int BitsAndDroidsFlightConnector::sendBCHoldOn() { return valSendBCHoldOn; }
int BitsAndDroidsFlightConnector::sendAPNav1HoldOn() {
  return valSendAPNav1HoldOn;
}
int BitsAndDroidsFlightConnector::sendAPAttitudeHoldOff() {
  return valSendAPAttitudeHoldOff;
}
int BitsAndDroidsFlightConnector::sendAPLocHoldOff() {
  return valSendAPLocHoldOff;
}
int BitsAndDroidsFlightConnector::sendAprHoldOff() { return valSendAprHoldOff; }
int BitsAndDroidsFlightConnector::sendAPHeadingHoldOff() {
  return valSendAPHeadingHoldOff;
}
int BitsAndDroidsFlightConnector::sendAPAltitudeHoldOff() {
  return valSendAPAltitudeHoldOff;
}
int BitsAndDroidsFlightConnector::sendWingLevelerOff() {
  return valSendWingLevelerOff;
}
int BitsAndDroidsFlightConnector::sendAPBCHoldOff() {
  return valSendAPBCHoldOff;
}
int BitsAndDroidsFlightConnector::sendAPNav1HoldOff() {
  return valSendAPNav1HoldOff;
}
int BitsAndDroidsFlightConnector::sendAPAirspeedHold() {
  return valSendAPAirspeedHold;
}
int BitsAndDroidsFlightConnector::sendAPPanelSpeedHold() {
  return valSendAPPanelSpeedHold;
}
int BitsAndDroidsFlightConnector::sendAPAltitudeInc() {
  return valSendAPAltitudeInc;
}
int BitsAndDroidsFlightConnector::sendAPAltitudeDec() {
  return valSendAPAltitudeDec;
}
int BitsAndDroidsFlightConnector::sendAPVSInc() { return valSendAPVSInc; }
int BitsAndDroidsFlightConnector::sendAPVSDec() { return valSendAPVSDec; }
int BitsAndDroidsFlightConnector::sendAPSpeedInc() { return valSendAPSpeedInc; }
int BitsAndDroidsFlightConnector::sendAPSpeedDec() { return valSendAPSpeedDec; }
int BitsAndDroidsFlightConnector::sendAPPanelMachHold() {
  return valSendAPPanelMachHold;
}
int BitsAndDroidsFlightConnector::sendAPMachInc() { return valSendAPMachInc; }
int BitsAndDroidsFlightConnector::sendAPMachDec() { return valSendAPMachDec; }
int BitsAndDroidsFlightConnector::sendAPMachHold() { return valSendAPMachHold; }
int BitsAndDroidsFlightConnector::sendAPAltitudeSetMetric() {
  return valSendAPAltitudeSetMetric;
}
int BitsAndDroidsFlightConnector::sendAPVSSetEnglish() {
  return valSendAPVSSetEnglish;
}
int BitsAndDroidsFlightConnector::sendAPSpeedSet() {
  return valSendAPPanelSpeedSet;
}
int BitsAndDroidsFlightConnector::sendAPMachVarSet() {
  return valSendAPMachVarSet;
}
int BitsAndDroidsFlightConnector::sendAPAirspeedOn() {
  return valSendAPAirspeedOn;
}
int BitsAndDroidsFlightConnector::sendAPAirspeedOff() {
  return valSendAPAirspeedOff;
}
int BitsAndDroidsFlightConnector::sendAPAirspeedSet() {
  return valSendAPAirspeedSet;
}
int BitsAndDroidsFlightConnector::sendAPMachOn() { return valSendAPMachOn; }
int BitsAndDroidsFlightConnector::sendAPMachOff() { return valSendAPMachOff; }
int BitsAndDroidsFlightConnector::sendAPMachSet() { return valSendAPMachSet; }
int BitsAndDroidsFlightConnector::sendAPPanelAltitudeOn() {
  return valSendAPPanelAltitudeOn;
}
int BitsAndDroidsFlightConnector::sendAPPanelAltitudeOff() {
  return valSendAPPanelAltitudeOff;
}
int BitsAndDroidsFlightConnector::sendAPPanelAltitudeSet() {
  return valSendAPPanelAltitudeSet;
}
int BitsAndDroidsFlightConnector::sendAPPanelHeadingOn() {
  return valSendAPPanelHeadingOn;
}
int BitsAndDroidsFlightConnector::sendAPPanelHeadingOff() {
  return valSendAPPanelHeadingOff;
}
int BitsAndDroidsFlightConnector::sendAPPanelHeadingSet() {
  return valSendAPPanelHeadingSet;
}
int BitsAndDroidsFlightConnector::sendAPPanelMachOn() {
  return valSendAPPanelMachOn;
}
int BitsAndDroidsFlightConnector::sendAPPanelMachOff() {
  return valSendAPPanelMachOff;
}
int BitsAndDroidsFlightConnector::sendAPPanelMachSet() {
  return valSendAPPanelMachSet;
}
int BitsAndDroidsFlightConnector::sendAPPanelSpeedOn() {
  return valSendAPPanelSpeedOn;
}
int BitsAndDroidsFlightConnector::sendAPPanelSpeedOff() {
  return valSendAPPanelSpeedOff;
}
int BitsAndDroidsFlightConnector::sendAPPanelSpeedSet() {
  return valSendAPPanelSpeedSet;
}
int BitsAndDroidsFlightConnector::sendAPPanelAltVarSetEnglish() {
  return valSendAPPanelAltVarSetEnglish;
}
int BitsAndDroidsFlightConnector::sendAPVSVarSetMetric() {
  return valSendAPVSVarSetMetric;
}
int BitsAndDroidsFlightConnector::sendAPPanelSpeedHoldToggle() {
  return valSendAPPanelSpeedHoldToggle;
}
int BitsAndDroidsFlightConnector::sendAPPanelMachHoldToggle() {
  return valSendAPPanelMachHoldToggle;
}
int BitsAndDroidsFlightConnector::sendAPNavSelectSet() {
  return valSendAPNavSelectSet;
}
int BitsAndDroidsFlightConnector::sendAPPitchRefIncUp() {
  return valSendAPPitchRefIncUp;
}
int BitsAndDroidsFlightConnector::sendAPPitchRefIncDown() {
  return valSendAPPitchRefIncDown;
}
int BitsAndDroidsFlightConnector::sendAPPitchRefSelect() {
  return valSendAPPitchRefSelect;
}
int BitsAndDroidsFlightConnector::sendAPAttitudeHold() {
  return valSendAPAttitudeHold;
}
int BitsAndDroidsFlightConnector::sendAPLocHold() { return valSendAPLocHold; }
int BitsAndDroidsFlightConnector::sendAPAprHold() { return valSendAPAprHold; }
int BitsAndDroidsFlightConnector::sendAPHeadingHold() {
  return valSendAPHeadingHold;
}
int BitsAndDroidsFlightConnector::sendAPAltitudeHold() {
  return valSendAPAltitudeHold;
}
int BitsAndDroidsFlightConnector::sendAPWingLeveler() {
  return valSendAPWingLeveler;
}
int BitsAndDroidsFlightConnector::sendAPBCHold() { return valSendAPBCHold; }
int BitsAndDroidsFlightConnector::sendAPNav1Hold() { return valSendAPNav1Hold; }
int BitsAndDroidsFlightConnector::sendHeadingBugInc() {
  return valSendHeadingBugInc;
}
int BitsAndDroidsFlightConnector::sendHeadingBugDec() {
  return valSendHeadingBugDec;
}
int BitsAndDroidsFlightConnector::sendAPFlightDirector() {
  return valSendAPFlightDirector;
}
int BitsAndDroidsFlightConnector::sendAPVSHold() { return valSendAPVSHold; }
int BitsAndDroidsFlightConnector::sendKohlsmanInc() {
  return valSendKohlsmanInc;
}
int BitsAndDroidsFlightConnector::sendKohlsmanDec() {
  return valSendKohlsmanDec;
}
// Coms
String BitsAndDroidsFlightConnector::sendStandbyCom1Set(char* value) {
  return valSendStandbyCom1Set + " " + (value);
}
String BitsAndDroidsFlightConnector::sendStandbyCom2Set(char* value) {
  return valSendStandbyCom2Set + " " + (value);
}

byte BitsAndDroidsFlightConnector::sendSwapCom1() { return valSendSwapCom1; }
byte BitsAndDroidsFlightConnector::sendSwapCom2() { return valSendSwapCom2; }

byte BitsAndDroidsFlightConnector::sendCom1FractInc() {
  return valSendCom1FractInc;
}
byte BitsAndDroidsFlightConnector::sendCom1FractIncCarry() {
  return valSendCom1FractIncCarry;
}
byte BitsAndDroidsFlightConnector::sendCom1FractDecr() {
  return valSendCom1FractDecr;
}
byte BitsAndDroidsFlightConnector::sendCom1FractDecrCarry() {
  return valSendCom1FractDecrCarry;
}

byte BitsAndDroidsFlightConnector::sendCom2FractInc() {
  return valSendCom2FractInc;
}
byte BitsAndDroidsFlightConnector::sendCom2FractIncCarry() {
  return valSendCom2FractIncCarry;
}
byte BitsAndDroidsFlightConnector::sendCom2FractDecr() {
  return valSendCom2FractDecr;
}
byte BitsAndDroidsFlightConnector::sendCom2FractDecrCarry() {
  return valSendCom2FractDecrCarry;
}

// Xpndr
String BitsAndDroidsFlightConnector::sendXpndrSet(char* Xpndr) {
  return valSendXpndrSet + " " + (Xpndr);
}

// Nav
byte BitsAndDroidsFlightConnector::sendMhzNavStandby1Plus() {
  return valSendMhzNavStandby1Plus;
}
byte BitsAndDroidsFlightConnector::sendMhzNavStandby1Min() {
  return valSendMhzNavStandby1Min;
}
byte BitsAndDroidsFlightConnector::sendKhzNavStandby1Plus() {
  return valSendKhzNavStandby1Plus;
}
byte BitsAndDroidsFlightConnector::sendKhzNavStandby1Min() {
  return valSendKhzNavStandby1Min;
}

byte BitsAndDroidsFlightConnector::sendMhzNavStandby2Plus() {
  return valSendMhzNavStandby2Plus;
}
byte BitsAndDroidsFlightConnector::sendMhzNavStandby2Min() {
  return valSendMhzNavStandby2Min;
}
byte BitsAndDroidsFlightConnector::sendKhzNavStandby2Plus() {
  return valSendKhzNavStandby2Plus;
}
byte BitsAndDroidsFlightConnector::sendKhzNavStandby2Min() {
  return valSendKhzNavStandby2Min;
}

byte BitsAndDroidsFlightConnector::sendIncWholeNav1() {
  return valSendIncWholeNav1;
}
byte BitsAndDroidsFlightConnector::sendDecWholeNav1() {
  return valSendDecWholeNav1;
}
byte BitsAndDroidsFlightConnector::sendIncWholeNav2() {
  return valSendIncWholeNav2;
}
byte BitsAndDroidsFlightConnector::sendDecWholeNav2() {
  return valSendDecWholeNav2;
}

byte BitsAndDroidsFlightConnector::sendIncFractNav1() {
  return valSendIncFractNav1;
}
byte BitsAndDroidsFlightConnector::sendDecFractNav1() {
  return valSendDecFractNav1;
}
byte BitsAndDroidsFlightConnector::sendIncFractNav2() {
  return valSendIncFractNav2;
}
byte BitsAndDroidsFlightConnector::sendDecFractNav2() {
  return valSendDecFractNav2;
}

byte BitsAndDroidsFlightConnector::sendSwapNav1() { return valSendSwapNav1; }
byte BitsAndDroidsFlightConnector::sendSwapNav2() { return valSendSwapNav2; }

// G1000
byte BitsAndDroidsFlightConnector::sendG1000ZoomMapIn() {
  return valSendG1000ZoomMapIn;
}
byte BitsAndDroidsFlightConnector::sendG1000ZoomMapOut() {
  return valSendG1000ZoomMapOut;
}

//DME

byte BitsAndDroidsFlightConnector::sendSelectedDme1IdentEnable(){return valSendSelectedDme1IdentEnable;}
byte BitsAndDroidsFlightConnector::sendSeletedDme1IdentDisable (){return valSendSeletedDme1IdentDisable;}
byte BitsAndDroidsFlightConnector::sendSelectedDme1IdentSet (){return valSendSelectedDme1IdentSet;}
byte BitsAndDroidsFlightConnector::sendSelectedDme1IdentToggle (){return valSendSelectedDme1IdentToggle;}
byte BitsAndDroidsFlightConnector::sendSelectedDme2IdentEnable (){return valSendSelectedDme2IdentEnable;}
byte BitsAndDroidsFlightConnector::sendSelectedDme2IdentDisable(){return valSendSelectedDme2IdentDisable;}
byte BitsAndDroidsFlightConnector::sendSelectedDme2IdentSet(){return valSendSelectedDme2IdentSet;}
byte BitsAndDroidsFlightConnector::sendSelectedDme2IdentToggle(){return valSendSelectedDme2IdentToggle;}
byte BitsAndDroidsFlightConnector::sendDmeToggle(){return valSendDmeToggle;}

//VOR

byte BitsAndDroidsFlightConnector::sendSelectedVor1IdentEnable(){return valSendSelectedVor1IdentEnable;}
byte BitsAndDroidsFlightConnector::sendSelectedVor1IdentDisable(){return valSendSelectedVor1IdentDisable;}
byte BitsAndDroidsFlightConnector::sendSelectedVor1IdentSet(){return valSendSelectedVor1IdentSet;}
byte BitsAndDroidsFlightConnector::sendVor1IdentToggle(){return valSendVor1IdentToggle;}
byte BitsAndDroidsFlightConnector::sendVor2IdentEnable(){return valSendVor2IdentEnable;}
byte BitsAndDroidsFlightConnector::sendVor2IdentDisable(){return valSendVor2IdentDisable;}
byte BitsAndDroidsFlightConnector::sendVor2IdentSet(){return valSendVor2IdentSet;}
byte BitsAndDroidsFlightConnector::sendVor2IdentToggle(){return valSendVor2IdentToggle;}
byte BitsAndDroidsFlightConnector::sendVorToggle(){return valSendVorToggle;}
byte BitsAndDroidsFlightConnector::sendVor1ObiDec(){return valSendVor1ObiDec;}
byte BitsAndDroidsFlightConnector::sendVor1ObiInc(){return valSendVor1ObiInc;}
byte BitsAndDroidsFlightConnector::sendVor2ObiDec(){return valSendVor2ObiDec;}
byte BitsAndDroidsFlightConnector::sendVor2ObiInc(){return valSendVor2ObiInc;}

//ADF

byte BitsAndDroidsFlightConnector::sendSelectedAdfIdentEnable(){return valSendSelectedAdfIdentEnable;}
byte BitsAndDroidsFlightConnector::sendSelectedAdfIdentDisable(){return valSendSelectedAdfIdentDisable;}
byte BitsAndDroidsFlightConnector::sendSelecetedAdfIdentSet(){return valSendSelecetedAdfIdentSet;}
byte BitsAndDroidsFlightConnector::sendSelectedAdfIdentToggle(){return valSendSelectedAdfIdentToggle;}
byte BitsAndDroidsFlightConnector::sendAdfCardInc(){return valSendAdfCardInc;}
byte BitsAndDroidsFlightConnector::sendAdfCardDec(){return valSendAdfCardDec;}
byte BitsAndDroidsFlightConnector::sendAdfCardSet(){return valSendAdfCardSet;}
byte BitsAndDroidsFlightConnector::sendAdf100Inc(){return valSendAdf100Inc;}
byte BitsAndDroidsFlightConnector::sendAdf10Inc(){return valSendAdf10Inc;}
byte BitsAndDroidsFlightConnector::sendAdf1Inc(){return valSendAdf1Inc;}
byte BitsAndDroidsFlightConnector::sendAdf100Dec(){return valSendAdf100Dec;}
byte BitsAndDroidsFlightConnector::sendAdf10Dec(){return valSendAdf10Dec;}
byte BitsAndDroidsFlightConnector::sendAdf1Dec(){return valSendAdf1Dec;}
byte BitsAndDroidsFlightConnector::sendAdfCompleteSet(){return valSendAdfCompleteSet;}
byte BitsAndDroidsFlightConnector::sendAdf1WholeInc(){return valSendAdf1WholeInc;}
byte BitsAndDroidsFlightConnector::sendAdf1WholeDec(){return valSendAdf1WholeDec;}
byte BitsAndDroidsFlightConnector::sendAdf2100Inc(){return valSendAdf2100Inc;}
byte BitsAndDroidsFlightConnector::sendAdf210Inc(){return valSendAdf210Inc;}
byte BitsAndDroidsFlightConnector::sendAdf21Inc(){return valSendAdf21Inc;}
byte BitsAndDroidsFlightConnector::sendAdf2RadioThenthsInc(){return valSendAdf2RadioThenthsInc;}
byte BitsAndDroidsFlightConnector::sendAdf2100Dec(){return valSendAdf2100Dec;}
byte BitsAndDroidsFlightConnector::sendAdf210Dec(){return valSendAdf210Dec;}
byte BitsAndDroidsFlightConnector::sendAdf21Dec(){return valSendAdf21Dec;}
byte BitsAndDroidsFlightConnector::sendAdf2RadioThenthsDec(){return valSendAdf2RadioThenthsDec;}
byte BitsAndDroidsFlightConnector::sendAdf2WholeInc(){return valSendAdf2WholeInc;}
byte BitsAndDroidsFlightConnector::sendAdf2WholeDec(){return valSendAdf2WholeDec;}
byte BitsAndDroidsFlightConnector::sendAdf2FractDecCarry(){return valSendAdf2FractDecCarry;}
byte BitsAndDroidsFlightConnector::sendAdf2FractIncCarry(){return valSendAdf2FractIncCarry;}
byte BitsAndDroidsFlightConnector::sendAdf2CompleteSet(){return valSendAdf2CompleteSet;}
byte BitsAndDroidsFlightConnector::sendAdf2IdentDisable(){return valSendAdf2IdentDisable;}
byte BitsAndDroidsFlightConnector::sendAdf2IdentEnable(){return valSendAdf2IdentEnable;}
byte BitsAndDroidsFlightConnector::sendAdf2IdentToggle(){return valSendAdf2IdentToggle;}
byte BitsAndDroidsFlightConnector::sendAdf2IdentSet(){return valSendAdf2IdentSet;}

//XPNDR
byte BitsAndDroidsFlightConnector::sendXpndr1000Inc(){return valSendXpndr1000Inc;}
byte BitsAndDroidsFlightConnector::sendXpndr100Inc(){return valSendXpndr100Inc;}
byte BitsAndDroidsFlightConnector::sendXpndr10Inc(){return valSendXpndr10Inc;}
byte BitsAndDroidsFlightConnector::sendXpndr1Inc(){return valSendXpndr1Inc;}
byte BitsAndDroidsFlightConnector::sendXpndr1000Dec(){return valSendXpndr1000Dec;}
byte BitsAndDroidsFlightConnector::sendXpndr100Dec(){return valSendXpndr100Dec;}
byte BitsAndDroidsFlightConnector::sendXpndr10Dec(){return valSendXpndr10Dec;}
byte BitsAndDroidsFlightConnector::sendXpndr1Dec(){return valSendXpndr1Dec;}
//String BitsAndDroidsFlightConnector::sendXpndrSet(char*){return ;}

//Avionics
int BitsAndDroidsFlightConnector::sendAvionicsMaster1On(){return valSendAvionicsMaster1On;}
int BitsAndDroidsFlightConnector::sendAvionicsMaster1Off(){return valSendAvionicsMaster1Off;}
int BitsAndDroidsFlightConnector::sendAvionicsMaster2On(){return valSendAvionicsMaster2On;}
int BitsAndDroidsFlightConnector::sendAvionicsMaster2Off(){return valSendAvionicsMaster2Off;}
int BitsAndDroidsFlightConnector::sendParkingBrake(){return valSendParkingBrake;}

//Battery
int BitsAndDroidsFlightConnector::sendToggleMasterBattery1 (){return valSendToggleMasterBattery1;}
int BitsAndDroidsFlightConnector::sendToggleMasterBattery2(){return valSendToggleMasterBattery2;}
int BitsAndDroidsFlightConnector::sendToggleExternalPower(){return valSendToggleExternalPower;}

int BitsAndDroidsFlightConnector::sendToggleMasterAlternator(){return valSendToggleMasterAlternator;}

//Flaps
int BitsAndDroidsFlightConnector::sendFlapsUp(){ return valSendFlapsUp;}
int BitsAndDroidsFlightConnector::sendFlaps1(){ return valSendFlaps1;}
int BitsAndDroidsFlightConnector::sendFlaps2(){ return valSendFlaps2;}
int BitsAndDroidsFlightConnector::sendFlaps3(){ return valSendFlaps3;}
int BitsAndDroidsFlightConnector::sendFlapsDown(){ return valSendFlapsDown;}
int BitsAndDroidsFlightConnector::sendFlapsInc(){ return valSendFlapsInc;}
int BitsAndDroidsFlightConnector::sendFlapsDec(){ return valSendFlapsDec;}
