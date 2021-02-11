
#ifndef BitsAndDroidsFlightConnector_h
#define BitsAndDroidsFlightConnector_h

// library interface description
class BitsAndDroidsFlightConnector {
  // user-accessible "public" interface
 public:
  BitsAndDroidsFlightConnector(bool isLeonardoMicro);
  void switchHandling();
  void dataHandling();
  void simpleInputHandling(int throttlePin, float maxVal);
  void advancedInputHandling(int eng1Pin, int eng2Pin, int eng3Pin, int eng4Pin,
                             int mixturePin, float maxVal);
  void superAdvancedInputHandling(byte eng1Percentage, byte eng2Percentage,
                                  byte eng3Percentage, byte eng4Percentage,
                                  byte receivedMixturePercentage);
  void propsInputHandling(int propPin1, int propPin2, float maxVal);
  void setTeensy(bool);
  void setEMA_a(float a);
  byte getPercentage(int value, float maxVal);

  // Ap
  String getApVerticalSpeed();
  String getApAltLock();

  // GPS
  String getGpsCourseToSteer();

  // Avionics
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

  // Lights
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

  // Coms
  String getActiveCom1();
  String getActiveCom2();
  String getStandbyCom1();
  String getStandbyCom2();
  String getActiveNav1();
  String getActiveNav2();
  String getStandbyNav1();
  String getStandbyNav2();
  String getNavRadialError1();
  String getNavVorLationalt1();

  // Warnings
  bool getStallWarningOn();
  bool getOverspeedWarningOn();

  // flaps
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

  // Gears
  bool getGearHandlePos();
  String getGearHydraulicPressure();
  bool getTailWheelLock();
  String getGearCenterPositionPct();
  String getGearLeftPositionPct();
  String getGearRightPositionPct();
  String getGearTailPositionPct();
  String getGearAuxPosition();
  String getGearTotalPct();

  // Rudder/Trim
  String getAileronTrimPct();
  String getAileronTrimDegr();
  String getRudderTrimDegr();
  String getRudderTrimPct();
  String getElevatorTrimPos();
  String getElevatorTrimPct();

  // DME
  String getNavDme1();
  String getNavDme2();
  String getNavDmeSpeed1();
  String getNavDmeSpeed2();

  // ADF
  String getAdfActiveFreq1();
  String getAdfStandbyFreq1();
  String getAdfRadial1();
  String getAdfSignal1();
  String getAdfActiveFreq2();
  String getAdfStandbyFreq2();
  String getAdfRadial2();
  String getAdfSignal2();

  // Transponder
  String getTransponderCode1();
  String getTransponderCode2();

  // AP
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

  // Plane data
  String getPlaneName();

  //--------------------------------------------
  // TRANSMIT DATA
  // These values can be retrieved to assure user is not able to overwrite the
  // data These functions are mainly implemented to improve readability of your
  // code
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

  //Flaps
  int sendFlapsUp();
  int sendFlaps1();
  int sendFlaps2();
  int sendFlaps3();
  int sendFlapsDown();
  int sendFlapsInc();
  int sendFlapsDec();

  // Coms
  String sendStandbyCom1Set(char*);
  String sendStandbyCom2Set(char* value);

  byte sendSwapCom1();
  byte sendSwapCom2();

  byte sendCom1FractInc();
  byte sendCom1FractIncCarry();
  byte sendCom1FractDecr();
  byte sendCom1FractDecrCarry();

  byte sendCom2FractInc();
  byte sendCom2FractIncCarry();
  byte sendCom2FractDecr();
  byte sendCom2FractDecrCarry();

  byte sendCom1WholeInc();
  byte sendCom1WholeDec();
  byte sendCom2WholeInc();
  byte sendCom2WholeDec();


  // Nav
  byte sendMhzNavStandby1Plus();
  byte sendMhzNavStandby1Min();
  byte sendKhzNavStandby1Plus();
  byte sendKhzNavStandby1Min();

  byte sendMhzNavStandby2Plus();
  byte sendMhzNavStandby2Min();
  byte sendKhzNavStandby2Plus();
  byte sendKhzNavStandby2Min();

