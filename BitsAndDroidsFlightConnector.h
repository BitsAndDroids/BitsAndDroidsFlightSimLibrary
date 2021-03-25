#ifndef BitsAndDroidsFlightConnector_h
#define BitsAndDroidsFlightConnector_h

#ifndef ARDUINO_SAM_DUE
#include "SoftwareSerial.h"
#endif

// library interface description
class BitsAndDroidsFlightConnector {
  // user-accessible "public" interface
 public:
  BitsAndDroidsFlightConnector(bool isLeonardoMicro);
  BitsAndDroidsFlightConnector(bool isLeonardoMicro, HardwareSerial* serial);
  #ifndef ARDUINO_SAM_DUE
  BitsAndDroidsFlightConnector(bool isLeonardoMicro, SoftwareSerial* serial);
  #else
  BitsAndDroidsFlightConnector(bool isLeonardoMicro, Serial_* serial);
  #endif

  void switchHandling();
  void dataHandling();
  void simpleInputHandling(int throttlePin,int minVal, float maxVal, bool reversed);
  void advancedInputHandling(int eng1Pin, int eng2Pin, int eng3Pin, int eng4Pin,
                            int minVal, float maxVal, bool reversed);
  void superAdvancedInputHandling(byte eng1Percentage, byte eng2Percentage, byte eng3Percentage, byte eng4Percentage);
  void sendCombinedMixtureValues();
  void propsInputHandling(int propPin1, int propPin2, int minVal, float maxVal, bool reversed);
  void mixtureInputHandling(int mixturePin1, int mixturePin2, int minVal,float maxVal, bool reversed);
  void sendSetElevatorTrim(int value);
  void sendSetBrakePot(byte leftPin, byte rightPin,int minVal, int maxVal);
  void sendSetRudderPot(byte rudderPin,int minVal, int maxVal);
  void sendSetElevatorTrimPot(byte potPin, int minVal, int maxVal);
  void setEMA_a(float a);
  byte getPercentage(int value, int minVal, float maxVal);

  //Data
  int feetAboveGround = 0;
  int getFeetAboveGround(){return feetAboveGround;};

  bool onGround = true;
  bool getOnGround(){return onGround;};
  // Ap
  int getApVerticalSpeed(){return apVerticalSpeed;};
  int getApAltLock(){return apAltLock;};

  // GPS
  int getGpsCourseToSteer(){return gpsCourseToSteer;};

  // Avionics
  int getApHeadingLock(){return apHeadingLock;};
  int getKohlmanAltimeter(){return kohlmanAltimeter;};
  int getBarPressure(){return barPressure;};
  byte getFuelTotalPercentage(){return fuelTotalPercentage;};

  int getIndicatedAirspeed(){return indicatedAirspeed;};
  int getIndicatedAltitude(){return indicatedAltitude;};
  int getIndicatedHeading(){return indicatedHeading;};
  int getIndicatedGPSGroundspeed(){return indicatedGPSGroundspeed;};
  int getTrueVerticalSpeed(){return trueVerticalSpeed;};
  int getLastPrefix();

  // Lights
  bool getLightTaxiOn(){return lightTaxiOn;};
  bool getLightStrobeOn(){return lightStrobeOn;};
  bool getLightPanelOn(){return lightPanelOn;};
  bool getLightRecognitionOn(){return lightRecognitionOn;};
  bool getLightWingOn(){return lightWingOn;};
  bool getLightLogoOn(){return lightLogoOn;};
  bool getLightCabinOn(){return lightCabinOn;};
  bool getLightHeadOn(){return lightHeadOn;};
  bool getLightBrakeOn(){return lightBrakeOn;};
  bool getLightNavOn(){return lightNavOn;};
  bool getLightBeaconOn(){return lightBeaconOn;};
  bool getLightLandingOn(){return lightLandingOn;};

  // Coms
  String getActiveCom1(){return activeCom1;};
  String getActiveCom2(){return activeCom2;};
  String getStandbyCom1(){return standByCom1;};
  String getStandbyCom2(){return standByCom2;};
  String getActiveNav1(){return activeNav1;};
  String getActiveNav2(){return activeNav2;};
  String getStandbyNav1(){return standbyNav1;};
  String getStandbyNav2(){return standbyNav2;};
  String getNavRadialError1(){return navRadialError1;};
  String getNavVorLationalt1(){return navVorLationalt1;};

