#include <Arduino.h>

void setup() 
{

  Serial.begin(115200);

}


void loop() 
{

  float temperature = temperatureRead(); // Reads internal temperature
  Serial.print("Internal Chip Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  delay(400);
}