  byte sendIncWholeNav1();
  byte sendDecWholeNav1();

  byte sendIncWholeNav2();
  byte sendDecWholeNav2();

  byte sendIncFractNav1();
  byte sendDecFractNav1();

  byte sendIncFractNav2();
  byte sendDecFractNav2();

  byte sendSwapNav1();
  byte sendSwapNav2();

  //DME

  byte sendSelectedDme1IdentEnable();
  byte sendSeletedDme1IdentDisable ();
  byte sendSelectedDme1IdentSet ();
  byte sendSelectedDme1IdentToggle ();
  byte sendSelectedDme2IdentEnable ();
  byte sendSelectedDme2IdentDisable();
  byte sendSelectedDme2IdentSet();
  byte sendSelectedDme2IdentToggle();
  byte sendDmeToggle();

  //VOR

  byte sendSelectedVor1IdentEnable();
  byte sendSelectedVor1IdentDisable();
  byte sendSelectedVor1IdentSet();
  byte sendVor1IdentToggle();
  byte sendVor2IdentEnable();
  byte sendVor2IdentDisable();
  byte sendVor2IdentSet();
  byte sendVor2IdentToggle();
  byte sendVorToggle();
  byte sendVor1ObiDec();
  byte sendVor1ObiInc();
  byte sendVor2ObiDec();
  byte sendVor2ObiInc();

  //ADF

  byte sendSelectedAdfIdentEnable();
  byte sendSelectedAdfIdentDisable();
  byte sendSelecetedAdfIdentSet();
  byte sendSelectedAdfIdentToggle();
  byte sendAdfCardIn();
  byte sendAdfCardDec();
  byte sendAdfCardSet();
  byte sendAdf100Inc();
  byte sendAdf10Inc();
  byte sendAdf1Inc();
  byte sendAdf100Dec();
  byte sendAdf10Dec();
  byte sendAdf1Dec();
  byte sendAdfCompleteSet();
  byte sendAdf1WholeInc();
  byte sendAdf1WholeDec();
  byte sendAdf2100Inc();
  byte sendAdf210Inc();
  byte sendAdf21Inc();
  byte sendAdf2RadioThenthsInc();
  byte sendAdf2100Dec();
  byte sendAdf210Dec();
  byte sendAdf21Dec();
  byte sendAdf2RadioThenthsDec();
  byte sendAdf2WholeInc();
  byte sendAdf2WholeDec();
  byte sendAdf2FractDecCarry();
  byte sendAdf2FractIncCarry();
  byte sendAdf2CompleteSet();
  byte sendAdf2IdentDisable();
  byte sendAdf2IdentEnable();
  byte sendAdf2IdentToggle();
  byte sendAdf2IdentSet();
  byte sendAdfCardInc();

  //XPNDR
  byte sendXpndr1000Inc();
  byte sendXpndr100Inc();
  byte sendXpndr10Inc();
  byte sendXpndr1Inc();
  byte sendXpndr1000Dec();
  byte sendXpndr100Dec();
  byte sendXpndr10Dec();
  byte sendXpndr1Dec();
  String sendXpndrSet(char*);

  //Avionics
  int sendAvionicsMaster1On();
  int sendAvionicsMaster1Off();
  int sendAvionicsMaster2On();
  int sendAvionicsMaster2Off();
  int sendParkingBrake();

  //Battery
  int sendToggleMasterBattery1 ();
  int sendToggleMasterBattery2();
  int sendToggleExternalPower();

  int sendToggleMasterAlternator();





  // G1000
  byte sendG1000ZoomMapIn();
  byte sendG1000ZoomMapOut();

  // library-accessible "private" interface

 private:
  //--------------------------------------------
  // TRANSMIT DATA
  // These values can be ommited and printed to serial directly
  // They are mainly implemented to improve readability of your code


  // Avionics
  int valSendAvionicsMaster1On = 401;
  int valSendAvionicsMaster1Off = 402;
  int valSendAvionicsMaster2On = 403;
  int valSendAvionicsMaster2Off = 404;
  int valSendParkingBrake = 420;