  int getNavObs1(){return navObs1;};
  int getNavObs2(){return navObs2;};

  // Warnings
  bool getStallWarningOn(){return stallWarning;};
  bool getOverspeedWarningOn(){return overspeedWarning;};


  // flaps
  byte getFlapsHandlePct(){return flapsHandlePct;};
  byte getFlapsHandleIndex(){return flapsHandleIndex;};
  byte getFlapsNumHandlePos(){return flapsNumHandlePos;};
  byte getTrailingEdgeFlapsLeftPercent(){return trailingEdgeFlapsLeftPercent;};
  byte getTrailingEdgeFlapsRightPercent(){return trailingEdgeFlapsRightPercent;};
  int getTrailingEdgeFlapsLeftAngle(){return trailingEdgeFlapsLeftAngle;};
  int getTrailingEdgeFlapsRightAngle(){return trailingEdgeFlapsRightAngle;};
  byte getLeadingEdgeFlapsLeftPct(){return leadingEdgeFlapsLeftPct;};
  byte getLeadingEdgeFlapsRightPct(){return leadingEdgeFlapsRightPct;};
  int getLeadingEdgeFlapsLeftAngle(){return leadingEdgeFlapsLeftAngle;};
  int getLeadingEdgeFlapsRightAngle(){return leadingEdgeFlapsRightAngle;};

  // Gears
  bool getGearHandlePos(){return gearHandlePos;};
  int getGearHydraulicPressure(){return gearHydraulicPressure;};
  bool getTailWheelLock(){return tailWheelLock;};
  byte getGearCenterPositionPct(){return gearCenterPositionPct;};
  byte getGearLeftPositionPct(){return gearLeftPositionPct;};
  byte getGearRightPositionPct(){return gearRightPositionPct;};
  byte getGearTailPositionPct(){return gearTailPositionPct;};
  byte getGearAuxPosition(){return gearAuxPosition;};
  byte getGearTotalPct(){return gearTotalPct;};

  // Rudder/Trim
  int getAileronTrimPct(){return aileronTrimPct;};
  int getAileronTrimDegr(){return aileronTrimDegr;};
  int getRudderTrimDegr(){return rudderTrimDegr;};
  int getRudderTrimPct(){return rudderTrimPct;};
  int getElevatorTrimPos(){return elevatorTrimPos;};
  int getElevatorTrimPct(){return elevatorTrimPct;};

  // DME
  String getNavDme1(){return navDme1;};
  String getNavDme2(){return navDme2;};
  String getNavDmeSpeed1(){return navDmeSpeed1;};
  String getNavDmeSpeed2(){return navDmeSpeed2;};

  // ADF
  String getAdfActiveFreq1(){return adfActiveFreq1;};
  String getAdfStandbyFreq1(){return adfStandbyFreq1;};
  String getAdfRadial1(){return adfRadial1;};
  String getAdfSignal1(){return adfSignal1;};
  String getAdfActiveFreq2(){return adfActiveFreq2;};
  String getAdfStandbyFreq2(){return adfStandbyFreq2;};
  String getAdfRadial2(){return adfRadial2;};
  String getAdfSignal2(){return adfSignal2;};

  // Transponder
  String getTransponderCode1(){return transponderCode1;};
  String getTransponderCode2(){return transponderCode2;};

