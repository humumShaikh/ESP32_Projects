#include <Arduino.h>

#define lightSensor 2

void setup()
{
  Serial.begin(115200);

  pinMode(lightSensor , INPUT);
}

void loop()
{

  int val = analogRead(lightSensor);
  delay(200);
  Serial.print("Light Value : ");
  Serial.println(val);

}