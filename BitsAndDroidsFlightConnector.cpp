#include "Arduino.h"
#include "BitsAndDroidsFlightConnector.h"


BitsAndDroidsFlightConnector::BitsAndDroidsFlightConnector(bool isLeonardoMicro){
    if (isLeonardoMicro) {
        Serial.begin(115200);
        Serial.setTimeout(50);
    }
}
void BitsAndDroidsFlightConnector::sendCombinedValues()
{
    packagedData = sprintf(valuesBuffer, "%s %i %i %i %i %i", "199", engines[0], engines[1], engines[2], engines[3], mixturePercentage);
    Serial.println(valuesBuffer);
}

int BitsAndDroidsFlightConnector::getPercentage(int value, float maxVal) {
    int percentage = (value / maxVal) * 100;
    if (percentage == 99) {
        percentage = 100;
    }
    return percentage;
}
bool convBool(String input){
     if (input == "0"){
         return false;
     } else{
         return true;
     }
}

void BitsAndDroidsFlightConnector::dataHandling(){

    if (Serial.available() > 0){
        String value = Serial.readStringUntil('\n');
        String prefix = value.substring(0, 3);
        String receivedValue = value.substring(3);
        int prefixVal = prefix.toInt();
        lastPrefix = prefixVal;

        switch (prefixVal) {
        //Ap

        //lights
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
           lightRecognitionOn  = convBool(receivedValue);
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

            //warnings
        case 333:{
            stallWarning = convBool(receivedValue);
            break;
        }
        case 334:{
            overspeedWarning = convBool(receivedValue);
            break;
        }

        //Flaps
        case 510:{
            flapsHandlePct = receivedValue;
        break; }
        case 511:{
            flapsHandleIndex = receivedValue;
        break; }
        case 512:{
            flapsNumHandlePos = receivedValue;
        break; }
        case 513:{
            trailingEdgeFlapsLeftPercent = receivedValue;
        break; }
        case 514:{
            trailingEdgeFlapsRightPercent = receivedValue;
        break; }
        case 515:{
            trailingEdgeFlapsLeftAngle = receivedValue;
        break; }
        case 516:{
            trailingEdgeFlapsRightAngle = receivedValue;
        break; }
        case 517:{
            leadingEdgeFlapsLeftPct = receivedValue;
        break; }
        case 518:{
            leadingEdgeFlapsRightPct = receivedValue;
        break; }
        case 519:{
            leadingEdgeFlapsLeftAngle = receivedValue;
        break; }
        case 520:{
            leadingEdgeFlapsRightAngle = receivedValue;
        break; }

        //Gears
        case 526:{
            gearHandlePos = convBool(receivedValue);
        break; }
        case 527:{
            gearHydraulicPressure = receivedValue;
        break; }
        case 528:{
           tailWheelLock = convBool(receivedValue);
        break; }
        case 529:{
           gearCenterPositionPct = receivedValue;
        break; }
        case 530:{
           gearLeftPositionPct = receivedValue;
        break; }
        case 531:{
            gearRightPositionPct = receivedValue;
        break; }
        case 532:{
           gearTailPositionPct = receivedValue;
        break; }
        case 533:{
           gearAuxPosition = receivedValue;
        break; }
        case 536:{
           gearTotalPct = receivedValue;
        break; }

        //AP
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
        case 586:{
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

        //Rudder trim
        case 498:{
            elevatorTrimPos = receivedValue;
        break; }
        case 500:{
            elevatorTrimPct = receivedValue;
        break; }
        case 562:{
            aileronTrimDegr = receivedValue;
        break; }
        case 563:{
            aileronTrimPct = receivedValue;
        break; }
        case 566:{
            rudderTrimDegr = receivedValue;
        break; }
        case 567:{
            rudderTrimPct = receivedValue;
        break; }

        case 330:{
            trueVerticalSpeed = receivedValue;
            break;
        }

        case 326:{
            indicatedAirspeed = receivedValue;
            break;
                }
        case 335:{

            indicatedAltitude = receivedValue;
            break;
                }

        case 337: {
            kohlmanAltimeter = inhg(receivedValue);
            break;
        }
        case 344:
                {

            indicatedHeading = receivedValue;
            break;
                }
        case 430:
                {
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
        case 910:{
            activeNav1 = convertToNavFreq(receivedValue);
             break;
        }
        case 911:{
            standbyNav1 = convertToNavFreq(receivedValue);
             break;
        }
        case 912:{
            activeNav2 = convertToNavFreq(receivedValue);
             break;
        }
        case 913: {
            standbyNav2 = convertToNavFreq(receivedValue);
             break;
        }

        //PLANE DATA
        case 999: {
            planeName = receivedValue;
            break;
        }

        default: break;
        }

    }

}



void BitsAndDroidsFlightConnector::simpleInputHandling(int throttlePin, float maxVal) {
    value = analogRead(throttlePin);
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

        sendCombinedValues();
    }
    delay(50);
}
void BitsAndDroidsFlightConnector::advancedInputHandling(int eng1Pin,int eng2Pin,int eng3Pin,int eng4Pin,int mixturePin, float maxVal) {
    valueEng1 = analogRead(eng1Pin);
    valueEng2 = analogRead(eng2Pin);
    valueEng3 = analogRead(eng3Pin);
    valueEng4 = analogRead(eng4Pin);

    mixtureValue = analogRead(mixturePin);

    bool changed = false;

    if (valueEng1 != oldValueEng1) {
        oldValueEng1 = valueEng1;
        int engine1 = getPercentage(valueEng1, maxVal);
        engines[0] = engine1;
        changed = true;
    }
    if (valueEng2 != oldValueEng2) {
        oldValueEng2 = valueEng2;
        int engine2 = getPercentage(valueEng2, maxVal);
        engines[1] = engine2;
        changed = true;

    }
    if (valueEng3 != oldValueEng3) {
        oldValueEng3 = valueEng3;
        int engine3 = getPercentage(valueEng3, maxVal);
        engines[2] = engine3;
        changed = true;
    }
    if (valueEng4 != oldValueEng4) {
        oldValueEng4 = valueEng4;
        int engine4 = getPercentage(valueEng4, maxVal);
        engines[3] = engine4;
        changed = true;

    }
        if (mixtureValue != oldMixtureValue)
        {
        oldMixtureValue = mixtureValue;
        mixturePercentage = getPercentage(mixtureValue, maxVal);
        changed = true;
        }
    if (changed) { sendCombinedValues(); }
    delay(100);
}
void BitsAndDroidsFlightConnector::superAdvancedInputHandling(int eng1Percentage, int eng2Percentage, int eng3Percentage, int eng4Percentage, int receivedMixturePercentage)
{
    engines[0] = eng1Percentage;
    engines[1] = eng2Percentage;
    engines[2] = eng3Percentage;
    engines[3] = eng4Percentage;
    mixturePercentage = receivedMixturePercentage;
    sendCombinedValues();
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
        //if its bigger add 10
        valOfAltm += 10;
    }
    //remove the last digit that
    valOfAltm = (valOfAltm - valOfCorrection) / 10;
    String valString = String(valOfAltm);
    String stringA = valString.substring(0, 2);
    String stringB = valString.substring(2);
    return stringA + "." + stringB;
}
int BitsAndDroidsFlightConnector::getLastPrefix() {return lastPrefix;}

