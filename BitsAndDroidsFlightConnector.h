#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-nodiscard"
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

#ifndef BitsAndDroidsFlightConnector_h
#define BitsAndDroidsFlightConnector_h

#if !defined(ARDUINO_SAM_DUE) && !defined(ESP32) && !defined(ESP8266) &&       \
    !defined(PICO_RP2040)
#include "SoftwareSerial.h"
#endif

enum sendCommands {

  sendApMasterOn = 301,
  sendApPanelHeadingLock = 302,
  sendAPPanelAltitudeHold = 303,
  sendAPAttitudeHoldOn = 304,
  sendAPLocHoldOn = 305,
  sendAPAprHoldOn = 306,
  sendAPHeadingHoldOn = 307,
  sendAltitudeHoldOn = 367,
  sendApWingLevelerOn = 309,
  sendBCHoldOn = 310,
  sendAPNav1HoldOn = 311,
  sendAPAttitudeHoldOff = 312,
  sendAPLocHoldOff = 313,
  sendAprHoldOff = 314,
  sendAPHeadingHoldOff = 315,
  sendAvionicsMaster1On = 401,
  sendAvionicsMaster1Off = 402,
  sendAvionicsMaster2On = 403,
  sendAvionicsMaster2Off = 404,
  sendParkingBrake = 420,

  sendMixtureInput = 115,

  sendToggleMasterBattery1 = 405,
  sendToggleMasterBattery2 = 406,
  sendToggleExternalPower = 408,
  sendToggleMasterAlternator = 407,

  sendXpndrIdentOff = 103,
  sendXpndrIdentOn = 104,
  sendXpndrIdentToggle = 105,
  sendXpndrSet = 106,
  sendXpndr1000Inc = 171,
  sendXpndr100Inc = 172,
  sendXpndr10Inc = 173,
  sendXpndr1Inc = 174,
  sendXpndr1000Dec = 175,
  sendXpndr100Dec = 176,
  sendXpndr10Dec = 177,
  sendXpndr1Dec = 178,

  sendSelectedAdfIdentEnable = 158,
  sendSelectedAdfIdentDisable = 159,
  sendSelecetedAdfIdentSet = 160,
  sendSelectedAdfIdentToggle = 161,
  sendAdfCardInc = 162,
  sendAdfCardDec = 163,
  sendAdfCardSet = 164,
  sendAdf100Inc = 165,
  sendAdf10Inc = 166,
  sendAdf1Inc = 167,
  sendAdf100Dec = 168,
  sendAdf10Dec = 169,
  sendAdf1Dec = 170,
  sendAdfCompleteSet = 179,
  sendAdf1TenthsInc = 390,
  sendAdf1TenthsDec = 391,
  sendAdf1WholeInc = 180,
  sendAdf1WholeDec = 181,
  sendAdf2100Inc = 182,
  sendAdf210Inc = 183,
  sendAdf21Inc = 184,
  sendAdf2RadioThenthsInc = 185,
  sendAdf2100Dec = 186,
  sendAdf210Dec = 187,
  sendAdf21Dec = 188,
  sendAdf2RadioThenthsDec = 189,
  sendAdf2WholeInc = 190,
  sendAdf2WholeDec = 191,
  sendAdf2FractDecCarry = 192,
  sendAdf2FractIncCarry = 193,
  sendAdf2CompleteSet = 194,
  sendAdf2IdentDisable = 195,
  sendAdf2IdentEnable = 196,
  sendAdf2IdentToggle = 197,
  sendAdf2IdentSet = 200,

  sendSelectedVor1IdentEnable = 145,
  sendSelectedVor1IdentDisable = 146,
  sendSelectedVor1IdentSet = 147,
  sendVor1IdentToggle = 148,
  sendVor2IdentEnable = 149,
  sendVor2IdentDisable = 150,
  sendVor2IdentSet = 151,
  sendVor2IdentToggle = 152,
  sendVorToggle = 153,
  sendVor1ObiDec = 154,
  sendVor1ObiInc = 155,
  sendVor2ObiDec = 156,
  sendVor2ObiInc = 157,

  sendSelectedDme1IdentEnable = 136,
  sendSeletedDme1IdentDisable = 137,
  sendSelectedDme1IdentSet = 138,
  sendSelectedDme1IdentToggle = 139,
  sendSelectedDme2IdentEnable = 140,
  sendSelectedDme2IdentDisable = 141,
  sendSelectedDme2IdentSet = 142,
  sendSelectedDme2IdentToggle = 143,
  sendDmeToggle = 144,

  sendAPAltitudeHoldOff = 316,
  sendWingLevelerOff = 317,
  sendAPBCHoldOff = 318,
  sendAPNav1HoldOff = 319,
  sendAPAirspeedHold = 320,
  sendAPPanelSpeedHold = 321,
  sendAPAltitudeInc = 322,
  sendAPAltitudeDec = 323,
  sendAPVSInc = 324,
  sendAPVSDec = 325,
  sendAPSpeedInc = 326,
  sendAPSpeedDec = 327,
  sendAPPanelMachHold = 328,
  sendAPMachInc = 329,
  sendAPMachDec = 330,
  sendAPMachHold = 331,
  sendAPAltitudeSetMetric = 332,
  sendAPVSSetEnglish = 333,
  sendAPSpeedSet = 334,
  sendAPMachVarSet = 335,
  sendAPAirspeedOn = 336,
  sendAPAirspeedOff = 337,
  sendAPAirspeedSet = 338,
  sendAPMachOn = 339,
  sendAPMachOff = 340,
  sendAPMachSet = 341,
  sendAPPanelAltitudeOn = 342,
  sendAPPanelAltitudeOff = 343,
  sendAPPanelAltitudeSet = 345,
  sendAPPanelHeadingOn = 346,
  sendAPPanelHeadingOff = 347,
  sendAPPanelHeadingSet = 348,
  sendAPPanelMachOn = 349,
  sendAPPanelMachOff = 350,
  sendAPPanelMachSet = 351,
  sendAPPanelSpeedOn = 352,
  sendAPPanelSpeedOff = 353,
  sendAPPanelSpeedSet = 354,
  sendAPPanelAltVarSetEnglish = 355,
  sendAPVSVarSetMetric = 356,
  sendAPPanelSpeedHoldToggle = 357,
  sendAPPanelMachHoldToggle = 358,
  sendAPNavSelectSet = 359,
  sendAPPitchRefIncUp = 360,
  sendAPPitchRefIncDown = 361,
  sendAPPitchRefSelect = 362,
  sendAPAttitudeHold = 363,
  sendAPLocHold = 364,
  sendAPAprHold = 365,
  sendAPHeadingHold = 366,
  sendAPAltitudeHold = 367,
  sendAPWingLeveler = 368,
  sendAPBCHold = 369,
  sendAPNav1Hold = 370,
  sendHeadingBugInc = 371,
  sendHeadingBugDec = 372,
  sendAPFlightDirector = 373,
  sendAPVSHold = 374,
  sendKohlsmanInc = 375,
  sendKohlsmanDec = 376,
  sendThrottleArm = 378,
  sendhrottleArmToGa = 379,