  //Battery
  int valSendToggleMasterBattery1 = 405;
  int valSendToggleMasterBattery2= 406;
  int valSendToggleExternalPower = 408;

  int valSendToggleMasterAlternator = 407;


  //Xpndr
  byte valSendXpndr1000Inc = 171;
  byte valSendXpndr100Inc = 172;
  byte valSendXpndr10Inc = 173;
  byte valSendXpndr1Inc = 174;
  byte valSendXpndr1000Dec = 175;
  byte valSendXpndr100Dec = 176;
  byte valSendXpndr10Dec = 177;
  byte valSendXpndr1Dec = 178;
  //String valSendXpndrSet = "202";

  //Adf
  byte valSendSelectedAdfIdentEnable = 158;
  byte valSendSelectedAdfIdentDisable = 159;
  byte valSendSelecetedAdfIdentSet = 160;
  byte valSendSelectedAdfIdentToggle = 161;
  byte valSendAdfCardInc = 162;
  byte valSendAdfCardDec = 163;
  byte valSendAdfCardSet = 164;
  byte valSendAdf100Inc = 165;
  byte valSendAdf10Inc = 166;
  byte valSendAdf1Inc = 167;
  byte valSendAdf100Dec = 168;
  byte valSendAdf10Dec = 169;
  byte valSendAdf1Dec = 170;
  byte valSendAdfCompleteSet = 179;
  byte valSendAdf1WholeInc = 180;
  byte valSendAdf1WholeDec = 181;
  byte valSendAdf2100Inc = 182;
  byte valSendAdf210Inc = 183;
  byte valSendAdf21Inc = 184;
  byte valSendAdf2RadioThenthsInc = 185;
  byte valSendAdf2100Dec = 186;
  byte valSendAdf210Dec = 187;
  byte valSendAdf21Dec = 188;
  byte valSendAdf2RadioThenthsDec= 189;
  byte valSendAdf2WholeInc = 190;
  byte valSendAdf2WholeDec = 191;
  byte valSendAdf2FractDecCarry = 192;
  byte valSendAdf2FractIncCarry = 193;
  byte valSendAdf2CompleteSet = 194;
  byte valSendAdf2IdentDisable = 195;
  byte valSendAdf2IdentEnable = 196;
  byte valSendAdf2IdentToggle = 197;
  byte valSendAdf2IdentSet = 200;

  //VOR
  byte valSendSelectedVor1IdentEnable = 145;
  byte valSendSelectedVor1IdentDisable = 146;
  byte valSendSelectedVor1IdentSet = 147;
  byte valSendVor1IdentToggle = 148;
  byte valSendVor2IdentEnable = 149;
  byte valSendVor2IdentDisable = 150;
  byte valSendVor2IdentSet = 151;
  byte valSendVor2IdentToggle = 152;
  byte valSendVorToggle = 153;
  byte valSendVor1ObiDec = 154;
  byte valSendVor1ObiInc = 155;
  byte valSendVor2ObiDec = 156;
  byte valSendVor2ObiInc = 157;

  //DME
  byte valSendSelectedDme1IdentEnable = 136;
  byte valSendSeletedDme1IdentDisable = 137;
  byte valSendSelectedDme1IdentSet = 138;
  byte valSendSelectedDme1IdentToggle = 139;
  byte valSendSelectedDme2IdentEnable = 140;
  byte valSendSelectedDme2IdentDisable = 141;
  byte valSendSelectedDme2IdentSet = 142;
  byte valSendSelectedDme2IdentToggle = 143;
  byte valSendDmeToggle = 144;


  // AP
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
  int autoThrottleArm = 378;
  int autoThrottleArmToGa = 379;


  // Coms
  String valSendStandbyCom1Set = "100";
  String valSendStandbyCom2Set = "101";

  byte valSendCom1FractInc = 125;
  byte valSendCom1FractIncCarry = 127;
  byte valSendCom1FractDecr = 124;
  byte valSendCom1FractDecrCarry = 126;

