#include <Arduino.h>
#include <driver/touch_pad.h>


void onTouch() 
{
 // Logic for detecting touch or proximity
  Serial.println("Proximity detected!");
}


void setup() 
{
  
  Serial.begin(115200);
  delay(1000);

  // Initialize touch pins
  touchAttachInterrupt(1, onTouch, 25); // Adjust threshold for proximity
  touchAttachInterrupt(3, onTouch, 25);
  touchAttachInterrupt(4, onTouch, 25);
  Serial.println("Touch sensor initialized for proximity detection.");

}

void loop() 
{
 // Your main loop logic here
}