  // AP
  bool getAPAvailable(){return APAvailable;};
  bool getAPMasterOn(){return APMasterOn;};
  bool getAPWingLevelerOn(){return APWingLevelerOn;};
  bool getAPNav1LockOn(){return APNav1LockOn;};
  bool getAPHeadingLockOn(){return APHeadingLockOn;};
  bool getAPAltitudeLockOn(){return APAltitudeLockOn;};
  bool getAPAttitudeLockOn(){return APAttitudeLockOn;};
  bool getAPGlideslopeHoldOn(){return APGlideslopeHoldOn;};
  bool getAPApproachHoldOn(){return APApproachHoldOn;};
  bool getAPBackcourseHoldOn(){return APBackcourseHoldOn;};
  bool getAPFlightDirectorOn(){return APFlightDirectorOn;};
  bool getAPAirspeedHoldOn(){return APAirspeedHoldOn;};
  bool getAPMachHoldOn(){return APMachHoldOn;};
  bool getAPYawDampenerOn(){return APYawDampenerOn;};
  bool getAPAutothrottleArm(){return APAutothrottleArm;};
  bool getAPTakeoffPowerOn(){return APTakeoffPowerOn;};
  bool getAPAutothrottleOn(){return APAutothrottleOn;};
  bool getAPVerticalHoldOn(){return APVerticalHoldOn;};
  bool getAPRPMHoldOn(){return APRPMHoldOn;};

  // Plane data
  String getPlaneName(){return planeName;};

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

