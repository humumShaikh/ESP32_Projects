//CWIR3

#include <Arduino.h>

void setup()
{
  Serial.begin(115200);
  pinMode(33 , OUTPUT);
  delay(2000);
  Serial.println("Programmed Successfully \n");
}

void loop()
{
  digitalWrite(33 , HIGH);
  Serial.println("ON \n");
  delay(100);
  digitalWrite(33 , LOW);
  Serial.println("OFF \n");
  delay(100);
}
