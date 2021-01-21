/*
  Test.h - Test library for Wiring - description
  Copyright (c) 2006 John Doe.  All right reserved.
*/

// ensure this library description is only included once
#ifndef BitsAndDroidsFlightConnector_h
#define BitsAndDroidsFlightConnector_h


// library interface description
class BitsAndDroidsFlightConnector
{
  // user-accessible "public" interface
  public:
    BitsAndDroidsFlightConnector(bool isLeonardoMicro);
    void dataHandling();
    void simpleInputHandling(int throttlePin, float maxVal);
    void advancedInputHandling(int eng1Pin, int eng2Pin, int eng3Pin, int eng4Pin, int mixturePin, float maxVal);
    void superAdvancedInputHandling(int eng1Percentage, int eng2Percentage, int eng3Percentage, int eng4Percentage, int receivedMixturePercentage);
    int getPercentage(int value, float maxVal);

    //Ap
    String getApVerticalSpeed();
    String getApAltLock();

    //Avionics
    String getApHeadingLock();
    String getKohlmanAltimeter();
    String getBarPressure();
    String getFuelTotalPercentage();

    String getIndicatedAirspeed();
    String getIndicatedAltitude();
    String getIndicatedHeading();
    String getIndicatedGPSGroundspeed();
    String getTrueVerticalSpeed();
    int getLastPrefix();
    //lights
    bool getLightTaxiOn();
    bool getLightStrobeOn();
    bool getLightPanelOn();
    bool getLightRecognitionOn();
    bool getLightWingOn();
    bool getLightLogoOn();
    bool getLightCabinOn();
    bool getLightHeadOn();
    bool getLightBrakeOn();
    bool getLightNavOn();
    bool getLightBeaconOn();
    bool getLightLandingOn();
    //coms
    String getActiveCom1();
    String getActiveCom2();
    String getStandbyCom1();
    String getStandbyCom2();
    String getActiveNav1();
    String getActiveNav2();
    String getStandbyNav1();
    String getStandbyNav2();
    //warnings
    bool getStallWarningOn();
    bool getOverspeedWarningOn();
    //flaps
    String getFlapsHandlePct();
    String getFlapsHandleIndex();
    String getFlapsNumHandlePos();
    String getTrailingEdgeFlapsLeftPercent();
    String getTrailingEdgeFlapsRightPercent();
    String getTrailingEdgeFlapsLeftAngle();
    String getTrailingEdgeFlapsRightAngle();
    String getLeadingEdgeFlapsLeftPct();
    String getLeadingEdgeFlapsRightPct();
    String getLeadingEdgeFlapsLeftAngle();
    String getLeadingEdgeFlapsRightAngle();
    //Gears
    bool getGearHandlePos();
    String getGearHydraulicPressure();
    bool getTailWheelLock();
    String getGearCenterPositionPct();
    String getGearLeftPositionPct();
    String getGearRightPositionPct();
    String getGearTailPositionPct();
    String getGearAuxPosition();
    String getGearTotalPct();
    //Rudder/Trim

    String getAileronTrimPct();
    String getAileronTrimDegr();
    String getRudderTrimDegr();
    String getRudderTrimPct();
    String getElevatorTrimPos();
    String getElevatorTrimPct();

    //AP
    bool getAPAvailable();
    bool getAPMasterOn();
    bool getAPWingLevelerOn();
    bool getAPNav1LockOn();
    bool getAPHeadingLockOn();
    bool getAPAltitudeLockOn();
    bool getAPAttitudeLockOn();
    bool getAPGlideslopeHoldOn();
    bool getAPApproachHoldOn();
    bool getAPBackcourseHoldOn();
    bool getAPFlightDirectorOn();
    bool getAPAirspeedHoldOn();
    bool getAPMachHoldOn();
    bool getAPYawDampenerOn();
    bool getAPAutothrottleArm();
    bool getAPTakeoffPowerOn();
    bool getAPAutothrottleOn();
    bool getAPVerticalHoldOn();
    bool getAPRPMHoldOn();

    //Plane data
    String getPlaneName();