//RECEIVING VALUES

//Ap
String BitsAndDroidsFlightConnector::getApVerticalSpeed() { return apVerticalSpeed; }
String BitsAndDroidsFlightConnector::getApAltLock() { return apAltLock; }

bool BitsAndDroidsFlightConnector::getAPAvailable(){return APAvailable;}
bool BitsAndDroidsFlightConnector::getAPMasterOn(){return APMasterOn;}
bool BitsAndDroidsFlightConnector::getAPWingLevelerOn(){return APWingLevelerOn;}
bool BitsAndDroidsFlightConnector::getAPNav1LockOn(){return APNav1LockOn;}
bool BitsAndDroidsFlightConnector::getAPHeadingLockOn(){return APHeadingLockOn;}
bool BitsAndDroidsFlightConnector::getAPAltitudeLockOn(){return APAltitudeLockOn;}
bool BitsAndDroidsFlightConnector::getAPAttitudeLockOn(){return APAttitudeLockOn;}
bool BitsAndDroidsFlightConnector::getAPGlideslopeHoldOn(){return APGlideslopeHoldOn;}
bool BitsAndDroidsFlightConnector::getAPApproachHoldOn(){return APApproachHoldOn;}
bool BitsAndDroidsFlightConnector::getAPBackcourseHoldOn(){return APBackcourseHoldOn;}
bool BitsAndDroidsFlightConnector::getAPFlightDirectorOn(){return APFlightDirectorOn;}
bool BitsAndDroidsFlightConnector::getAPAirspeedHoldOn(){return APAirspeedHoldOn;}
bool BitsAndDroidsFlightConnector::getAPMachHoldOn(){return APMachHoldOn;}
bool BitsAndDroidsFlightConnector::getAPYawDampenerOn(){return APYawDampenerOn;}
bool BitsAndDroidsFlightConnector::getAPAutothrottleArm(){return APAutothrottleArm;}
bool BitsAndDroidsFlightConnector::getAPTakeoffPowerOn(){return APTakeoffPowerOn;}
bool BitsAndDroidsFlightConnector::getAPAutothrottleOn(){return APAutothrottleOn;}
bool BitsAndDroidsFlightConnector::getAPVerticalHoldOn(){return APVerticalHoldOn;}
bool BitsAndDroidsFlightConnector::getAPRPMHoldOn(){return APRPMHoldOn;}