  SendStandbyCom1Set = 100,
  SendStandbyCom2Set = 101,

  sendCom1FractInc = 125,
  sendCom1FractIncCarry = 127,
  sendCom1FractDecr = 124,
  sendCom1FractDecrCarry = 126,

  sendCom2FractInc = 121,
  sendCom2FractIncCarry = 123,
  sendCom2FractDecr = 120,
  sendCom2FractDecrCarry = 122,

  sendCom1WholeDec = 111,
  sendCom1WholeInc = 112,
  sendCom2WholeDec = 113,
  sendCom2WholeInc = 114,

  sendSwapCom1 = 116,
  sendSwapCom2 = 117,

  slSendXpndrSet = 202,

  sendIncWholeNav1 = 132,
  sendDecWholeNav1 = 133,
  sendIncWholeNav2 = 134,
  sendDecWholeNav2 = 135,

  sendIncFractNav1 = 128,
  sendDecFractNav1 = 129,
  sendIncFractNav2 = 130,
  sendDecFractNav2 = 131,

  sendSwapNav1 = 118,
  sendSwapNav2 = 119,

  sendG1000ZoomMapIn = 250,
  sendG1000ZoomMapOut = 251,
  sendFlapsUp = 501,
  sendFlaps1 = 502,
  sendFlaps2 = 503,
  sendFlaps3 = 504,
  sendFlapsDown = 505,
  sendFlapsInc = 506,
  sendFlapsDec = 507,
  sendPitotHeatToggle = 508,
  sendPitotHeatOn = 509,
  sendPitotHeatOff = 510,
  sendMagneto = 511,
  sendMagnetoDecr = 512,
  sendMagnetoIncr = 513,
  sendMagneto1Off = 514,
  sendMagneto1Right = 515,
  sendMagneto1Left = 516,
  sendMagneto1Both = 517,
  sendMagneto1Start = 518,
  sendMagneto2Off = 519,
  sendMagneto2Right = 520,
  sendMagneto2Left = 521,
  sendMagneto2Both = 522,
  sendMagneto2Start = 523,
  sendMagneto3Off = 524,
  sendMagneto3Right = 525,
  sendMagneto3Left = 526,
  sendMagneto3Both = 527,
  sendMagneto3Start = 528,
  sendMagneto4Off = 529,
  sendMagneto4Right = 530,
  sendMagneto4Left = 531,
  sendMagneto4Both = 532,
  sendMagneto4Start = 533,
  sendMagnetoOff = 534,
  sendMagnetoRight = 535,
  sendMagnetoLeft = 536,
  sendMagnetoBoth = 537,
  sendMagnetoStart = 538,
  sendMagneto1Decr = 539,
  sendMagneto1Incr = 540,
  sendMagneto2Decr = 541,
  sendMagneto2Incr = 542,
  sendMagneto3Decr = 543,
  sendMagneto3Incr = 544,
  sendMagneto4Decr = 545,
  sendMagneto4Incr = 546,
  sendMagnetoSet = 547,
  sendMagneto1Set = 548,
  sendMagneto2Set = 549,
  sendMagneto3Set = 550,
  sendMagneto4Set = 551,
  sendAntiIceOn = 552,
  sendAntiIceOff = 553,
  sendAntiIceSet = 554,
  sendAntiIceToggle = 555,
  sendAntiIceToggleEng1 = 556,
  sendAntiIceToggleEng2 = 557,
  sendAntiIceToggleEng3 = 558,
  sendAntiIceToggleEng4 = 559,
  sendAntiIceSetEng1 = 560,
  sendAntiIceSetEng2 = 561,
  sendAntiIceSetEng3 = 562,
  sendAntiIceSetEng4 = 563,
  sendToggleFuelValveAll = 564,
  sendToggleFuelValveEng1 = 565,
  sendToggleFuelValveEng2 = 566,
  sendToggleFuelValveEng3 = 567,
  sendToggleFuelValveEng4 = 568,
  sendFuelSelectorOff = 569,
  sendFuelSelectorAll = 570,
  sendFuelSelectorLeft = 571,
  sendFuelSelectorRight = 572,
  sendFuelSelectorLeftAux = 573,
  sendFuelSelectorRightAux = 574,
  sendFuelSelectorCenter = 575,
  sendFuelSelectorSet = 576,
  sendFuelSelector2Off = 577,
  sendFuelSelector2All = 578,
  sendFuelSelector2Left = 579,
  sendFuelSelector2Right = 580,
  sendFuelSelector2LeftAux = 581,
  sendFuelSelector2RightAux = 582,
  sendFuelSelector2Center = 583,
  sendFuelSelector2Set = 584,
  sendFuelSelector3Off = 585,
  sendFuelSelector3All = 586,
  sendFuelSelector3Left = 587,
  sendFuelSelector3Right = 588,
  sendFuelSelector3LeftAux = 589,
  sendFuelSelector3RightAux = 590,
  sendFuelSelector3Center = 591,
  sendFuelSelector3Set = 592,
  sendFuelSelector4Off = 593,
  sendFuelSelector4All = 594,
  sendFuelSelector4Left = 595,
  sendFuelSelector4Right = 596,
  sendFuelSelector4LeftAux = 597,
  sendFuelSelector4RightAux = 598,
  sendFuelSelector4Center = 599,
  sendFuelSelector4Set = 600,
  sendCrossFeedOpen = 601,
  sendCrossFeedToggle = 602,
  sendCrossFeedOff = 603,
  sendElevTrimDn = 604,
  sendDown = 605,
  sendElevTrimUp = 606,
  sendElevUp = 607,
  sendSpoilersArmToggle = 608,
  sendSpoilersOn = 609,
  sendSpoilersOff = 610,
  sendSpoilersArmOn = 611,
  sendSpoilersArmOff = 612,
  sendAileronTrimLeft = 613,
  sendAileronTrimRight = 614,
  sendRudderTrimLeft = 615,
  sendRudderTrimRight = 616,
  sendCowFlap1Set = 617,
  sendCowlFlap2Set = 618,
  sendCowlFlap3Set = 619,
  sendCowlFlap4Set = 620,
  sendIncCowlFlaps = 621,
  sendDecCowlFlaps = 622,
  sendIncCowlFlaps1 = 623,
  sendDecCowlFlaps1 = 624,
  sendIncCowlFlaps2 = 625,
  sendDecCowlFlaps2 = 626,
  sendIncCowlFlaps3 = 627,
  sendDecCowlFlaps3 = 628,
  sendIncCowlFlaps4 = 629,
  sendDecCowlFlaps4 = 630,
  sendFuelPump = 631,
  sendToggleElectFuelPump = 632,
  sendToggleElectFuelPump1 = 633,
  sendToggleElectFuelPump2 = 634,
  sendToggleElectFuelPump3 = 635,
  sendToggleElectFuelPump4 = 636,
  sendEnginePrimer = 637,
  sendToggleEnginePrimer = 638,
  sendTogglePrimer1 = 639,
  sendTogglePrimer2 = 640,
  sendTogglePrimer3 = 641,
  sendTogglePrimer4 = 642,
  sendToggleFeatherSwitches = 643,
  sendToggleFeatherSwitch1 = 644,
  sendToggleFeatherSwitch2 = 645,
  sendToggleFeatherSwitch3 = 646,
  sendToggleFeatherSwitch4 = 647,
  sendTogglePropellerSync = 648,
  sendToggleAutoFeatherArm = 649,
  sendToggleAfterburner = 650,
  sendToggleAfterburner1 = 651,
  sendToggleAfterburner2 = 652,
  sendToggleAfterburner3 = 653,
  sendToggleAfterburner4 = 654,
  sendEngine = 655,
  sendSpoilersToggle = 656,
  sendToggleStarter1 = 657,
  sendToggleStarter2 = 658,
  sendToggleStarter3 = 659,
  sendToggleStarter4 = 660,
  sendToggleAllStarters = 661,
  sendEngineAutoStart = 662,
  sendEngineAutoShutdown = 663,
  sendFuelSelectorLeftMain = 664,
  sendFuelSelector2LeftMain = 665,
  sendFuelSelector3LeftMain = 666,
  sendFuelSelector4LeftMain = 667,
  sendFuelSelectorRightMain = 668,
  sendFuelSelector2RightMain = 669,
  sendFuelSelector3RightMain = 670,
  sendFuelSelector4RightMain = 671,
  sendApuStarter = 672,
  sendApuOffSwitch = 673,
  sendApuGeneratorSwitchToggle = 674,
  sendCabinNoSmokingAlertSwitchToggle = 675,
  sendCabinSeatbeltsAlertSwitchToggle = 676,