  byte valSendCom2FractInc = 121;
  byte valSendCom2FractIncCarry = 123;
  byte valSendCom2FractDecr = 120;
  byte valSendCom2FractDecrCarry = 122;

  byte valSendCom1WholeDec = 111;
  byte valSendCom1WholeInc = 112;
  byte valSendCom2WholeDec = 113;
  byte valSendCom2WholeInc = 114;

  byte valSendSwapCom1 = 116;
  byte valSendSwapCom2 = 117;

  // Xpndr
  String valSendXpndrSet = "202";

  // Nav
  byte valSendIncWholeNav1 = 132;
  byte valSendDecWholeNav1 = 133;
  byte valSendIncWholeNav2 = 134;
  byte valSendDecWholeNav2 = 135;

  byte valSendIncFractNav1 = 128;
  byte valSendDecFractNav1 = 129;
  byte valSendIncFractNav2 = 130;
  byte valSendDecFractNav2 = 131;

  byte valSendSwapNav1 = 118;
  byte valSendSwapNav2 = 119;

  // G1000
  byte valSendG1000ZoomMapIn = 250;
  byte valSendG1000ZoomMapOut = 251;



  byte lastPrefix = 0;

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

  // lights
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

  // AP
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

  // warnings
  bool stallWarning = false;
  bool overspeedWarning = false;

  String fuelTotalPercentage = "";

  char valuesBuffer[40];

  bool advanced;
  byte engine1 = 0;
  byte engine2 = 0;
  byte engine3 = 0;
  byte engine4 = 0;

  byte prop1 = 0;
  byte prop2 = 0;
  int mixturePercentage = 0;

  byte engines[4] = {0, 0, 0, 0};
  byte props[2] = {0, 0};

  int value;
  int propValue1;
  int propValue2;
  int oldValue;

  int oldPropValue1;
  int oldPropValue2;

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
  void sendCombinedThrottleValues();
  void sendCombinedPropValues();

  // Coms
  String activeCom1 = "";
  String activeCom2 = "";
  String standByCom1 = "";
  String standByCom2 = "";
  String activeNav1 = "";
  String activeNav2 = "";
  String standbyNav1 = "";
  String standbyNav2 = "";
  String navRadialError1 = "";
  String navVorLationalt1 = "";

  // GPS
  String gpsCourseToSteer = "";

  // DME
  String navDme1 = "";
  String navDme2 = "";
  String navDmeSpeed1 = "";
  String navDmeSpeed2 = "";

  // ADF
  String adfActiveFreq1 = "";
  String adfStandbyFreq1 = "";
  String adfRadial1 = "";
  String adfSignal1 = "";
  String adfActiveFreq2 = "";
  String adfStandbyFreq2 = "";
  String adfRadial2 = "";
  String adfSignal2 = "";

  // Transponder
  String transponderCode1 = "";
  String transponderCode2 = "";

  // Flaps
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

  // Gears
  bool gearHandlePos = false;
  String gearHydraulicPressure = "";
  bool tailWheelLock = false;
  String gearCenterPositionPct = "";
  String gearLeftPositionPct = "";
  String gearRightPositionPct = "";
  String gearTailPositionPct = "";
  String gearAuxPosition = "";
  String gearTotalPct = "";

  // Rudder/trim
  String aileronTrimPct = "";
  String aileronTrimDegr = "";
  String rudderTrimDegr = "";
  String rudderTrimPct = "";
  String elevatorTrimPos = "";
  String elevatorTrimPct = "";

  //Flaps
  int valSendFlapsUp = 501;
  int valSendFlaps1 = 502;
  int valSendFlaps2 = 503;
  int valSendFlaps3 = 504;
  int valSendFlapsDown = 505;
  int valSendFlapsInc = 506;
  int valSendFlapsDec = 507;



  // Plane data
  String planeName = "";
  String receivedValue;
  String prefix = "";
  String cutValue = "";
  bool isTeensy = false;
  float EMA_a = 0.1;
  int EMA_S = 0;
};

#endif