  int sendPitotHeatToggle(){return 508;};
  int sendPitotHeatOn(){return 509;};
  int sendPitotHeatOff(){return 510;};
  int sendMagneto(){return 511;};
  int sendMagnetoDecr(){return 512;};
  int sendMagnetoIncr(){return 513;};
  int sendMagneto1Off(){return 514;};
  int sendMagneto1Right(){return 515;};
  int sendMagneto1Left(){return 516;};
  int sendMagneto1Both(){return 517;};
  int sendMagneto1Start(){return 518;};
  int sendMagneto2Off(){return 519;};
  int sendMagneto2Right(){return 520;};
  int sendMagneto2Left(){return 521;};
  int sendMagneto2Both(){return 522;};
  int sendMagneto2Start(){return 523;};
  int sendMagneto3Off(){return 524;};
  int sendMagneto3Right(){return 525;};
  int sendMagneto3Left(){return 526;};
  int sendMagneto3Both(){return 527;};
  int sendMagneto3Start(){return 528;};
  int sendMagneto4Off(){return 529;};
  int sendMagneto4Right(){return 530;};
  int sendMagneto4Left(){return 531;};
  int sendMagneto4Both(){return 532;};
  int sendMagneto4Start(){return 533;};
  int sendMagnetoOff(){return 534;};
  int sendMagnetoRight(){return 535;};
  int sendMagnetoLeft(){return 536;};
  int sendMagnetoBoth(){return 537;};
  int sendMagnetoStart(){return 538;};
  int sendMagneto1Decr(){return 539;};
  int sendMagneto1Incr(){return 540;};
  int sendMagneto2Decr(){return 541;};
  int sendMagneto2Incr(){return 542;};
  int sendMagneto3Decr(){return 543;};
  int sendMagneto3Incr(){return 544;};
  int sendMagneto4Decr(){return 545;};
  int sendMagneto4Incr(){return 546;};
  int sendMagnetoSet(){return 547;};
  int sendMagneto1Set(){return 548;};
  int sendMagneto2Set(){return 549;};
  int sendMagneto3Set(){return 550;};
  int sendMagneto4Set(){return 551;};
  int sendAntiIceOn(){return 552;};
  int sendAntiIceOff(){return 553;};
  int sendAntiIceSet(){return 554;};
  int sendAntiIceToggle(){return 555;};
  int sendAntiIceToggleEng1(){return 556;};
  int sendAntiIceToggleEng2(){return 557;};
  int sendAntiIceToggleEng3(){return 558;};
  int sendAntiIceToggleEng4(){return 559;};
  int sendAntiIceSetEng1(){return 560;};
  int sendAntiIceSetEng2(){return 561;};
  int sendAntiIceSetEng3(){return 562;};
  int sendAntiIceSetEng4(){return 563;};
  int sendToggleFuelValveAll(){return 564;};
  int sendToggleFuelValveEng1(){return 565;};
  int sendToggleFuelValveEng2(){return 566;};
  int sendToggleFuelValveEng3(){return 567;};
  int sendToggleFuelValveEng4(){return 568;};
  int sendFuelSelectorOff(){return 569;};
  int sendFuelSelectorAll(){return 570;};
  int sendFuelSelectorLeft(){return 571;};
  int sendFuelSelectorRight(){return 572;};
  int sendFuelSelectorLeftAux(){return 573;};
  int sendFuelSelectorRightAux(){return 574;};
  int sendFuelSelectorCenter(){return 575;};
  int sendFuelSelectorSet(){return 576;};
  int sendFuelSelector2Off(){return 577;};
  int sendFuelSelector2All(){return 578;};
  int sendFuelSelector2Left(){return 579;};
  int sendFuelSelector2Right(){return 580;};
  int sendFuelSelector2LeftAux(){return 581;};
  int sendFuelSelector2RightAux(){return 582;};
  int sendFuelSelector2Center(){return 583;};
  int sendFuelSelector2Set(){return 584;};
  int sendFuelSelector3Off(){return 585;};
  int sendFuelSelector3All(){return 586;};
  int sendFuelSelector3Left(){return 587;};
  int sendFuelSelector3Right(){return 588;};
  int sendFuelSelector3LeftAux(){return 589;};
  int sendFuelSelector3RightAux(){return 590;};
  int sendFuelSelector3Center(){return 591;};
  int sendFuelSelector3Set(){return 592;};
  int sendFuelSelector4Off(){return 593;};
  int sendFuelSelector4All(){return 594;};
  int sendFuelSelector4Left(){return 595;};
  int sendFuelSelector4Right(){return 596;};
  int sendFuelSelector4LeftAux(){return 597;};
  int sendFuelSelector4RightAux(){return 598;};
  int sendFuelSelector4Center(){return 599;};
  int sendFuelSelector4Set(){return 600;};
  int sendCrossFeedOpen(){return 601;};
  int sendCrossFeedToggle(){return 602;};
  int sendCrossFeedOff(){return 603;};
  int sendElevTrimDn(){return 604;};
  int sendDown(){return 605;};
  int sendElevTrimUp(){return 606;};
  int sendElevUp(){return 607;};
  int sendSpoilersArmToggle(){return 608;};
  int sendSpoilersOn(){return 609;};
  int sendSpoilersOff(){return 610;};
  int sendSpoilersArmOn(){return 611;};
  int sendSpoilersArmOff(){return 612;};
  int sendAileronTrimLeft(){return 613;};
  int sendAileronTrimRight(){return 614;};
  int sendRudderTrimLeft(){return 615;};
  int sendRudderTrimRight(){return 616;};
  int sendCowFlap1Set(){return 617;};
  int sendCowlFlap2Set(){return 618;};
  int sendCowlFlap3Set(){return 619;};
  int sendCowlFlap4Set(){return 620;};
  int sendIncCowlFlaps(){return 621;};
  int sendDecCowlFlaps(){return 622;};
  int sendIncCowlFlaps1(){return 623;};
  int sendDecCowlFlaps1(){return 624;};
  int sendIncCowlFlaps2(){return 625;};
  int sendDecCowlFlaps2(){return 626;};
  int sendIncCowlFlaps3(){return 627;};
  int sendDecCowlFlaps3(){return 628;};
  int sendIncCowlFlaps4(){return 629;};
  int sendDecCowlFlaps4(){return 630;};
  int sendFuelPump(){return 631;};
  int sendToggleElectFuelPump(){return 632;};
  int sendToggleElectFuelPump1(){return 633;};
  int sendToggleElectFuelPump2(){return 634;};
  int sendToggleElectFuelPump3(){return 635;};
  int sendToggleElectFuelPump4(){return 636;};
  int sendEnginePrimer(){return 637;};
  int sendToggleEnginePrimer(){return 638;};
  int sendTogglePrimer1(){return 639;};
  int sendTogglePrimer2(){return 640;};
  int sendTogglePrimer3(){return 641;};
  int sendTogglePrimer4(){return 642;};
  int sendToggleFeatherSwitches(){return 643;};
  int sendToggleFeatherSwitch1(){return 644;};
  int sendToggleFeatherSwitch2(){return 645;};
  int sendToggleFeatherSwitch3(){return 646;};
  int sendToggleFeatherSwitch4(){return 647;};
  int sendTogglePropellerSync(){return 648;};
  int sendToggleAutoFeatherArm(){return 649;};
  int sendToggleAfterburner(){return 650;};
  int sendToggleAfterburner1(){return 651;};
  int sendToggleAfterburner2(){return 652;};
  int sendToggleAfterburner3(){return 653;};
  int sendToggleAfterburner4(){return 654;};
  int sendEngine(){return 655;};
  int sendSpoilersToggle(){return 656;};
  int sendToggleStarter1(){return 657;};
  int sendToggleStarter2(){return 658;};
  int sendToggleStarter3(){return 659;};
  int sendToggleStarter4(){return 660;};
  int sendToggleAllStarters(){return 661;};
  int sendEngineAutoStart(){return 662;};
  int sendEngineAutoShutdown(){return 663;};
  int sendFuelSelectorLeftMain(){return 664;};
  int sendFuelSelector2LeftMain(){return 665;};
  int sendFuelSelector3LeftMain(){return 666;};
  int sendFuelSelector4LeftMain(){return 667;};
  int sendFuelSelectorRightMain(){return 668;};
  int sendFuelSelector2RightMain(){return 669;};
  int sendFuelSelector3RightMain(){return 670;};
  int sendFuelSelector4RightMain(){return 671;};
  int sendApuStarter(){return 672;};
  int sendApuOffSwitch(){return 673;};
  int sendApuGeneratorSwitchToggle(){return 674;};
  int sendCabinNoSmokingAlertSwitchToggle(){return 675;};
  int sendCabinSeatbeltsAlertSwitchToggle(){return 676;};