  sendStrobesToggle = 677,
  sendAllLightsToggle = 678,
  sendPanelLightsToggle = 679,
  sendLandingLightsToggle = 680,
  sendLandingLightUp = 681,
  sendLandingLightDown = 682,
  sendLandingLightLeft = 683,
  sendLandingLightRight = 684,
  sendLandingLightHome = 685,
  sendStrobesOn = 686,
  sendStrobesOff = 687,
  sendPanelLightsOn = 688,
  sendPanelLightsOff = 689,
  sendLandingLightsOn = 690,
  sendLandingLightsOff = 691,
  sendToggleBeaconLights = 692,
  sendToggleTaxiLights = 693,
  sendToggleLogoLights = 694,
  sendToggleRecognitionLights = 695,
  sendToggleWingLights = 696,
  sendToggleNavLights = 697,
  sendToggleCabinLights = 698,
  sendGearUp = 699,
  sendGearDown = 700,
  sendToggleStructuralDeice = 701,
  sendTogglePropellerDeice = 702,
  sendToggleAlternator1 = 703,
  sendToggleAlternator2 = 704,
  sendToggleAlternator3 = 705,
  sendToggleAlternator4 = 706,
  sendAtc = 707,
  sendATCMenu1 = 708,
  sendATCMenu2 = 709,
  sendATCMenu3 = 710,
  sendATCMenu4 = 711,
  sendATCMenu5 = 712,
  sendATCMenu6 = 713,
  sendATCMenu7 = 714,
  sendATCMenu8 = 715,
  sendATCMenu9 = 716,
  sendATCMenu0 = 717,
  sendEGT1Inc = 718,
  sendEGT1Dec = 719,
  sendEGT2Inc = 720,
  sendEGT2Dec = 721,
  sendEGT3Inc = 722,
  sendEGT3Dec = 723,
  sendEGT4Inc = 724,
  sendEGT4Dec = 725,
  sendEGTInc = 726,
  sendEGTDec = 727,
  sendToggleGPSDrivesNav1 = 728,
  sendGPSPowerButton = 729,
  sendGPSNearestButton = 730,
  sendGPSObsButton = 731,
  sendGPSMsgButton = 732,
  sendGPSMsgButtonDown = 733,
  sendGPSMsgButtonUp = 734,
  sendGPSFlightplanButton = 735,
  sendGPSTerrainButton = 736,
  sendGPSProcedureButton = 737,
  sendGPSZoominButton = 738,
  sendGPSZoomoutButton = 739,
  sendGPSDirectToButton = 740,
  sendGPSMenuButton = 741,
  sendGPSClearButton = 742,
  sendGPSClearAllButton = 743,
  sendGPSClearButtonDown = 744,
  sendGPSClearButtonUp = 745,
  sendGPSEnterButton = 746,
  sendGPSCursorButton = 747,
  sendGPSGroupKnobInc = 748,
  sendGPSGroupKnobDec = 749,
  sendGPSPageKnobInc = 750,
  sendGPSPageKnobDec = 751,
  sendYawDamperToggle = 752,
  sendG1000PfdFlightplanButton = 753,
  sendG1000PfdProcedureButton = 754,
  sendG1000PfdZoominButton = 755,
  sendG1000PfdZoomoutButton = 756,
  sendG1000PfdDirectToButton = 757,
  sendG1000PfdMenuButton = 758,
  sendG1000PfdClearButton = 759,
  sendG1000PfdEnterButton = 760,
  sendG1000PfdCursorButton = 761,
  sendG1000PfdGroupKnobInc = 762,
  sendG1000PfdGroupKnobDec = 763,
  sendG1000PfdPageKnobInc = 764,
  sendG1000PfdPageKnobDec = 765,
  sendG1000PfdSoftkey1 = 766,
  sendG1000PfdSoftkey2 = 767,
  sendG1000PfdSoftkey3 = 768,
  sendG1000PfdSoftkey4 = 769,
  sendG1000PfdSoftkey5 = 770,
  sendG1000PfdSoftkey6 = 771,
  sendG1000PfdSoftkey7 = 772,
  sendG1000PfdSoftkey8 = 773,
  sendG1000PfdSoftkey9 = 774,
  sendG1000PfdSoftkey10 = 775,
  sendG1000PfdSoftkey11 = 776,
  sendG1000PfdSoftkey12 = 777,
  sendG1000MfdFlightPlanButton = 778,
  sendG1000MfdProcedureButton = 779,
  sendG1000MfdZoominButton = 780,
  sendG1000MfdZoomoutButton = 781,
  sendG1000MfdDirectToButton = 782,
  sendG1000MfdMenuButton = 783,
  sendG1000MfdClearButton = 784,
  sendG1000MfdEnterButton = 785,
  sendG1000MfdCursorButton = 786,
  sendG1000MfdGroupKnobInc = 787,
  sendG1000MfdGroupKnobDec = 788,
  sendG1000MfdPageKnobInc = 789,
  sendG1000MfdPageKnobDec = 790,
  sendG1000MfdSoftkey1 = 791,
  sendG1000MfdSoftkey2 = 792,
  sendG1000MfdSoftkey3 = 793,
  sendG1000MfdSoftkey4 = 794,
  sendG1000MfdSoftkey5 = 795,
  sendG1000MfdSoftkey6 = 796,
  sendG1000MfdSoftkey7 = 797,
  sendG1000MfdSoftkey8 = 798,
  sendG1000MfdSoftkey9 = 799,
  sendG1000MfdSoftkey10 = 800,
  sendG1000MfdSoftkey11 = 801,
  sendG1000MfdSoftkey12 = 802,
  sendApMaxBankInc = 803,
  sendApMaxBankDec = 804,
  sendGyroDriftInc = 805,
  sendGyroDriftDec = 806,
  sendTrueAirspeedCalInc = 807,
  sendTrueAirspeedCalDec = 808,
  sendDecreaseDecisionHeight = 809,
  sendIncreaseDecisionHeight = 810,

