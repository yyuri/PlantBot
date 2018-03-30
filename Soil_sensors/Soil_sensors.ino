

#include <SHT1x.h>   // SHT10 sensor Library



// Define Ambiental Sensor ( STH10, Humidity / Temp )

#define adataPin 10   // Ambiental Humidity data PIN //amarillo
#define aclockPin 11  // Ambiental Humidity clock PIN //azul

// DATA Yellow
// CLOCK Blue
// GROUND Black
// 5V o 3.3V Brown

#define sdataPin 10   // Soil Humidity sensor PIN
#define sclockPin 11  // Soil Humidity sensor PIN 
SHT1x ambiental(adataPin, aclockPin);
//SHT1x soil(sdataPin, sclockPin);




void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600); // Open serial connection to report values to host
   Serial.println("Starting up");
}

void loop() {
  // put your main code here, to run repeatedly:
  float atemp_c;
  float ahumidity;
  float temp_c;
  float humidity;
  // Read values from the sensor
  atemp_c = ambiental.readTemperatureC();
  ahumidity = ambiental.readHumidity();
  
  temp_c = ambiental.readTemperatureC();
  humidity = ambiental.readHumidity();


  // Print the values to the serial port
  Serial.print("Temperature: ");
  Serial.print(atemp_c, DEC);
  Serial.print("C / ");
  Serial.print("  Humidity: ");
  Serial.print(humidity);
  Serial.println("%");

delay(2000);

}