//Avionics
String BitsAndDroidsFlightConnector::getApHeadingLock() { return apHeadingLock; }
String BitsAndDroidsFlightConnector::getKohlmanAltimeter() { return kohlmanAltimeter; }
String BitsAndDroidsFlightConnector::getBarPressure() { return barPressure; }
String BitsAndDroidsFlightConnector::getIndicatedAirspeed() { return indicatedAirspeed; }
String BitsAndDroidsFlightConnector::getIndicatedAltitude() { return indicatedAltitude; }
String BitsAndDroidsFlightConnector::getIndicatedHeading() { return indicatedHeading; }
String BitsAndDroidsFlightConnector::getIndicatedGPSGroundspeed() { return indicatedGPSGroundspeed; }
String BitsAndDroidsFlightConnector::getTrueVerticalSpeed() { return trueVerticalSpeed; }
String BitsAndDroidsFlightConnector::getFuelTotalPercentage() { return fuelTotalPercentage;  }

//lights
bool BitsAndDroidsFlightConnector::getLightTaxiOn()       { return lightTaxiOn; }
bool BitsAndDroidsFlightConnector::getLightStrobeOn()      { return lightStrobeOn; }
bool BitsAndDroidsFlightConnector::getLightPanelOn()       { return lightPanelOn; }
bool BitsAndDroidsFlightConnector::getLightRecognitionOn() { return  lightRecognitionOn; }
bool BitsAndDroidsFlightConnector::getLightWingOn()        { return lightWingOn; }
bool BitsAndDroidsFlightConnector::getLightLogoOn()        { return lightLogoOn; }
bool BitsAndDroidsFlightConnector::getLightCabinOn()       { return lightCabinOn; }
bool BitsAndDroidsFlightConnector::getLightHeadOn()        { return lightHeadOn; }
bool BitsAndDroidsFlightConnector::getLightBrakeOn()       { return lightBrakeOn; }
bool BitsAndDroidsFlightConnector::getLightNavOn()         { return lightNavOn; }
bool BitsAndDroidsFlightConnector::getLightBeaconOn()      { return lightBeaconOn; }
bool BitsAndDroidsFlightConnector::getLightLandingOn()     { return lightLandingOn; }

//Coms
String BitsAndDroidsFlightConnector::getActiveCom1() { return activeCom1; }
String BitsAndDroidsFlightConnector::getActiveCom2() { return activeCom2; }
String BitsAndDroidsFlightConnector::getStandbyCom1() { return standByCom1; }
String BitsAndDroidsFlightConnector::getStandbyCom2() { return standByCom2; }
String BitsAndDroidsFlightConnector::getActiveNav1(){ return activeNav1;}
String BitsAndDroidsFlightConnector::getActiveNav2(){ return activeNav2;}
String BitsAndDroidsFlightConnector::getStandbyNav1(){return standbyNav1;}
String BitsAndDroidsFlightConnector::getStandbyNav2(){return standbyNav2;}