    //--------------------------------------------
    //TRANSMIT DATA
    //These values can be retrieved to assure user is not able to overwrite the data
    //These functions are mainly implemented to improve readability of your code
    // AP
    int sendApMasterOn();
    int sendApPanelHeadingLock();
    int sendAPPanelAltitudeHold();
    int sendAPAttitudeHoldOn();
    int sendAPLocHoldOn();
    int sendAPAprHoldOn();
    int sendAPHeadingHoldOn();
    int sendAltitudeHoldOn();
    int sendApWingLevelerOn();
    int sendBCHoldOn();
    int sendAPNav1HoldOn();
    int sendAPAttitudeHoldOff();
    int sendAPLocHoldOff();
    int sendAprHoldOff();
    int sendAPHeadingHoldOff();
    int sendAPAltitudeHoldOff();
    int sendWingLevelerOff();
    int sendAPBCHoldOff();
    int sendAPNav1HoldOff();
    int sendAPAirspeedHold();
    int sendAPPanelSpeedHold();
    int sendAPAltitudeInc();
    int sendAPAltitudeDec();
    int sendAPVSInc();
    int sendAPVSDec();
    int sendAPSpeedInc();
    int sendAPSpeedDec();
    int sendAPPanelMachHold();
    int sendAPMachInc();
    int sendAPMachDec();
    int sendAPMachHold();
    int sendAPAltitudeSetMetric();
    int sendAPVSSetEnglish();
    int sendAPSpeedSet();
    int sendAPMachVarSet();
    int sendAPAirspeedOn();
    int sendAPAirspeedOff();
    int sendAPAirspeedSet();
    int sendAPMachOn();
    int sendAPMachOff();
    int sendAPMachSet();
    int sendAPPanelAltitudeOn();
    int sendAPPanelAltitudeOff();
    int sendAPPanelAltitudeSet();
    int sendAPPanelHeadingOn();
    int sendAPPanelHeadingOff();
    int sendAPPanelHeadingSet();
    int sendAPPanelMachOn();
    int sendAPPanelMachOff();
    int sendAPPanelMachSet();
    int sendAPPanelSpeedOn();
    int sendAPPanelSpeedOff();
    int sendAPPanelSpeedSet();
    int sendAPPanelAltVarSetEnglish();
    int sendAPVSVarSetMetric();
    int sendAPPanelSpeedHoldToggle();
    int sendAPPanelMachHoldToggle();
    int sendAPNavSelectSet();
    int sendAPPitchRefIncUp();
    int sendAPPitchRefIncDown();
    int sendAPPitchRefSelect();
    int sendAPAttitudeHold();
    int sendAPLocHold();
    int sendAPAprHold();
    int sendAPHeadingHold();
    int sendAPAltitudeHold();
    int sendAPWingLeveler();
    int sendAPBCHold();
    int sendAPNav1Hold();
    int sendHeadingBugInc();
    int sendHeadingBugDec();
    int sendAPFlightDirector();
    int sendAPVSHold();

    int sendKohlsmanInc();
    int sendKohlsmanDec();



    //Coms
    int sendMhzComStandby1Plus();
    int sendMhzComStandby1Min();
    int sendKhzComStandby1Plus();
    int sendKhzComStandby1Min();

    int sendMhzComStandby2Plus();
    int sendMhzComStandby2Min();
    int sendKhzComStandby2Plus();
    int sendKhzComStandby2Min();

    int sendSwapCom1 ();
    int sendSwapCom2 ();


    int sendCom1FractInc();
    int sendCom1FractIncCarry();
    int sendCom1FractDecr();
    int sendCom1FractDecrCarry();



    int sendCom2FractInc();
    int sendCom2FractIncCarry();
    int sendCom2FractDecr();
    int sendCom2FractDecrCarry();




    //Nav
    int sendMhzNavStandby1Plus();
    int sendMhzNavStandby1Min();
    int sendKhzNavStandby1Plus();
    int sendKhzNavStandby1Min();

    int sendMhzNavStandby2Plus();
    int sendMhzNavStandby2Min();
    int sendKhzNavStandby2Plus();
    int sendKhzNavStandby2Min();

    int sendIncWholeNav1();
    int sendDecWholeNav1();
    int sendIncWholeNav2();
    int sendDecWholeNav2();

    int sendIncFractNav1();
    int sendDecFractNav1();
    int sendIncFractNav2();
    int sendDecFractNav2();


    int sendSwapNav1();
    int sendSwapNav2();

    //G1000
    int sendG1000ZoomMapIn();
    int sendG1000ZoomMapOut();
	
   

  // library-accessible "private" interface
  private:

    //--------------------------------------------
    //TRANSMIT DATA
    //These values can be ommited and printed to serial directly
    //They are mainly implemented to improve readability of your code