  sendG3000HorizontalBottomKnobPush = 811,
  sendG3000HorizontalBottomKnobSmallDec = 812,
  sendG3000HorizontalBottomKnowSmallInc = 813,
  sendG3000HorizontalSoftkey1 = 814,
  sendG3000HorizontalSoftkey2 = 815,
  sendG3000HorizontalSoftkey3 = 816,
  sendG3000HorizontalTopKnobLargeDec = 817,
  sendG3000HorizontalTopKnobLargeInc = 818,
  sendG3000HorizontalTopKnobPush = 819,
  sendG3000HorizontalTopKnobPushLong = 820,
  sendG3000HorizontalTopKnobSmallDec = 821,
  sendG3000HorizontalTopKnobSmallInc = 822,
  sendG3000PFD1Softkey1 = 823,
  sendG3000PFD1Softkey2 = 824,
  sendG3000PFD1Softkey3 = 825,
  sendG3000PFD1Softkey4 = 826,
  sendG3000PFD1Softkey5 = 827,
  sendG3000PFD1Softkey6 = 828,
  sendG3000PFD1Softkey7 = 829,
  sendG3000PFD1Softkey8 = 830,
  sendG3000PFD1Softkey9 = 831,
  sendG3000PFD1Softkey10 = 832,
  sendG3000PFD1Softkey11 = 833,
  sendG3000PFD1Softkey12 = 834,