//Warnings
bool BitsAndDroidsFlightConnector::getStallWarningOn() {return stallWarning;}
bool BitsAndDroidsFlightConnector::getOverspeedWarningOn() {return overspeedWarning;}

//Flaps
String BitsAndDroidsFlightConnector::getFlapsHandlePct(){return flapsHandlePct ;}
String BitsAndDroidsFlightConnector::getFlapsHandleIndex(){return flapsHandleIndex;}
String BitsAndDroidsFlightConnector::getFlapsNumHandlePos(){return flapsNumHandlePos;}
String BitsAndDroidsFlightConnector::getTrailingEdgeFlapsLeftPercent(){return trailingEdgeFlapsLeftPercent;}
String BitsAndDroidsFlightConnector::getTrailingEdgeFlapsRightPercent(){return trailingEdgeFlapsRightPercent;}
String BitsAndDroidsFlightConnector::getTrailingEdgeFlapsLeftAngle(){return trailingEdgeFlapsLeftAngle;}
String BitsAndDroidsFlightConnector::getTrailingEdgeFlapsRightAngle(){return trailingEdgeFlapsRightAngle;}
String BitsAndDroidsFlightConnector::getLeadingEdgeFlapsLeftPct(){return leadingEdgeFlapsLeftPct;}
String BitsAndDroidsFlightConnector::getLeadingEdgeFlapsRightPct(){return leadingEdgeFlapsRightPct;}
String BitsAndDroidsFlightConnector::getLeadingEdgeFlapsLeftAngle(){return leadingEdgeFlapsLeftAngle;}
String BitsAndDroidsFlightConnector::getLeadingEdgeFlapsRightAngle(){return leadingEdgeFlapsRightAngle;}

//Gears
bool BitsAndDroidsFlightConnector::getGearHandlePos(){return gearHandlePos;}
String BitsAndDroidsFlightConnector::getGearHydraulicPressure(){return gearHydraulicPressure;}
bool BitsAndDroidsFlightConnector::getTailWheelLock(){return tailWheelLock;}
String BitsAndDroidsFlightConnector::getGearCenterPositionPct(){return gearCenterPositionPct;}
String BitsAndDroidsFlightConnector::getGearLeftPositionPct(){return gearLeftPositionPct;}
String BitsAndDroidsFlightConnector::getGearRightPositionPct(){return gearRightPositionPct;}
String BitsAndDroidsFlightConnector::getGearTailPositionPct(){return gearTailPositionPct;}
String BitsAndDroidsFlightConnector::getGearAuxPosition(){return gearAuxPosition;}
String BitsAndDroidsFlightConnector::getGearTotalPct(){return gearTotalPct;}

//Rudder/Trim
String BitsAndDroidsFlightConnector::getAileronTrimPct(){return aileronTrimPct;}
String BitsAndDroidsFlightConnector::getAileronTrimDegr(){return aileronTrimDegr;}
String BitsAndDroidsFlightConnector::getRudderTrimDegr(){return rudderTrimDegr;}
String BitsAndDroidsFlightConnector::getRudderTrimPct(){return rudderTrimPct;}
String BitsAndDroidsFlightConnector::getElevatorTrimPos(){return elevatorTrimPos;}
String BitsAndDroidsFlightConnector::getElevatorTrimPct(){return elevatorTrimPct;}

//Plane data
String BitsAndDroidsFlightConnector::getPlaneName(){return planeName;}