  int sendStrobesToggle(){return 677;};
  int sendAllLightsToggle(){return 678;};
  int sendPanelLightsToggle(){return 679;};
  int sendLandingLightsToggle(){return 680;};
  int sendLandingLightUp(){return 681;};
  int sendLandingLightDown(){return 682;};
  int sendLandingLightLeft(){return 683;};
  int sendLandingLightRight(){return 684;};
  int sendLandingLightHome(){return 685;};
  int sendStrobesOn(){return 686;};
  int sendStrobesOff(){return 687;};
  int sendPanelLightsOn(){return 688;};
  int sendPanelLightsOff(){return 689;};
  int sendLandingLightsOn(){return 690;};
  int sendLandingLightsOff(){return 691;};
  int sendToggleBeaconLights(){return 692;};
  int sendToggleTaxiLights(){return 693;};
  int sendToggleLogoLights(){return 694;};
  int sendToggleRecognitionLights(){return 695;};
  int sendToggleWingLights(){return 696;};
  int sendToggleNavLights(){return 697;};
  int sendToggleCabinLights(){return 698;};
  int sendGearUp(){return 699;};
  int sendGearDown(){return 700;};
  int sendToggleStructuralDeice(){return 701;};
  int sendTogglePropellerDeice(){return 702;};
  int sendToggleAlternator1(){return 703;};
  int sendToggleAlternator2(){return 704;};
  int sendToggleAlternator3(){return 705;};
  int sendToggleAlternator4(){return 706;};
  int sendAtc(){return 707;};
  int sendATCMenu1(){return 708;};
  int sendATCMenu2(){return 709;};
  int sendATCMenu3(){return 710;};
  int sendATCMenu4(){return 711;};
  int sendATCMenu5(){return 712;};
  int sendATCMenu6(){return 713;};
  int sendATCMenu7(){return 714;};
  int sendATCMenu8(){return 715;};
  int sendATCMenu9(){return 716;};
  int sendATCMenu0(){return 717;};
  int sendEGT1Inc(){return 718;};
  int sendEGT1Dec(){return 719;};
  int sendEGT2Inc(){return 720;};
  int sendEGT2Dec(){return 721;};
  int sendEGT3Inc(){return 722;};
  int sendEGT3Dec(){return 723;};
  int sendEGT4Inc(){return 724;};
  int sendEGT4Dec(){return 725;};
  int sendEGTInc(){return 726;};
  int sendEGTDec(){return 727;};
  int sendToggleGPSDrivesNav1(){return 728;};
  int sendGPSPowerButton(){return 729;};
  int sendGPSNearestButton(){return 730;};
  int sendGPSObsButton(){return 731;};
  int sendGPSMsgButton(){return 732;};
  int sendGPSMsgButtonDown(){return 733;};
  int sendGPSMsgButtonUp(){return 734;};
  int sendGPSFlightplanButton(){return 735;};
  int sendGPSTerrainButton(){return 736;};
  int sendGPSProcedureButton(){return 737;};
  int sendGPSZoominButton(){return 738;};
  int sendGPSZoomoutButton(){return 739;};
  int sendGPSDirectToButton(){return 740;};
  int sendGPSMenuButton(){return 741;};
  int sendGPSClearButton(){return 742;};
  int sendGPSClearAllButton(){return 743;};
  int sendGPSClearButtonDown(){return 744;};
  int sendGPSClearButtonUp(){return 745;};
  int sendGPSEnterButton(){return 746;};
  int sendGPSCursorButton(){return 747;};
  int sendGPSGroupKnobInc(){return 748;};
  int sendGPSGroupKnobDec(){return 749;};
  int sendGPSPageKnobInc(){return 750;};
  int sendGPSPageKnobDec(){return 751;};
  int sendYawDamperToggle(){return 752;};
  int sendG1000PfdFlightplanButton(){return 753;};
  int sendG1000PfdProcedureButton(){return 754;};
  int sendG1000PfdZoominButton(){return 755;};
  int sendG1000PfdZoomoutButton(){return 756;};
  int sendG1000PfdDirectToButton(){return 757;};
  int sendG1000PfdMenuButton(){return 758;};
  int sendG1000PfdClearButton(){return 759;};
  int sendG1000PfdEnterButton(){return 760;};
  int sendG1000PfdCursorButton(){return 761;};
  int sendG1000PfdGroupKnobInc(){return 762;};
  int sendG1000PfdGroupKnobDec(){return 763;};
  int sendG1000PfdPageKnobInc(){return 764;};
  int sendG1000PfdPageKnobDec(){return 765;};
  int sendG1000PfdSoftkey1(){return 766;};
  int sendG1000PfdSoftkey2(){return 767;};
  int sendG1000PfdSoftkey3(){return 768;};
  int sendG1000PfdSoftkey4(){return 769;};
  int sendG1000PfdSoftkey5(){return 770;};
  int sendG1000PfdSoftkey6(){return 771;};
  int sendG1000PfdSoftkey7(){return 772;};
  int sendG1000PfdSoftkey8(){return 773;};
  int sendG1000PfdSoftkey9(){return 774;};
  int sendG1000PfdSoftkey10(){return 775;};
  int sendG1000PfdSoftkey11(){return 776;};
  int sendG1000PfdSoftkey12(){return 777;};
  int sendG1000MfdFlightPlanButton(){return 778;};
  int sendG1000MfdProcedureButton(){return 779;};
  int sendG1000MfdZoominButton(){return 780;};
  int sendG1000MfdZoomoutButton(){return 781;};
  int sendG1000MfdDirectToButton(){return 782;};
  int sendG1000MfdMenuButton(){return 783;};
  int sendG1000MfdClearButton(){return 784;};
  int sendG1000MfdEnterButton(){return 785;};
  int sendG1000MfdCursorButton(){return 786;};
  int sendG1000MfdGroupKnobInc(){return 787;};
  int sendG1000MfdGroupKnobDec(){return 788;};
  int sendG1000MfdPageKnobInc(){return 789;};
  int sendG1000MfdPageKnobDec(){return 790;};
  int sendG1000MfdSoftkey1(){return 791;};
  int sendG1000MfdSoftkey2(){return 792;};
  int sendG1000MfdSoftkey3(){return 793;};
  int sendG1000MfdSoftkey4(){return 794;};
  int sendG1000MfdSoftkey5(){return 795;};
  int sendG1000MfdSoftkey6(){return 796;};
  int sendG1000MfdSoftkey7(){return 797;};
  int sendG1000MfdSoftkey8(){return 798;};
  int sendG1000MfdSoftkey9(){return 799;};
  int sendG1000MfdSoftkey10(){return 800;};
  int sendG1000MfdSoftkey11(){return 801;};
  int sendG1000MfdSoftkey12(){return 802;};
  int sendApMaxBankInc(){return 803;};
  int sendApMaxBankDec(){return 804;};
  int sendGyroDriftInc(){return 805;};
  int sendGyroDriftDec(){return 806;};
  int sendTrueAirspeedCalInc(){return 807;};
  int sendTrueAirspeedCalDec(){return 808;};
  int sendDecreaseDecisionHeight(){return 809;};
  int sendIncreaseDecisionHeight(){return 810;};


