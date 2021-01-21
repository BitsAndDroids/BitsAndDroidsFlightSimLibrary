
#include <BitsAndDroidsFlightConnector.h>
BitsAndDroidsFlightConnector connector = BitsAndDroidsFlightConnector(true);

int potPin = A0;
int potPin2 = A1;

void setup() {
  
  pinMode(potPin, INPUT);
  Serial.begin(115200);
 
}

void loop() {
 
 //connector.connector.simpleInputHandling(1 Throttle to rule them all (just the pin), max value);
 connector.simpleInputHandling(potPin, 1023);

 //connector.advancedInputHandling(Pin of Engine 1,Pin of Engine 2,Pin of Engine 3,Pin of Engine 4,Pin of mixture, max value);
 //connector.advancedInputHandling(A0,A0,A1,A1,A1,1023);
 
 
 //supersuperAdvancedInputHandling(int percentage eng1,int percentage eng2,int percentage eng3, int percentage eng4, int percentageMixture)
 //int value = analogRead(potPin);
 //connector.superAdvancedInputHandling(value,80,80,80,80);
 //delay(400);


}