//----------------------
//TRANSMIT FUNCTIONS
//AP
int BitsAndDroidsFlightConnector::sendApMasterOn(){return valSendApMasterOn;}
int BitsAndDroidsFlightConnector::sendApPanelHeadingLock(){return valSendApPanelHeadingLock;}
int BitsAndDroidsFlightConnector::sendAPPanelAltitudeHold(){return valSendAPPanelAltitudeHold;}
int BitsAndDroidsFlightConnector::sendAPAttitudeHoldOn(){return valSendAPAttitudeHoldOn;}
int BitsAndDroidsFlightConnector::sendAPLocHoldOn(){return valSendAPLocHoldOn;}
int BitsAndDroidsFlightConnector::sendAPAprHoldOn(){return valSendAPAprHoldOn;}
int BitsAndDroidsFlightConnector::sendAPHeadingHoldOn(){return valSendAPHeadingHoldOn;}
int BitsAndDroidsFlightConnector::sendAltitudeHoldOn(){return valSendAPAltitudeHold;}
int BitsAndDroidsFlightConnector::sendApWingLevelerOn(){return valSendApWingLevelerOn;}
int BitsAndDroidsFlightConnector::sendBCHoldOn(){return valSendBCHoldOn;}
int BitsAndDroidsFlightConnector::sendAPNav1HoldOn(){return valSendAPNav1HoldOn;}
int BitsAndDroidsFlightConnector::sendAPAttitudeHoldOff(){return valSendAPAttitudeHoldOff;}
int BitsAndDroidsFlightConnector::sendAPLocHoldOff(){return valSendAPLocHoldOff;}
int BitsAndDroidsFlightConnector::sendAprHoldOff(){return valSendAprHoldOff;}
int BitsAndDroidsFlightConnector::sendAPHeadingHoldOff(){return valSendAPHeadingHoldOff;}
int BitsAndDroidsFlightConnector::sendAPAltitudeHoldOff(){return valSendAPAltitudeHoldOff;}
int BitsAndDroidsFlightConnector::sendWingLevelerOff(){return valSendWingLevelerOff;}
int BitsAndDroidsFlightConnector::sendAPBCHoldOff(){return valSendAPBCHoldOff;}
int BitsAndDroidsFlightConnector::sendAPNav1HoldOff(){return valSendAPNav1HoldOff;}
int BitsAndDroidsFlightConnector::sendAPAirspeedHold(){return valSendAPAirspeedHold;}
int BitsAndDroidsFlightConnector::sendAPPanelSpeedHold(){return valSendAPPanelSpeedHold;}
int BitsAndDroidsFlightConnector::sendAPAltitudeInc(){return valSendAPAltitudeInc;}
int BitsAndDroidsFlightConnector::sendAPAltitudeDec(){return valSendAPAltitudeDec;}
int BitsAndDroidsFlightConnector::sendAPVSInc(){return valSendAPVSInc;}
int BitsAndDroidsFlightConnector::sendAPVSDec(){return valSendAPVSDec;}
int BitsAndDroidsFlightConnector::sendAPSpeedInc(){return valSendAPSpeedInc;}
int BitsAndDroidsFlightConnector::sendAPSpeedDec(){return valSendAPSpeedDec;}
int BitsAndDroidsFlightConnector::sendAPPanelMachHold(){return valSendAPPanelMachHold;}
int BitsAndDroidsFlightConnector::sendAPMachInc(){return valSendAPMachInc;}
int BitsAndDroidsFlightConnector::sendAPMachDec(){return valSendAPMachDec;}
int BitsAndDroidsFlightConnector::sendAPMachHold(){return valSendAPMachHold;}
int BitsAndDroidsFlightConnector::sendAPAltitudeSetMetric(){return valSendAPAltitudeSetMetric;}
int BitsAndDroidsFlightConnector::sendAPVSSetEnglish(){return valSendAPVSSetEnglish;}
int BitsAndDroidsFlightConnector::sendAPSpeedSet(){return valSendAPPanelSpeedSet;}
int BitsAndDroidsFlightConnector::sendAPMachVarSet(){return valSendAPMachVarSet;}
int BitsAndDroidsFlightConnector::sendAPAirspeedOn(){return valSendAPAirspeedOn;}
int BitsAndDroidsFlightConnector::sendAPAirspeedOff(){return valSendAPAirspeedOff;}
int BitsAndDroidsFlightConnector::sendAPAirspeedSet(){return valSendAPAirspeedSet;}
int BitsAndDroidsFlightConnector::sendAPMachOn(){return valSendAPMachOn;}
int BitsAndDroidsFlightConnector::sendAPMachOff(){return valSendAPMachOff;}
int BitsAndDroidsFlightConnector::sendAPMachSet(){return valSendAPMachSet;}
int BitsAndDroidsFlightConnector::sendAPPanelAltitudeOn(){return valSendAPPanelAltitudeOn;}
int BitsAndDroidsFlightConnector::sendAPPanelAltitudeOff(){return valSendAPPanelAltitudeOff;}
int BitsAndDroidsFlightConnector::sendAPPanelAltitudeSet(){return valSendAPPanelAltitudeSet;}
int BitsAndDroidsFlightConnector::sendAPPanelHeadingOn(){return valSendAPPanelHeadingOn;}
int BitsAndDroidsFlightConnector::sendAPPanelHeadingOff(){return valSendAPPanelHeadingOff;}
int BitsAndDroidsFlightConnector::sendAPPanelHeadingSet(){return valSendAPPanelHeadingSet;}
int BitsAndDroidsFlightConnector::sendAPPanelMachOn(){return valSendAPPanelMachOn;}
int BitsAndDroidsFlightConnector::sendAPPanelMachOff(){return valSendAPPanelMachOff;}
int BitsAndDroidsFlightConnector::sendAPPanelMachSet(){return valSendAPPanelMachSet;}
int BitsAndDroidsFlightConnector::sendAPPanelSpeedOn(){return valSendAPPanelSpeedOn;}
int BitsAndDroidsFlightConnector::sendAPPanelSpeedOff(){return valSendAPPanelSpeedOff;}
int BitsAndDroidsFlightConnector::sendAPPanelSpeedSet(){return valSendAPPanelSpeedSet;}
int BitsAndDroidsFlightConnector::sendAPPanelAltVarSetEnglish(){return valSendAPPanelAltVarSetEnglish;}
int BitsAndDroidsFlightConnector::sendAPVSVarSetMetric(){return valSendAPVSVarSetMetric;}
int BitsAndDroidsFlightConnector::sendAPPanelSpeedHoldToggle(){return valSendAPPanelSpeedHoldToggle;}
int BitsAndDroidsFlightConnector::sendAPPanelMachHoldToggle(){return valSendAPPanelMachHoldToggle;}
int BitsAndDroidsFlightConnector::sendAPNavSelectSet(){return valSendAPNavSelectSet;}
int BitsAndDroidsFlightConnector::sendAPPitchRefIncUp(){return valSendAPPitchRefIncUp;}
int BitsAndDroidsFlightConnector::sendAPPitchRefIncDown(){return valSendAPPitchRefIncDown;}
int BitsAndDroidsFlightConnector::sendAPPitchRefSelect(){return valSendAPPitchRefSelect;}
int BitsAndDroidsFlightConnector::sendAPAttitudeHold(){return valSendAPAttitudeHold;}
int BitsAndDroidsFlightConnector::sendAPLocHold(){return valSendAPLocHold;}
int BitsAndDroidsFlightConnector::sendAPAprHold(){return valSendAPAprHold;}
int BitsAndDroidsFlightConnector::sendAPHeadingHold(){return valSendAPHeadingHold;}
int BitsAndDroidsFlightConnector::sendAPAltitudeHold(){return valSendAPAltitudeHold;}
int BitsAndDroidsFlightConnector::sendAPWingLeveler(){return valSendAPWingLeveler;}
int BitsAndDroidsFlightConnector::sendAPBCHold(){return valSendAPBCHold;}
int BitsAndDroidsFlightConnector::sendAPNav1Hold(){return valSendAPNav1Hold;}
int BitsAndDroidsFlightConnector::sendHeadingBugInc(){return valSendHeadingBugInc;}
int BitsAndDroidsFlightConnector::sendHeadingBugDec(){return valSendHeadingBugDec;}
int BitsAndDroidsFlightConnector::sendAPFlightDirector(){return valSendAPFlightDirector;}
int BitsAndDroidsFlightConnector::sendAPVSHold(){return valSendAPVSHold;}
int BitsAndDroidsFlightConnector::sendKohlsmanInc(){return valSendKohlsmanInc;}
int BitsAndDroidsFlightConnector::sendKohlsmanDec(){return valSendKohlsmanDec;}
//Coms
int BitsAndDroidsFlightConnector::sendMhzComStandby1Plus(){return valSendMhzComStandby1Plus;}
int BitsAndDroidsFlightConnector::sendMhzComStandby1Min(){ return valSendMhzComStandby1Min;}
int BitsAndDroidsFlightConnector::sendKhzComStandby1Plus(){ return valSendKhzComStandby1Plus;}
int BitsAndDroidsFlightConnector::sendKhzComStandby1Min(){ return valSendKhzComStandby1Min;}