  sendG3000PFD2Softkey1 = 835,
  sendG3000PFD2Softkey2 = 836,
  sendG3000PFD2Softkey3 = 837,
  sendG3000PFD2Softkey4 = 838,
  sendG3000PFD2Softkey5 = 839,
  sendG3000PFD2Softkey6 = 840,
  sendG3000PFD2Softkey7 = 841,
  sendG3000PFD2Softkey8 = 842,
  sendG3000PFD2Softkey9 = 843,
  sendG3000PFD2Softkey10 = 844,
  sendG3000PFD2Softkey11 = 845,
  sendG3000PFD2Softkey12 = 846,

  sendG3000PFD3Softkey1 = 847,
  sendG3000PFD3Softkey2 = 848,
  sendG3000PFD3Softkey3 = 849,
  sendG3000PFD3Softkey4 = 850,
  sendG3000PFD3Softkey5 = 851,
  sendG3000PFD3Softkey6 = 852,
  sendG3000PFD3Softkey7 = 853,
  sendG3000PFD3Softkey8 = 854,
  sendG3000PFD3Softkey9 = 855,
  sendG3000PFD3Softkey10 = 856,
  sendG3000PFD3Softkey11 = 857,
  sendG3000PFD3Softkey12 = 858,

  sendG3000MFDSoftkey1 = 859,
  sendG3000MFDSoftkey2 = 860,
  sendG3000MFDSoftkey3 = 861,
  sendG3000MFDSoftkey4 = 862,
  sendG3000MFDSoftkey5 = 863,
  sendG3000MFDSoftkey6 = 864,
  sendG3000MFDSoftkey7 = 865,
  sendG3000MFDSoftkey8 = 866,
  sendG3000MFDSoftkey9 = 867,
  sendG3000MFDSoftkey10 = 868,
  sendG3000MFDSoftkey11 = 869,
  sendG3000MFDSoftkey12 = 870,

  sendG3000PFDSoftkey1 = 871,
  sendG3000PFDSoftkey2 = 872,
  sendG3000PFDSoftkey3 = 873,
  sendG3000PFDSoftkey4 = 874,
  sendG3000PFDSoftkey5 = 875,
  sendG3000PFDSoftkey6 = 876,
  sendG3000PFDSoftkey7 = 877,
  sendG3000PFDSoftkey8 = 878,
  sendG3000PFDSoftkey9 = 879,
  sendG3000PFDSoftkey10 = 880,
  sendG3000PFDSoftkey11 = 881,
  sendG3000PFDSoftkey12 = 882,

  sendG3000PFDBottomKnobLargeDec = 883,
  sendG3000PFDBottomKnobLargeInc = 884,
  sendG3000PFDBottomKnobPush = 885,
  sendG3000PFDBottomKnobPushLong = 886,
  sendG3000PFDBottomKnobSmallDec = 887,
  sendG3000PFDBottomKnobSmallInc = 888,

  sendG3000PFDTopKnobLargeDec = 889,
  sendG3000PFDTopKnobLargeInc = 890,
  sendG3000PFDTopKnobSmallDec = 891,
  sendG3000PFDTopKnobSmallInc = 892,

  sendG3000VerticalBottomKnobLargeDec = 893,
  sendG3000VerticalBottomKnobLargeInc = 894,
  sendG3000VerticalBottomKnobPush = 895,
  sendG3000VerticalBottomKnobPushLong = 896,
  sendG3000VerticalBottomKnobSmallDec = 897,
  sendG3000VerticalBottomKnobSmallInc = 898,
  sendG3000VerticalTopKnobLargeDec = 899,
  sendG3000VerticalTopKnobLargeInc = 903,
  sendG3000VerticalTopKnobSmallDec = 904,
  sendG3000VerticalTopKnobSmallInc = 905,
  sendMasterWarning = 906,
  sendMasterCaution = 907,
  sendSimPauseOn = 908,
  sendSimPauseOff = 909
};

#define SEND_GET_COMMAND 999

// library interface description
class BitsAndDroidsFlightConnector {
  // user-accessible "public" interface
public:
  int getFuelLevel() { return fuelLevel; };

  int connected = 0;

  BitsAndDroidsFlightConnector();
#if defined(ARDUINO_SAM_DUE)
  BitsAndDroidsFlightConnector(Serial_ *serial);
#elif defined(ESP32) ||                                                        \
    defined(                                                                   \
        ESP8266) // This will handle all boards except ESP32 and Arduino Due
  BitsAndDroidsFlightConnector(HardwareSerial *serial);
#else            // This handles the ESP32 and other boards with HardwareSerial
  BitsAndDroidsFlightConnector(SoftwareSerial *serial);
#endif
  String getVersion() { return "0.9.9.9"; }
  void send(int command);
  void switchHandling();
  int getConnected() { return connected; };
  void checkConnection();
  void dataHandling();
  void simpleInputHandling(int throttlePin);
  void advancedInputHandling(int eng1Pin, int eng2Pin, int eng3Pin,
                             int eng4Pin);
  void superAdvancedInputHandling(byte eng1Percentage, byte eng2Percentage,
                                  byte eng3Percentage, byte eng4Percentage);
  void sendCombinedMixtureValues();
  void propsInputHandling(int propPin1, int propPin2, int propPin3,
                          int propPin4);
  void mixtureInputHandling(int mixturePin1, int mixturePin2, int mixturePin3,
                            int mixturePin4);
  void sendSetElevatorTrim(int value);
  void sendFlaps();
  void setPotFlaps(byte flapsPin);
  void sendSetBrakePot(byte leftPin, byte rightPin);
  void sendSetYokeAxis(byte elevatorPin, byte aileronPin);
  void sendSetRudderPot(byte potPin);
  void sendSetElevatorTrimPot(byte potPin, int minVal, int maxVal);
  void sendSetKohlmanAltimeterInHg(float kohlmanInhg);
  void sendSetKohlmanAltimeterMb(float kohlmanMb);
  void setEMA_a(float a);
  byte getPercentage(int value, int minVal, float maxVal, bool reversed);
  void sendGetValueById(int id);
  // void setSampleSize(byte amntSamples){sampleSize = amntSamples;};
  // Data
  int feetAboveGround = 0;
  int getFeetAboveGround() { return feetAboveGround; };