  // library-accessible "private" interface

 private:
  //--------------------------------------------
  // TRANSMIT DATA
  // These values can be ommited and printed to serial directly
  // They are mainly implemented to improve readability of your code

  Stream* serial;

  // Avionics
  int valSendAvionicsMaster1On = 401;
  int valSendAvionicsMaster1Off = 402;
  int valSendAvionicsMaster2On = 403;
  int valSendAvionicsMaster2Off = 404;
  int valSendParkingBrake = 420;
  byte valSendMixtureInput(){return 115;}
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


  int apVerticalSpeed;
  int kohlmanAltimeter;
  int barPressure;
  int apAltLock;
  int apHeadingLock;

  int indicatedAirspeed;
  int indicatedAltitude;
  int indicatedHeading;
  int indicatedGPSGroundspeed;
  int trueVerticalSpeed;

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

  int fuelTotalPercentage;

  char valuesBuffer[40];

  bool advanced;
  byte engine1 = 0;
  byte engine2 = 0;
  byte engine3 = 0;
  byte engine4 = 0;

  byte prop1 = 0;
  byte prop2 = 0;

  byte engines[4] = {0, 0, 0, 0};
  byte mixturePercentage[2] = {0,0};
  byte props[2] = {0, 0};

  int value;
  int propValue1;
  int propValue2;
  int oldValue;