int BitsAndDroidsFlightConnector::sendMhzComStandby2Plus(){ return valSendMhzComStandby2Plus;}
int BitsAndDroidsFlightConnector::sendMhzComStandby2Min(){ return valSendMhzComStandby2Min;}
int BitsAndDroidsFlightConnector::sendKhzComStandby2Plus(){ return valSendKhzComStandby2Plus;}
int BitsAndDroidsFlightConnector::sendKhzComStandby2Min() {return valSendKhzComStandby2Min;}

int BitsAndDroidsFlightConnector::sendSwapCom1 (){return valSendSwapCom1;}
int BitsAndDroidsFlightConnector::sendSwapCom2 (){return valSendSwapCom2;}

int BitsAndDroidsFlightConnector::sendCom1FractInc(){return valSendCom1FractInc;}
int BitsAndDroidsFlightConnector::sendCom1FractIncCarry(){return valSendCom1FractIncCarry;}
int BitsAndDroidsFlightConnector::sendCom1FractDecr(){return valSendCom1FractDecr;}
int BitsAndDroidsFlightConnector::sendCom1FractDecrCarry(){return valSendCom1FractDecrCarry;}

int BitsAndDroidsFlightConnector::sendCom2FractInc(){return valSendCom2FractInc;}
int BitsAndDroidsFlightConnector::sendCom2FractIncCarry(){return valSendCom2FractIncCarry;}
int BitsAndDroidsFlightConnector::sendCom2FractDecr(){return valSendCom2FractDecr;}
int BitsAndDroidsFlightConnector::sendCom2FractDecrCarry(){return valSendCom2FractDecrCarry;}

