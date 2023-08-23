#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "Adafruit_VL53L0X.h"

Adafruit_VL53L0X lox = Adafruit_VL53L0X();
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void setup() {
  // put your setup code here, to run once:
  IF (!lox.begin()){
    while(1)
  }
  lcd.begin(16,2);
  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear();
  VL53L0X_RangingMeasurementData_t measure;
  lox.ragingTest(&measure, false);

  if(measure.RangeStatus != 4){
    lcd.setCursor(2,0);
    lcd.print(measure.RangeMiliMeter);
    lcd.setCursor(5,0);
    lcd.print("mm");
    lcd.print(measure.RangeMiliMeter/10);
    lcd.setCursor(4,1);
    lcd.print("cm");
  } else {
    lcd.print("Fora de alcance!");
  }

  lcd.setCursor(5,0);
  lcd.print("mm");
  delay(500);
}