  bool onGround = true;
  bool getOnGround() { return onGround; };
  // Ap
  int getApVerticalSpeed() { return apVerticalSpeed; };
  long int getApAltLock() { return apAltLock; };

  // GPS
  int getGpsCourseToSteer() { return gpsCourseToSteer; };

  // Avionics
  int getApHeadingLock() { return apHeadingLock; };
  int getKohlmanAltimeter() { return kohlmanAltimeter; };
  int getBarPressure() { return barPressure; };
  byte getFuelTotalPercentage() { return fuelTotalPercentage; };

  int getIndicatedAirspeed() { return indicatedAirspeed; };
  int getVarometerRate() { return varometerRate; };
  int getIndicatedAltitude() { return indicatedAltitude; };
  int getIndicatedAltitude2() { return indicatedAltitude2; };
  int getIndicatedAltitudeCalibrated() { return indicatedAltitudeCalibrated; };
  int getIndicatedHeading() { return indicatedHeading; };
  int getIndicatedGPSGroundspeed() { return indicatedGPSGroundspeed; };
  int getTrueVerticalSpeed() { return trueVerticalSpeed; };
  int getLastPrefix();

  // Lights
  bool getLightTaxiOn() { return lightTaxiOn; };
  bool getLightStrobeOn() { return lightStrobeOn; };
  bool getLightPanelOn() { return lightPanelOn; };
  bool getLightRecognitionOn() { return lightRecognitionOn; };
  bool getLightWingOn() { return lightWingOn; };
  bool getLightLogoOn() { return lightLogoOn; };
  bool getLightCabinOn() { return lightCabinOn; };
  bool getLightHeadOn() { return lightHeadOn; };
  bool getLightBrakeOn() { return lightBrakeOn; };
  bool getLightNavOn() { return lightNavOn; };
  bool getLightBeaconOn() { return lightBeaconOn; };
  bool getLightLandingOn() { return lightLandingOn; };

  // Coms
  long getActiveCom1() { return activeCom1; };
  long getActiveCom2() { return activeCom2; };
  long getStandbyCom1() { return standByCom1; };
  long getStandbyCom2() { return standByCom2; };
  long getActiveNav1() { return activeNav1; };
  long getActiveNav2() { return activeNav2; };
  long getStandbyNav1() { return standbyNav1; };
  long getStandbyNav2() { return standbyNav2; };
  String getNavRadialError1() { return navRadialError1; };
  String getNavVorLationalt1() { return navVorLationalt1; };

  int getNavObs1() { return navObs1; };
  int getNavObs2() { return navObs2; };

  // Warnings
  bool getStallWarningOn() { return stallWarning; };
  bool getOverspeedWarningOn() { return overspeedWarning; };

  // flaps
  byte getFlapsHandlePct() { return flapsHandlePct; };
  byte getFlapsHandleIndex() { return flapsHandleIndex; };
  byte getFlapsNumHandlePos() { return flapsNumHandlePos; };
  byte getTrailingEdgeFlapsLeftPercent() {
    return trailingEdgeFlapsLeftPercent;
  };
  byte getTrailingEdgeFlapsRightPercent() {
    return trailingEdgeFlapsRightPercent;
  };
  int getTrailingEdgeFlapsLeftAngle() { return trailingEdgeFlapsLeftAngle; };
  int getTrailingEdgeFlapsRightAngle() { return trailingEdgeFlapsRightAngle; };
  byte getLeadingEdgeFlapsLeftPct() { return leadingEdgeFlapsLeftPct; };
  byte getLeadingEdgeFlapsRightPct() { return leadingEdgeFlapsRightPct; };
  int getLeadingEdgeFlapsLeftAngle() { return leadingEdgeFlapsLeftAngle; };
  int getLeadingEdgeFlapsRightAngle() { return leadingEdgeFlapsRightAngle; };

  // Gears
  bool getGearHandlePos() { return gearHandlePos; };
  int getGearHydraulicPressure() { return gearHydraulicPressure; };
  bool getTailWheelLock() { return tailWheelLock; };
  byte getGearCenterPositionPct() { return gearCenterPositionPct; };
  byte getGearLeftPositionPct() { return gearLeftPositionPct; };
  byte getGearRightPositionPct() { return gearRightPositionPct; };
  byte getGearTailPositionPct() { return gearTailPositionPct; };
  byte getGearAuxPosition() { return gearAuxPosition; };
  byte getGearTotalPct() { return gearTotalPct; };

  // Rudder/Trim
  int getAileronTrimPct() { return aileronTrimPct; };
  int getAileronTrimDegr() { return aileronTrimDegr; };
  int getRudderTrimDegr() { return rudderTrimDegr; };
  int getRudderTrimPct() { return rudderTrimPct; };
  int getElevatorTrimPos() { return elevatorTrimPos; };
  int getElevatorTrimPct() { return elevatorTrimPct; };

  // DME
  String getNavDme1() { return navDme1; };
  String getNavDme2() { return navDme2; };
  String getNavDmeSpeed1() { return navDmeSpeed1; };
  String getNavDmeSpeed2() { return navDmeSpeed2; };

  // ADF
  long getAdfActiveFreq1() { return adfActiveFreq1; };
  long getAdfStandbyFreq1() { return adfStandbyFreq1; };
  String getAdfRadial1() { return adfRadial1; };
  String getAdfSignal1() { return adfSignal1; };
  long getAdfActiveFreq2() { return adfActiveFreq2; };
  long getAdfStandbyFreq2() { return adfStandbyFreq2; };
  String getAdfRadial2() { return adfRadial2; };
  String getAdfSignal2() { return adfSignal2; };