//Nav
int BitsAndDroidsFlightConnector::sendMhzNavStandby1Plus(){return valSendMhzNavStandby1Plus;}
int BitsAndDroidsFlightConnector::sendMhzNavStandby1Min(){return valSendMhzNavStandby1Min;}
int BitsAndDroidsFlightConnector::sendKhzNavStandby1Plus(){return valSendKhzNavStandby1Plus;}
int BitsAndDroidsFlightConnector::sendKhzNavStandby1Min(){return valSendKhzNavStandby1Min;}

int BitsAndDroidsFlightConnector::sendMhzNavStandby2Plus(){return valSendMhzNavStandby2Plus;}
int BitsAndDroidsFlightConnector::sendMhzNavStandby2Min(){return valSendMhzNavStandby2Min;}
int BitsAndDroidsFlightConnector::sendKhzNavStandby2Plus(){return valSendKhzNavStandby2Plus;}
int BitsAndDroidsFlightConnector::sendKhzNavStandby2Min(){return valSendKhzNavStandby2Min;}

int BitsAndDroidsFlightConnector::sendIncWholeNav1(){return valSendIncWholeNav1;}
int BitsAndDroidsFlightConnector::sendDecWholeNav1(){return valSendDecWholeNav1;}
int BitsAndDroidsFlightConnector::sendIncWholeNav2(){return valSendIncWholeNav2;}
int BitsAndDroidsFlightConnector::sendDecWholeNav2(){return valSendDecWholeNav2;}

int BitsAndDroidsFlightConnector::sendIncFractNav1(){return valSendIncFractNav1;}
int BitsAndDroidsFlightConnector::sendDecFractNav1(){return valSendDecFractNav1;}
int BitsAndDroidsFlightConnector::sendIncFractNav2(){return valSendIncFractNav2;}
int BitsAndDroidsFlightConnector::sendDecFractNav2(){return valSendDecFractNav2;}

int BitsAndDroidsFlightConnector::sendSwapNav1(){return valSendSwapNav1;}
int BitsAndDroidsFlightConnector::sendSwapNav2(){return valSendSwapNav2;}

//G1000
int BitsAndDroidsFlightConnector::sendG1000ZoomMapIn(){return valSendG1000ZoomMapIn;}
int BitsAndDroidsFlightConnector::sendG1000ZoomMapOut(){return valSendG1000ZoomMapOut;}
