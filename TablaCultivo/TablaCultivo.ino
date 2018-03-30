#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);





                                    
#define ONEMIN (1000UL * 60 * 1)
#define FIVEMIN (1000UL * 60 * 5)

unsigned long rolltime1 = millis() + ONEMIN;
unsigned long rolltime5 = millis() + FIVEMIN;


float hoursoflight=14;  // 1 minute = 0.0166667 hours
const int daylenght=24;   // Duration of the days
int day=0;          // Initial DAY
int minmoist = 100; //Min moisture value
int maxmoist = 500; //Max moisture value
int idealtemp = 25; //Ideal ambiental temperature in Celsius

const long lightinterval = 3600000*hoursoflight;
const long darkinterval =  3600000*daylenght-lightinterval;

        

                                                                                          //////////////////////Pins of sensors and motors //////////////////////////

// Define Waterpump power and time values

int waterPin = A0; // pin that turns on the waterpump
int waterinterval = 1; // how long to water in minutes

// Define Moisture sensor power and values

int soilmoisture = 0; //value for storing moisture value 
int soilPin = A1;//Declare a variable for the soil moisture sensor 
int soilPower = 7;//Variable for Soil moisture Power

//Rather than powering the sensor through the 3.3V or 5V pins, 
//we'll use a digital pin to power the sensor. This will 
//prevent corrosion of the sensor as it sits in the soil. 


// Define Ambiental Sensor ( STH10, Humidity / Temp )

#define adataPin 10   // Ambiental Humidity data PIN 
#define aclockPin 11  // Ambiental Humidity clock PIN 

int atempPin = 0;
float atempread = 0;
int atempPin = 0;
float atempread = 0;

// Define heater power

int heatPin = A2; // pin that turns on the waterpump

// Define Light power 

int lightPin = A3;














void setup() {
  Serial.begin(9600);
  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)
  // init done
  display.clearDisplay();
  // draw the first ~12 characters in the font
  display.setTextSize(2);
  display.setTextColor(WHITE);

  display.setCursor(20,10);
  display.println("PLANTBOT");
  display.setCursor(54,25);
  display.setTextSize(1);

  display.println("v.0.1");
  display.display();
  display.display();
}

void loop() {

  
// Stuff we check every 1 minutes

  if((long)(millis() - rolltime1) >= 0) {
   //  Take data from sensors every ONEMIN
   rolltime1 += ONEMIN;
  display.clearDisplay();

   firstscreen();   // We should send temp, h_s, h_a
  





    
 }


 
// Stuff we check every 5 minutes

  if((long)(millis() - rolltime5) >= 0) {
   //  Take data from sensors every FIVEMIN
   rolltime1 += FIVEMIN;






    
 }


  

}







int readSoil()
{
    int val;
    digitalWrite(soilPower, HIGH);//turn D7 "On"
    delay(10);//wait 10 milliseconds 
    val = analogRead(soilPin);//Read the SIG value form sensor 
    digitalWrite(soilPower, LOW);//turn D7 "Off"
    return val;//send current moisture value
}
int readTemp()
{
    int  reading = analogRead(tempPin);  
    // converting that reading to voltage, for 3.3v arduino use 3.3
    float voltage = tempread * 5.0;
    voltage /= 1024.0; 
    float temperatureC = (voltage - 0.5) * 100 ;
    return temperatureC; //send current Temp value in Celsius

}









    // SCREEN VALUES
void firstscreen() {


  // text display tests
  display.setTextSize(1);
    display.setTextColor(WHITE);

  display.setCursor(0,0);
  display.println("Luces:");
  display.setTextSize(1);
  display.setCursor(40,0);
  display.println("ON");
  display.setCursor(80,0);
  display.println("Dia: 1");
  display.drawLine(0, 7, 128, 7, WHITE);
  display.drawLine(64, 7, 64, 64, WHITE);


  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,10);
  display.println("Hs:");
  display.setCursor(26,10);
  display.println("60 %");

  display.drawLine(0, 20, 64, 20, WHITE);
  
  display.setCursor(0,24);
  display.println("Ha:");
  display.setCursor(26,24);
  display.println("50 %");
////////////////////////////////

  display.setCursor(70,16);
  display.println("T:");


  display.setCursor(95,12);
  display.setTextSize(2);
  display.println("22");

  display.display();

}

void secondscreen() {

  
      // Head   //
      
  display.clearDisplay();
  // text display tests
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Luces:");
  display.setTextSize(1);
  display.setCursor(40,0);
  display.println("ON");
  display.setCursor(90,0);
  display.println("Dia: 1");
  display.drawLine(0, 7, 128, 7, WHITE);
  display.drawLine(64, 7, 64, 64, WHITE);
  
      // Head end //

      // Body     //

  display.drawLine(0, 16, 128, 16, WHITE);

  display.setCursor(24,8);
  display.println("PH");


  display.setCursor(14,18);
  display.setTextSize(2);
  display.println("7.4");
////////////////////////////////
  display.drawLine(6, 16, 122, 16, WHITE);
  display.setTextSize(1);

  display.setCursor(78,8);
  display.println("Heater");


  display.setCursor(80,18);
  display.setTextSize(2);
  display.println("OFF");

  display.display();

        // END     //
}