  // Transponder
  String getTransponderCode1() { return transponderCode1; };
  String getTransponderCode2() { return transponderCode2; };
  bool getTransponderIdent1() { return transponderIdent1; };
  bool getTransponderIdent2() { return transponderIdent2; };
  uint8_t getTransponderState1() { return transponderState1; };
  uint8_t getTransponderState2() { return transponderState2; };

  // AP
  bool getAPAvailable() { return APAvailable; };
  bool getAPMasterOn() { return APMasterOn; };
  bool getAPWingLevelerOn() { return APWingLevelerOn; };
  bool getAPNav1LockOn() { return APNav1LockOn; };
  bool getAPHeadingLockOn() { return APHeadingLockOn; };
  bool getAPAltitudeLockOn() { return APAltitudeLockOn; };
  bool getAPAttitudeLockOn() { return APAttitudeLockOn; };
  bool getAPGlideslopeHoldOn() { return APGlideslopeHoldOn; };
  bool getAPApproachHoldOn() { return APApproachHoldOn; };
  bool getAPBackcourseHoldOn() { return APBackcourseHoldOn; };
  bool getAPFlightDirectorOn() { return APFlightDirectorOn; };
  bool getAPAirspeedHoldOn() { return APAirspeedHoldOn; };
  bool getAPMachHoldOn() { return APMachHoldOn; };
  bool getAPYawDampenerOn() { return APYawDampenerOn; };
  bool getAPAutothrottleArm() { return APAutothrottleArm; };
  bool getAPTakeoffPowerOn() { return APTakeoffPowerOn; };
  bool getAPAutothrottleOn() { return APAutothrottleOn; };
  bool getAPVerticalHoldOn() { return APVerticalHoldOn; };
  bool getAPRPMHoldOn() { return APRPMHoldOn; };

  bool getParkingBrakeIndicator() { return parkingBrakeIndicator; };

  byte getFuelTankCenterLevel() { return fuelTankCenterLevel; };
  byte getFuelTankCenter2Level() { return fuelTankCenter2Level; };
  byte getFuelTankCenter3Level() { return fuelTankCenter3Level; };
  byte getFuelTankLeftMainLevel() { return fuelTankLeftMainLevel; };
  byte getFuelTankLeftAuxLevel() { return fuelTankLeftAuxLevel; };
  byte getFuelTankLeftTipLevel() { return fuelTankLeftTipLevel; };
  byte getFuelTankRightMainLevel() { return fuelTankRightMainLevel; };
  byte getFuelTankRightAuxLevel() { return fuelTankRightAuxLevel; };
  byte getFuelTankRightTipLevel() { return fuelTankRightTipLevel; };
  byte getFuelTankExternal1Level() { return fuelTankExternal1Level; };
  byte getFuelTankExternal2Level() { return fuelTankExternal2Level; };

  int getFuelTankCenter() { return fuelTankCenterCapacity; };
  int getFuelTankCenter2() { return fuelTankCenter2Capacity; };
  int getFuelTankCenter3() { return fuelTankCenter3Capacity; };
  int getFuelTankLeftMainCapacity() { return fuelTankLeftMainCapacity; };
  int getFuelTankLeftAuxCapacity() { return fuelTankLeftAuxCapacity; };
  int getFuelTankLeftTipCapacity() { return fuelTankLeftTipCapacity; };
  int getFuelTankRightMainCapacity() { return fuelTankRightMainCapacity; };
  int getFuelTankRightAuxCapacity() { return fuelTankRightAuxCapacity; };
  int getFuelTankRightTipCapacity() { return fuelTankRightTipCapacity; };
  int getFuelTankExternal1Capacity() { return fuelTankExternal1Capacity; };
  int getFuelTankExternal2Capacity() { return fuelTankExternal2Capacity; };
  float getFuelTankLeftCapacity() { return fuelTankLeftCapacity; };
  float getFuelTankRightCapacity() { return fuelTankRightCapacity; };
  int getFuelTankCenterQuantity() { return fuelTankCenterQuantity; };
  int getFuelTankCenter2Quantity() { return fuelTankCenter2Quantity; };
  int getFuelTankCenter3Quantity() { return fuelTankCenter3Quantity; };
  int getFuelTankLeftMainQuantity() { return fuelTankLeftMainQuantity; };
  int getFuelTankLeftAuxQuantity() { return fuelTankLeftAuxQuantity; };
  int getFuelTankLeftTipQuantity() { return fuelTankLeftTipQuantity; };
  int getFuelTankRightMainQuantity() { return fuelTankRightMainQuantity; };
  int getFuelTankRightAuxQuantity() { return fuelTankRightAuxQuantity; }
  int getFuelTankRightTipQuantity() { return fuelTankRightTipQuantity; };
  int getFuelTankExternal1Quantity() { return fuelTankExternal1Quantity; };
  int getFuelTankExternal2Quantity() { return fuelTankExternal2Quantity; };
  float getFuelTankLeftQuantity() { return fuelTankLeftQuantity; };
  float getFuelTankRightQuantity() { return fuelTankRightQuantity; };
  int getFuelTankTotalQuantity() { return fuelTankTotalQuantity; };

  float getAmbientTemperature() { return ambientTemperature; };
  int getAmbientPressure() { return ambientPressure; };
  float getAmbientWindVelocity() { return ambientWindVelocity; };
  int getAmbientWindDirection() { return ambientWindDirection; };
  int getAmbientPrecipRate() { return ambientPrecipRate; };
  int getAmbientPrecipState() { return ambientPrecipState; };

  int getHeadingGyro() { return headingGyro; };
  int getHeadingMag() { return headingMag; };
  int getHeadingTrue() { return headingTrue; };

  bool getMasterWarningOn() const { return masterWarningOn; };

  bool getMasterCautionOn() const { return masterCautionOn; };

  // Plane data
  String getPlaneName() { return planeName; };

  //--------------------------------------------
  // TRANSMIT DATA
  // These values can be retrieved to assure user is not able to overwrite the
  // data These functions are mainly implemented to improve readability of your
  // code
  // AP

