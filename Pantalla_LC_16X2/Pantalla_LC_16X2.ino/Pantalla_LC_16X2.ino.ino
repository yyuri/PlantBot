
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR    0x3F  // Define I2C Address where the SainSmart LCD is
#define BACKLIGHT_PIN     3
#define En_pin  2
#define Rw_pin  1
#define Rs_pin  0
#define D4_pin  4
#define D5_pin  5
#define D6_pin  6
#define D7_pin  7

LiquidCrystal_I2C  lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);

void setup()
{
  lcd.begin (16,2);
 
  // Switch on the backlight
  lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
  lcd.setBacklight(HIGH);

  // Position cursor and write some text
  lcd.home ();                   // go to the first line, first character
  lcd.print("L = ON"); 
  lcd.setCursor ( 0, 1 );        // go to the 2nd line
  lcd.setCursor ( 0, 2 );        // go to the third line
  lcd.print("Temp = 25, Hum = 30");

}

void loop()
{

}

