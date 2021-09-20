//**********************************************************************************//
//  G1000 PFD commands                                                              //
//  More commands for the MFD + G3000 available on                                  //
//  https://www.bitsanddroids.com/flight-sim-connector-library-documentation/       //
//  sendG1000PfdFlightplanButton,                                                   //
//  sendG1000PfdProcedureButton,                                                    //
//  sendG1000PfdZoominButton,                                                       //
//  sendG1000PfdZoomoutButton,                                                      //
//  sendG1000PfdDirectToButton,                                                     //
//  sendG1000PfdMenuButton,                                                         //
//  sendG1000PfdClearButton,                                                        //
//  sendG1000PfdEnterButton,                                                        //
//  sendG1000PfdCursorButton,                                                       //
//  sendG1000PfdGroupKnobInc,                                                       //
//  sendG1000PfdGroupKnobDec,                                                       //
//  sendG1000PfdPageKnobInc,                                                        //
//  sendG1000PfdPageKnobDec,                                                        // 
//  sendG1000PfdSoftkey1,                                                           //
//  sendG1000PfdSoftkey2,                                                           //
//  sendG1000PfdSoftkey3,                                                           //
//  sendG1000PfdSoftkey4,                                                           //
//  sendG1000PfdSoftkey5,                                                           //
//  sendG1000PfdSoftkey6,                                                           //
//  sendG1000PfdSoftkey7,                                                           //
//  sendG1000PfdSoftkey8,                                                           //
//  sendG1000PfdSoftkey9,                                                           //
//  sendG1000PfdSoftkey10,                                                          //
//  sendG1000PfdSoftkey11,                                                          //
//  sendG1000PfdSoftkey12,                                                          //
//**********************************************************************************//

#include<BitsAndDroidsFlightConnector.h>

//We create a connector object to send and receive commands
BitsAndDroidsFlightConnector connector = BitsAndDroidsFlightConnector();

//For this example I've added 2 pushbuttons on pin 4 and 5 using the internal pullup resistors
const byte exampleButtonA = 4;
const byte exampleButtonB = 5;


void setup() {
  //115200 To match the default connector baud rate. can be altered but please do so as well in the conenctor
  //FOR THIS TO WORK YOU NEED TO INSTALL THE BITSANDDROIDS WASM MODULE AS WELL
  Serial.begin(115200);
  pinMode(exampleButtonA, INPUT_PULLUP);
  pinMode(exampleButtonB, INPUT_PULLUP);
}

void loop() {

  if(digitalRead(exampleButtonA) == LOW){
    connector.send(sendG1000PfdFlightplanButton);
    //For debouncing reasons (other methods are possible)
    delay(100);
  }

  if(digitalRead(exampleButtonB) == LOW){
    connector.send(sendG1000PfdProcedureButton);
    delay(100);
  }

}