  // library-accessible "private" interface

  int smoothPot(byte potPin);
  // Time data

  String getZuluTime() { return zuluTime; };
  int getTimezoneOffset() { return timezoneOffset; };
  String getLocalTime() { return localTime; };

  // DO NOT REMOVE THIS COMMENT ITS USED BY THE CONNECTOR TO GENERATE CUSTOM
  // EVENTS
  // START GETTER TEMPLATE
  // END GETTER TEMPLATE

private:
  int fuelLevel;
  //--------------------------------------------
  // TRANSMIT DATA
  // These values can be ommited and printed to serial directly
  // They are mainly implemented to improve readability of your code

  Stream *serial;

  int analogDiff = 1;

  byte lastPrefix = 0;

  String inputText;
  String convertToFreq(const String &unprocFreq);
  String convertToNavFreq(const String &unprocFreq);
  bool masterWarningOn = false;
  bool masterCautionOn = false;

  int apVerticalSpeed;
  int kohlmanAltimeter;
  int barPressure;
  long int apAltLock;
  int apHeadingLock;

  int indicatedAirspeed;
  int varometerRate;
  int indicatedAltitude;
  int indicatedAltitude2;
  int indicatedAltitudeCalibrated;
  int indicatedHeading;
  int indicatedGPSGroundspeed;
  int trueVerticalSpeed;

  int headingGyro;
  int headingMag;
  int headingTrue;

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

  // ambient
  float ambientTemperature;
  int ambientPressure;
  float ambientWindVelocity;
  int ambientWindDirection;
  int ambientPrecipRate;
  int ambientPrecipState;

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

  byte fuelTankCenterLevel;
  byte fuelTankCenter2Level;
  byte fuelTankCenter3Level;
  byte fuelTankLeftMainLevel;
  byte fuelTankLeftAuxLevel;
  byte fuelTankLeftTipLevel;
  byte fuelTankRightMainLevel;
  byte fuelTankRightAuxLevel;
  byte fuelTankRightTipLevel;
  byte fuelTankExternal1Level;
  byte fuelTankExternal2Level;

  // warnings
  bool stallWarning = false;
  bool overspeedWarning = false;

  int fuelTotalPercentage;

  char valuesBuffer[40];

  bool advanced;
  int engine1 = 0;
  int engine2 = 0;
  int engine3 = 0;
  int engine4 = 0;

  int elevator = 0;
  int aileron = 0;
  int elevatorPercentage = 0;
  int aileronPercentage = 0;
  int oldElevator = 0;
  int oldAileron = 0;

  int prop1 = 0;
  int prop2 = 0;

  int engines[4] = {0, 0, 0, 0};
  int mixturePercentage[4] = {0, 0, 0, 0};
  int props[4] = {0, 0, 0, 0};

  int flaps;
  int oldFlaps;

  int value;
  int oldValue;

  int navObs1;
  int navObs2;

  int propValue1;
  int propValue2;
  int propValue3;
  int propValue4;
  int oldPropValue1;
  int oldPropValue2;
  int oldPropValue3;
  int oldPropValue4;

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
  int mixtureValue3;
  int mixtureValue4;
  int oldMixtureValue1;
  int oldMixtureValue2;
  int oldMixtureValue3;
  int oldMixtureValue4;

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
  long activeCom1;
  long activeCom2;
  long standByCom1;
  long standByCom2;
  long activeNav1;
  long activeNav2;
  long standbyNav1;
  long standbyNav2;
  String navRadialError1;
  String navVorLationalt1;

  // GPS
  int gpsCourseToSteer;

  // DME
  String navDme1 = "";
  String navDme2 = "";
  String navDmeSpeed1 = "";
  String navDmeSpeed2 = "";

  // ADF
  long adfActiveFreq1 = 0;
  long adfStandbyFreq1 = 0;
  String adfRadial1 = "";
  String adfSignal1 = "";
  long adfActiveFreq2 = 0;
  long adfStandbyFreq2 = 0;
  String adfRadial2 = "";
  String adfSignal2 = "";

  // time
  String zuluTime = "";
  int timezoneOffset;
  String localTime = "";

  // Transponder
  String transponderCode1 = "";
  String transponderCode2 = "";
  bool transponderIdent1 = false;
  bool transponderIdent2 = false;
  uint8_t transponderState1 = 0;
  uint8_t transponderState2 = 0;

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

  bool parkingBrakeIndicator;

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

  int fuelTankCenterCapacity;
  int fuelTankCenter2Capacity;
  int fuelTankCenter3Capacity;
  int fuelTankLeftMainCapacity;
  int fuelTankLeftAuxCapacity;
  int fuelTankLeftTipCapacity;
  int fuelTankRightMainCapacity;
  int fuelTankRightAuxCapacity;
  int fuelTankRightTipCapacity;
  int fuelTankExternal1Capacity;
  int fuelTankExternal2Capacity;
  float fuelTankLeftCapacity;
  float fuelTankRightCapacity;
  int fuelTankCenterQuantity;
  int fuelTankCenter2Quantity;
  int fuelTankCenter3Quantity;
  int fuelTankLeftMainQuantity;
  int fuelTankLeftAuxQuantity;
  int fuelTankLeftTipQuantity;
  int fuelTankRightMainQuantity;
  int fuelTankRightAuxQuantity;
  int fuelTankRightTipQuantity;
  int fuelTankExternal1Quantity;
  int fuelTankExternal2Quantity;
  float fuelTankLeftQuantity;
  float fuelTankRightQuantity;
  int fuelTankTotalQuantity;

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
  int average = 0;
  int total = 0;

  // DO NOT REMOVE THIS COMMENT ITS USED BY THE CONNECTOR TO GENERATE CUSTOM
  // EVENTS
  // START VAR TEMPLATE
  // END VAR TEMPLATE
  static const int samples = 10;
};

#endif