  int navObs1;
  int navObs2;

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

  int mixtureValue1;
  int mixtureValue2;
  int oldMixtureValue1;
  int oldMixtureValue2;

  int oldTrim;
  int currentTrim;

  int currentRudder;
  int oldRudderAxis;

  int currentLeftBrake;
  int oldLeftBrake;

  int currentRightBrake;
  int oldRightBrake;

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
  int gpsCourseToSteer;

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
  byte flapsHandlePct;
  byte flapsHandleIndex;
  byte flapsNumHandlePos;
  byte trailingEdgeFlapsLeftPercent;
  byte trailingEdgeFlapsRightPercent;
  int trailingEdgeFlapsLeftAngle;
  int trailingEdgeFlapsRightAngle;
  byte leadingEdgeFlapsLeftPct;
  int leadingEdgeFlapsRightPct;
  byte leadingEdgeFlapsLeftAngle;
  byte leadingEdgeFlapsRightAngle;

  // Gears
  bool gearHandlePos = false;
  int gearHydraulicPressure;
  bool tailWheelLock = false;
  byte gearCenterPositionPct;
  byte gearLeftPositionPct;
  byte gearRightPositionPct;
  byte gearTailPositionPct;
  byte gearAuxPosition;
  byte gearTotalPct;

  // Rudder/trim
  int aileronTrimPct;
  int aileronTrimDegr;
  int rudderTrimDegr;
  int rudderTrimPct;
  int elevatorTrimPos;
  int elevatorTrimPct;

  //Flaps
  int valSendFlapsUp = 501;
  int valSendFlaps1 = 502;
  int valSendFlaps2 = 503;
  int valSendFlaps3 = 504;
  int valSendFlapsDown = 505;
  int valSendFlapsInc = 506;
  int valSendFlapsDec = 507;

  int calculateAxis(int value, int minVal, int maxVal);
  int rightBrakeFormated = 0;
  int leftBrakeFormated = 0;
  // Plane data
  String planeName = "";
  String receivedValue;
  String prefix = "";
  String cutValue = "";
  float EMA_a = 0.1;
  int EMA_S = 0;
};

#endif
