#include "Arduino.h"
#include "BitsAndDroidsFlightConnector.h"


BitsAndDroidsFlightConnector::BitsAndDroidsFlightConnector(
  bool isLeonardoMicro) {
  this->serial = &Serial;
  if (isLeonardoMicro) {
    Serial.begin(115200);
    Serial.setTimeout(50);
  }
}

BitsAndDroidsFlightConnector::BitsAndDroidsFlightConnector(
  bool isLeonardoMicro, HardwareSerial* serial) {
  this->serial = serial;
  if (isLeonardoMicro) {
    serial->begin(115200);
    serial->setTimeout(50);
  }
}

#ifndef ARDUINO_SAM_DUE
BitsAndDroidsFlightConnector::BitsAndDroidsFlightConnector(
  bool isLeonardoMicro, SoftwareSerial* serial) {
  this->serial = serial;
  if (isLeonardoMicro) {
    serial->begin(115200);
    serial->setTimeout(50);
  }
}
#else
BitsAndDroidsFlightConnector::BitsAndDroidsFlightConnector(
  bool isLeonardoMicro, Serial_* serial) {
  this->serial = serial;
  if (isLeonardoMicro) {
    serial->begin(115200);
    serial->setTimeout(50);
  }
}

#endif
void BitsAndDroidsFlightConnector::sendSetYokeAxis(byte elevatorPin,bool reversedElevator, byte aileronPin, bool reversedAileron, int minVal, int maxVal){

   elevator = (EMA_a * analogRead(elevatorPin)) + ((1-EMA_a) * elevator);
   aileron = (EMA_a * analogRead(aileronPin)) + ((1-EMA_a) * aileron);
   if(elevator != oldElevator || oldAileron != aileron){
       elevatorPercentage = getPercentage(elevator, minVal, maxVal, reversedElevator);
       oldElevator = elevator;
       aileronPercentage = getPercentage(aileron, minVal, maxVal, reversedAileron);
       oldAileron = aileron;
       packagedData = sprintf(valuesBuffer, "%s %i %i", "103", elevatorPercentage,
               aileronPercentage);
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
         packagedData = sprintf(valuesBuffer, "%s %i %i", "115", mixturePercentage[0], mixturePercentage[1]);
  this->serial->println(valuesBuffer);
}

void BitsAndDroidsFlightConnector::sendSetElevatorTrimPot(byte potPin,int minVal, int maxVal){
    currentTrim = (EMA_a * analogRead(potPin)) + ((1 - EMA_a) * currentTrim);
    if(currentTrim != oldTrim){
        int trimFormatted = calculateAxis(currentTrim,0 , 1023);
        packagedData = sprintf(valuesBuffer, "%s %i","900", trimFormatted);
        oldTrim = currentTrim;
        this->serial->println(valuesBuffer);
    }
}
void BitsAndDroidsFlightConnector::sendSetBrakePot(byte leftPin, byte rightPin,int minVal, int maxVal){
    currentLeftBrake = (EMA_a * analogRead(leftPin)) + ((1 - EMA_a) * currentLeftBrake);
    currentRightBrake = (EMA_a * analogRead(rightPin)) + ((1 - EMA_a) * currentRightBrake);

    bool changed = false;
    if(oldLeftBrake != currentLeftBrake){

        leftBrakeFormated = calculateAxis(currentLeftBrake, minVal, maxVal);
        oldLeftBrake = currentLeftBrake;
        changed = true;
    }
    if(oldRightBrake != currentRightBrake){

         rightBrakeFormated = calculateAxis(currentRightBrake, minVal, maxVal);
          oldRightBrake = currentRightBrake;
         changed = true;
    }


      if(changed){
      packagedData = sprintf(valuesBuffer, "%s %i %i","902", leftBrakeFormated, rightBrakeFormated);
      this->serial->println(valuesBuffer);
      delay(50);
      }
    }

void BitsAndDroidsFlightConnector::sendSetRudderPot(byte potPin,int minVal, int maxVal){
    currentRudder = (EMA_a * analogRead(potPin)) + ((1 - EMA_a) * currentRudder);
    if(currentRudder != oldRudderAxis){
        int rudderFormated = calculateAxis(currentRudder,minVal ,maxVal);
        packagedData = sprintf(valuesBuffer, "%s %i","901", rudderFormated);
        oldRudderAxis = currentRudder;
        this->serial->println(valuesBuffer);
        delay(50);
    }

}
int BitsAndDroidsFlightConnector::calculateAxis(int value, int minVal, int maxVal){
    return map(value, minVal, maxVal, -16383, 16383);
}
void BitsAndDroidsFlightConnector::sendSetElevatorTrim(int value){
        packagedData = sprintf(valuesBuffer, "%s i%","900", value);
        this->serial->println(valuesBuffer);
}

byte BitsAndDroidsFlightConnector::getPercentage(int value, int minVal, float max, bool flipped) {
    byte percentage = 0;
    if (!flipped){
        percentage = map(value, minVal,max, 0,100);
    } else{
        percentage = map(value, max,minVal, 0,100);
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

  if (this->serial->available() > 0) {
    receivedValue = this->serial->readStringUntil('\n');
    switchHandling();
  }

}

void BitsAndDroidsFlightConnector::switchHandling(){

    prefix = receivedValue.substring(0, 3);
    cutValue = receivedValue.substring(3);
    int prefixVal = prefix.toInt();
    lastPrefix = prefixVal;

    switch (prefixVal) {
      // Ap

      // lights
      case 33: {
        lightTaxiOn = convBool(cutValue);
        break;
      }
      case 34: {
        lightStrobeOn = convBool(cutValue);
        break;
      }

      case 35: {
        lightPanelOn = convBool(cutValue);
        break;
      }
      case 36: {
        lightRecognitionOn = convBool(cutValue);
        break;
      }
      case 37: {
        lightWingOn = convBool(cutValue);
        break;
      }
      case 38: {
        lightLogoOn = convBool(cutValue);
        break;
      }
      case 39: {
        lightCabinOn = convBool(cutValue);
        break;
      }
      case 40: {
        lightHeadOn = convBool(cutValue);
        break;
      }
      case 41: {
        lightBrakeOn = convBool(cutValue);
        break;
      }
      case 42: {
        lightNavOn = convBool(cutValue);
        break;
      }
      case 43: {
        lightBeaconOn = convBool(cutValue);
        break;
      }
      case 44: {
        lightLandingOn = convBool(cutValue);
        break;
      }
      case 275: {
        fuelTotalPercentage = cutValue.toInt();
        break;
      }
    case 312:{
        feetAboveGround = cutValue.toInt();
        break;
    }
      case 323: {
        onGround = convBool(cutValue);
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
        //GPS
    case 454:{
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

      case 337: {
        kohlmanAltimeter = cutValue.toInt();
        break;
      }
      case 344: {
        indicatedHeading = cutValue.toInt();
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
        activeCom1 = convertToFreq(cutValue);
        break;
      }
      case 901: {
        standByCom1 = convertToFreq(cutValue);
        break;
      }
      case 902: {
        activeCom2 = convertToFreq(cutValue);
        break;
      }
      case 903: {
        standByCom2 = convertToFreq(cutValue);
        break;
      }
      case 910: {
        activeNav1 = convertToNavFreq(cutValue);
        break;
      }
      case 911: {
        standbyNav1 = convertToNavFreq(cutValue);
        break;
      }
      case 912: {
        activeNav2 = convertToNavFreq(cutValue);
        break;
      }
      case 913: {
        standbyNav2 = convertToNavFreq(cutValue);
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
        adfActiveFreq1 = cutValue;
        break;
      }
      case 955: {
        adfStandbyFreq1 = cutValue;
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
        adfActiveFreq2 = convertToNavFreq(cutValue);
        break;
      }
      case 959: {
        adfStandbyFreq2 = convertToNavFreq(cutValue);
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

      // PLANE DATA
      case 999: {
        planeName = cutValue;
        break;
      }

    case 606:{
        navObs1 = cutValue.toInt();
        break;
    }
    case 607:{
        navObs2 = cutValue.toInt();
        break;
    }
    case 234:{
        fuelTankCenterLevel = cutValue.toInt();
        break;
    }
    case 235:{
        fuelTankCenter2Level = cutValue.toInt();
        break;
    }

    case 236:{
        fuelTankCenter3Level = cutValue.toInt();
        break;
    }

    case 237:{
        fuelTankLeftMainLevel = cutValue.toInt();
        break;
    }

    case 238:{
        fuelTankLeftAuxLevel = cutValue.toInt();
        break;
    }

    case 239:{
        fuelTankLeftTipLevel = cutValue.toInt();
        break;
    }

    case 240:{
        fuelTankRightMainLevel = cutValue.toInt();
        break;
    }

    case 241:{
        fuelTankRightAuxLevel = cutValue.toInt();
        break;
    }

    case 242:{
        fuelTankRightTipLevel = cutValue.toInt();
        break;
    }

    case 243:{
        fuelTankExternal1Level = cutValue.toInt();
        break;
    }

    case 244:{
        fuelTankExternal2Level = cutValue.toInt();
        break;
    }

    case 245:{
        fuelTankCenterCapacity = cutValue.toInt();
        break;
    }

    case 246:{
        fuelTankCenter2Capacity = cutValue.toInt();
        break;
    }

    case 247:{
        fuelTankCenter3Capacity = cutValue.toInt();
        break;
    }

    case 248:{
        fuelTankLeftMainCapacity = cutValue.toInt();
        break;
    }

    case 249:{
        fuelTankLeftAuxCapacity = cutValue.toInt();
        break;
    }

    case 250:{
        fuelTankLeftTipCapacity = cutValue.toInt();
        break;
    }

    case 251:{
        fuelTankRightMainCapacity = cutValue.toInt();
        break;
    }

    case 252:{
        fuelTankRightAuxCapacity = cutValue.toInt();
        break;
    }

    case 253:{
        fuelTankRightTipCapacity = cutValue.toInt();
        break;
    }

    case 254:{
        fuelTankExternal1Capacity = cutValue.toInt();
        break;
    }

    case 255:{
        fuelTankExternal2Capacity = cutValue.toInt();
        break;
    }

    case 256:{
        fuelTankLeftCapacity = cutValue.toFloat();
        break;
    }
    case 257:{
        fuelTankRightCapacity = cutValue.toFloat();
        break;
    }
    case 258:{
        fuelTankCenterQuantity = cutValue.toInt();
        break;
    }
    case 259:{
        fuelTankCenter2Quantity = cutValue.toInt();
        break;
    }
    case 260:{
        fuelTankCenter3Quantity = cutValue.toInt();
        break;
    }
    case 261:{
        fuelTankLeftMainQuantity = cutValue.toInt();
        break;
    }

    case 262:{
        fuelTankLeftAuxQuantity = cutValue.toInt();
        break;
    }

    case 263:{
        fuelTankLeftTipQuantity = cutValue.toInt();
        break;
    }

    case 264:{
        fuelTankRightMainQuantity = cutValue.toInt();
        break;
    }

    case 265:{
        fuelTankRightAuxCapacity = cutValue.toInt();
        break;
    }

    case 266:{
        fuelTankRightTipQuantity = cutValue.toInt();
        break;
    }

    case 267:{
        fuelTankExternal1Quantity = cutValue.toInt();
        break;
    }
    case 268:{
        fuelTankExternal2Quantity = cutValue.toInt();
        break;
    }

    case 269:{
        fuelTankLeftQuantity = cutValue.toFloat();
        break;
    }
    case 270:{
        fuelTankRightQuantity = cutValue.toFloat();
        break;
    }
    case 271:{
        fuelTankTotalQuantity = cutValue.toInt();
        break;
    }
    case 505:{
        parkingBrakeIndicator = convBool(cutValue);
        break;
    }





      default:
        break;
    }

}


void BitsAndDroidsFlightConnector::propsInputHandling(int propPin1,
                                                      int propPin2,
                                                      int minVal,float maxVal, bool reversed) {
  propValue1 = (EMA_a * analogRead(propPin1)) + ((1 - EMA_a) * propValue1);
  propValue2 = (EMA_a * analogRead(propPin2)) + ((1 - EMA_a) * propValue2);
  if (propValue1 != oldPropValue1 || propValue2 != oldPropValue2) {
    oldPropValue1 = propValue1;
    oldPropValue2 = propValue2;

        prop1 = getPercentage(propValue1,minVal, maxVal, reversed);
        prop2 = getPercentage(propValue2,minVal, maxVal, reversed);



    props[0] = prop1;
    props[1] = prop2;

    sendCombinedPropValues();
  }
}
void BitsAndDroidsFlightConnector::mixtureInputHandling(int mixturePin1,
                                                      int mixturePin2,
                                                      int minVal,float maxVal,bool reversed) {
  mixtureValue1 = (EMA_a * analogRead(mixturePin1)) + ((1 - EMA_a) * mixtureValue1);
  mixtureValue2 = (EMA_a * analogRead(mixturePin2)) + ((1 - EMA_a) * mixtureValue2);
  if (mixtureValue1 != oldMixtureValue1 || mixtureValue2 != oldMixtureValue2) {
    oldMixtureValue1 = mixtureValue1;
    oldMixtureValue2 = mixtureValue2;

    mixturePercentage[0] = getPercentage(mixtureValue1, minVal,maxVal, reversed);
    mixturePercentage[1] = getPercentage(mixtureValue2, minVal,maxVal, reversed);
    }


    sendCombinedMixtureValues();
  }

void BitsAndDroidsFlightConnector::simpleInputHandling(int throttlePin,
                                                       int minVal,float maxVal, bool reversed) {
  value = (EMA_a * analogRead(throttlePin)) + ((1 - EMA_a) * value);

  if (value != oldValue) {
    oldValue = value;

    engine1 = getPercentage(value,minVal, maxVal, reversed);
    engine2 = getPercentage(value, minVal,maxVal, reversed);
    engine3 = getPercentage(value, minVal,maxVal, reversed);
    engine4 = getPercentage(value, minVal,maxVal, reversed);


    engines[0] = engine1;
    engines[1] = engine2;
    engines[2] = engine3;
    engines[3] = engine4;

    sendCombinedThrottleValues();
  }
}
void BitsAndDroidsFlightConnector::advancedInputHandling(
    int eng1Pin, int eng2Pin, int eng3Pin, int eng4Pin,int minVal,
    float maxVal,bool reversed) {
  valueEng1 = (EMA_a * analogRead(eng1Pin)) + ((1 - EMA_a) * valueEng1);
  valueEng2 = (EMA_a * analogRead(eng2Pin)) + ((1 - EMA_a) * valueEng2);
  valueEng3 = (EMA_a * analogRead(eng3Pin)) + ((1 - EMA_a) * valueEng3);
  valueEng4 = (EMA_a * analogRead(eng4Pin)) + ((1 - EMA_a) * valueEng4);
  bool changed = false;

  if (valueEng1 != oldValueEng1) {
    oldValueEng1 = valueEng1;

    engine1 = 100 - getPercentage(valueEng1, minVal,maxVal, reversed);
    engines[0] = engine1;
    changed = true;
  }
  if (valueEng2 != oldValueEng2) {
    oldValueEng2 = valueEng2;
    engine2 = 100 - getPercentage(valueEng2, minVal,maxVal, reversed);
    engines[1] = engine2;
    changed = true;
  }
  if (valueEng3 != oldValueEng3) {
    oldValueEng3 = valueEng3;
    engine3 = getPercentage(valueEng3,minVal,maxVal, reversed);
    engines[2] = engine3;
    changed = true;
  }
  if (valueEng4 != oldValueEng4) {
    oldValueEng4 = valueEng4;

    engine4 = 100 - getPercentage(valueEng4, minVal,maxVal, reversed);
    engines[3] = engine4;
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

int BitsAndDroidsFlightConnector::getLastPrefix() { return lastPrefix; }
// Set jitter algorithm EMA_a
void BitsAndDroidsFlightConnector::setEMA_a(float a) { EMA_a = a; }
// RECEIVING VALUES
// GPS



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
byte BitsAndDroidsFlightConnector::sendCom1WholeDec(){return valSendCom1WholeDec;}
byte BitsAndDroidsFlightConnector::sendCom1WholeInc(){return valSendCom1WholeInc;}
byte BitsAndDroidsFlightConnector::sendCom2WholeDec(){return valSendCom2WholeDec;}
byte BitsAndDroidsFlightConnector::sendCom2WholeInc(){return valSendCom2WholeInc;}
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
