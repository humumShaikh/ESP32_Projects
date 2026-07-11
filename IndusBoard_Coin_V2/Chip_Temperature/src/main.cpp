//Written for ESP32 S2 Mini 2U
//Indusboard Coin v2

#include <Arduino.h>

void setup() 
{

  Serial.begin(115200);

}


void loop() 
{

  float temperature = temperatureRead(); // Reads internal temperature of the chip
  Serial.print("Internal Chip Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  delay(400);
}
