
#include <BitsAndDroidsFlightConnector.h>
BitsAndDroidsFlightConnector connector = BitsAndDroidsFlightConnector();

int potPin = A0;
int potPin2 = A1;

void setup() {
  
  pinMode(potPin, INPUT);
  Serial.begin(115200);
 
}

void loop() {
 
 //connector.connector.simpleInputHandling(1 Throttle to rule them all (just the pin), max value);
 connector.simpleInputHandling(potPin);

 //connector.advancedInputHandling(Pin of Engine 1,Pin of Engine 2,Pin of Engine 3,Pin of Engine 4);
 //connector.mixtureInputHandling(potPin, potPin);
 //connector.propsInputHandling(potPin, potPin);
 //delay(400);


}
