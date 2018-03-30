#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);




void setup()   {                
  Serial.begin(9600);

  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)
  // init done
  
  // Show image buffer on the display hardware.
  // Since the buffer is intialized with an Adafruit splashscreen
  // internally, this will display the splashscreen.
  // Clear the buffer.
  display.clearDisplay();

  // draw the first ~12 characters in the font
  display.display();

  display.setTextSize(2);
    display.setTextColor(WHITE);

  display.setCursor(20,10);
  display.println("PLANTBOT");
  display.setCursor(54,25);
  display.setTextSize(1);

  display.println("v.0.1");
  display.display();


}


void loop() {
display.clearDisplay();
firstscreen();
delay(10000);
secondscreen();
delay(10000);
}

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