    //AP
    int valSendApMasterOn = 301;
    int valSendApPanelHeadingLock = 302;
    int valSendAPPanelAltitudeHold = 303;
    int valSendAPAttitudeHoldOn = 304;
    int valSendAPLocHoldOn = 305;
    int valSendAPAprHoldOn = 306;
    int valSendAPHeadingHoldOn = 307;
    int valSendAltitudeHoldOn = 308;
    int valSendApWingLevelerOn = 309;
    int valSendBCHoldOn = 310;
    int valSendAPNav1HoldOn = 311;
    int valSendAPAttitudeHoldOff = 312;
    int valSendAPLocHoldOff = 313;
    int valSendAprHoldOff = 314;
    int valSendAPHeadingHoldOff = 315;
    int valSendAPAltitudeHoldOff = 316;
    int valSendWingLevelerOff = 317;
    int valSendAPBCHoldOff = 318;
    int valSendAPNav1HoldOff = 319;
    int valSendAPAirspeedHold = 320;
    int valSendAPPanelSpeedHold = 321;
    int valSendAPAltitudeInc = 322;
    int valSendAPAltitudeDec = 323;
    int valSendAPVSInc = 324;
    int valSendAPVSDec = 325;
    int valSendAPSpeedInc = 326;
    int valSendAPSpeedDec = 327;
    int valSendAPPanelMachHold = 328;
    int valSendAPMachInc = 329;
    int valSendAPMachDec = 330;
    int valSendAPMachHold = 331;
    int valSendAPAltitudeSetMetric = 332;
    int valSendAPVSSetEnglish = 333;
    int valSendAPSpeedSet = 334;
    int valSendAPMachVarSet = 335;
    int valSendAPAirspeedOn = 336;
    int valSendAPAirspeedOff = 337;
    int valSendAPAirspeedSet = 338;
    int valSendAPMachOn = 339;
    int valSendAPMachOff = 340;
    int valSendAPMachSet = 341;
    int valSendAPPanelAltitudeOn = 342;
    int valSendAPPanelAltitudeOff = 343;
    int valSendAPPanelAltitudeSet = 345;
    int valSendAPPanelHeadingOn = 346;
    int valSendAPPanelHeadingOff = 347;
    int valSendAPPanelHeadingSet = 348;
    int valSendAPPanelMachOn = 349;
    int valSendAPPanelMachOff = 350;
    int valSendAPPanelMachSet = 351;
    int valSendAPPanelSpeedOn = 352;
    int valSendAPPanelSpeedOff = 353;
    int valSendAPPanelSpeedSet = 354;
    int valSendAPPanelAltVarSetEnglish = 355;
    int valSendAPVSVarSetMetric = 356;
    int valSendAPPanelSpeedHoldToggle = 357;
    int valSendAPPanelMachHoldToggle = 358;
    int valSendAPNavSelectSet = 359;
    int valSendAPPitchRefIncUp = 360;
    int valSendAPPitchRefIncDown = 361;
    int valSendAPPitchRefSelect = 362;
    int valSendAPAttitudeHold = 363;
    int valSendAPLocHold = 364;
    int valSendAPAprHold = 365;
    int valSendAPHeadingHold = 366;
    int valSendAPAltitudeHold = 367;
    int valSendAPWingLeveler = 368;
    int valSendAPBCHold = 369;
    int valSendAPNav1Hold = 370;
    int valSendHeadingBugInc = 371;
    int valSendHeadingBugDec = 372;
    int valSendAPFlightDirector = 373;
    int valSendAPVSHold = 374;
    int valSendKohlsmanInc = 375;
    int valSendKohlsmanDec = 376;
    //Coms
    int valSendMhzComStandby1Plus = 100;
    int valSendMhzComStandby1Min = 101;
    int valSendKhzComStandby1Plus = 102;
    int valSendKhzComStandby1Min = 103;

    int valSendCom1FractInc = 125;
    int valSendCom1FractIncCarry = 127;
    int valSendCom1FractDecr = 124;
    int valSendCom1FractDecrCarry = 126;

    int valSendCom2FractInc = 121;
    int valSendCom2FractIncCarry = 123;
    int valSendCom2FractDecr = 120;
    int valSendCom2FractDecrCarry = 122;

    int valSendMhzComStandby2Plus = 104;
    int valSendMhzComStandby2Min = 105;
    int valSendKhzComStandby2Plus = 106;
    int valSendKhzComStandby2Min = 107;

    int valSendSwapCom1 = 116;
    int valSendSwapCom2 = 117;

    //Nav
    int valSendMhzNavStandby1Plus = 108;
    int valSendMhzNavStandby1Min = 109;
    int valSendKhzNavStandby1Plus = 110;
    int valSendKhzNavStandby1Min = 111;

    int valSendMhzNavStandby2Plus = 112;
    int valSendMhzNavStandby2Min = 113;
    int valSendKhzNavStandby2Plus = 114;
    int valSendKhzNavStandby2Min = 115;

