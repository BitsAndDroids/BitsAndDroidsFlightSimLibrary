//DONT FORGET TO ADD A 10Uf capacitor after installing the sketch between ground and the reset pin on the board
#include <BitsAndDroidsFlightConnector.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//create a new connector flase = Uno/Mega, True = Leonardo/Pro Micro
BitsAndDroidsFlightConnector connector(false);
//16x2 I2C display
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
  //This can be left out if you use an Leonardo/Pro micro
  Serial.begin(115200);
  Serial.setTimeout(50);
}

void loop() {
  //start the data processing
   connector.dataHandling();
  
   lcd.setCursor(0,0);
   //retrieve active com 1 from the connector
   lcd.print(connector.getActiveCom1());
   lcd.setCursor(0,1);
     //retrieve active com 2 from the connector
   lcd.print(connector.getActiveCom2());
   lcd.setCursor(8,0);
     //retrieve standby com 1 from the connector
   lcd.print(connector.getStandbyCom1());
   lcd.setCursor(8,1);
   //retrieve standby com 2 from the connector
   lcd.print(connector.getStandbyCom2());
}

  