    int valSendIncWholeNav1 = 132;
    int valSendDecWholeNav1 = 133;
    int valSendIncWholeNav2 = 134;
    int valSendDecWholeNav2 = 135;

    int valSendIncFractNav1 = 128;
    int valSendDecFractNav1 = 129;
    int valSendIncFractNav2 = 130;
    int valSendDecFractNav2 = 131;

    int valSendSwapNav1 = 118;
    int valSendSwapNav2 = 119;

    //G1000
    int valSendG1000ZoomMapIn = 200;
    int valSendG1000ZoomMapOut = 201;

    int lastPrefix =0;

    String inputText;  
    String convertToFreq(String unprocVal);
    String convertToNavFreq(String unprocVal);
    String inhg(String unprocInhg);

    String apVerticalSpeed = "";
    String kohlmanAltimeter = "";
    String barPressure = "";
    String apAltLock = "";
    String apHeadingLock = "";

    String indicatedAirspeed = "";
    String indicatedAltitude = "";
    String indicatedHeading = "";
    String indicatedGPSGroundspeed = "";
    String trueVerticalSpeed = "";

    //lights
    bool lightTaxiOn = false;
    bool lightStrobeOn = false;
    bool lightPanelOn = false;
    bool lightRecognitionOn = false;
    bool lightWingOn = false;
    bool lightLogoOn = false;
    bool lightCabinOn = false;
    bool lightHeadOn = false;
    bool lightBrakeOn = false;
    bool lightNavOn = false;
    bool lightBeaconOn = false;
    bool lightLandingOn = false;

    //AP
    bool APAvailable = false;
    bool APMasterOn = false;
    bool APWingLevelerOn = false;
    bool APNav1LockOn = false;
    bool APHeadingLockOn = false;
    bool APAltitudeLockOn = false;
    bool APAttitudeLockOn = false;
    bool APGlideslopeHoldOn = false;
    bool APApproachHoldOn = false;
    bool APBackcourseHoldOn = false;
    bool APFlightDirectorOn = false;
    bool APAirspeedHoldOn = false;
    bool APMachHoldOn = false;
    bool APYawDampenerOn = false;
    bool APAutothrottleArm = false;
    bool APTakeoffPowerOn = false;
    bool APAutothrottleOn = false;
    bool APVerticalHoldOn = false;
    bool APRPMHoldOn = false;

    //warnings
    bool stallWarning = false;
    bool overspeedWarning = false;

    String fuelTotalPercentage = "";

    char valuesBuffer[40];
	
    bool advanced;
    int engine1 = 0;
    int engine2 = 0;
    int engine3 = 0;
    int engine4 = 0;
    int mixturePercentage = 0;
    
    int engines[4] = { 0,0,0,0 };

    int value;
    int oldValue;

    int valueEng1;
    int valueEng2;
    int valueEng3;
    int valueEng4;

    int oldValueEng1;
    int oldValueEng2;
    int oldValueEng3;
    int oldValueEng4;

    int mixtureValue;
    int oldMixtureValue;

    int packagedData;
    void sendCombinedValues();
    //Coms
    String activeCom1 = "";
    String activeCom2 = "";
    String standByCom1 = "";
    String standByCom2 = "";
    String activeNav1 = "";
    String activeNav2 = "";
    String standbyNav1 = "";
    String standbyNav2 = "";

    //Flaps
    String flapsHandlePct = "";
    String flapsHandleIndex = "";
    String flapsNumHandlePos = "";
    String trailingEdgeFlapsLeftPercent = "";
    String trailingEdgeFlapsRightPercent = "";
    String trailingEdgeFlapsLeftAngle = "";
    String trailingEdgeFlapsRightAngle = "";
    String leadingEdgeFlapsLeftPct = "";
    String leadingEdgeFlapsRightPct = "";
    String leadingEdgeFlapsLeftAngle = "";
    String leadingEdgeFlapsRightAngle = "";


    //Gears
    bool gearHandlePos = false;
    String gearHydraulicPressure = "";
    bool tailWheelLock = false;
    String gearCenterPositionPct = "";
    String gearLeftPositionPct = "";
    String gearRightPositionPct = "";
    String gearTailPositionPct = "";
    String gearAuxPosition = "";
    String gearTotalPct = "";

    //Rudder/trim
    String aileronTrimPct = "";
    String aileronTrimDegr = "";
    String rudderTrimDegr = "";
    String rudderTrimPct = "";
    String elevatorTrimPos = "";
    String elevatorTrimPct = "";

    //Plane data
    String planeName = "";

};

#endif
