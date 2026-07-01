#include <Arduino.h>
#include<Adafruit_SSD1306.h>

#define OLED_RESET 4
#define OLED_ADDRESS 0x3C
Adafruit_SSD1306 OLED(OLED_RESET);




const int num_keys = 10;
int touch_pins[num_keys] = { 1, 3, 4, 7, 6, 5, 10, 11, 12,
13 };

int baseline;

void calibrate_baselines() {
 // Optional: Calibrate and print baselines (can be removed
// if not needed)

 for (int i = 0; i < num_keys; i++) {
 uint32_t sum = 0;
 // Average 100 readings for stable baseline
 for (int j = 0; j < 100; j++) {
 sum += touchRead(touch_pins[i]);
 delay(2); // Short delay between reads
 }
 baseline = sum / 100;
 Serial.print("Baseline for pin ");
 Serial.print(touch_pins[i]);
 Serial.print(": ");
 Serial.println(baseline);
 }
 Serial.println("Calibration complete.");
}


void setup()
{

  Serial.begin(115200);

  OLED.begin(SSD1306_SWITCHCAPVCC , OLED_ADDRESS);
  OLED.clearDisplay();

  calibrate_baselines(); 

}


void loop()
{

  OLED.setTextSize(2); 
  OLED.setTextColor(WHITE);
  OLED.setCursor(0,0); 
  OLED.println("AI&QT"); 
  OLED.display();

  int value = touchRead(touch_pins[8]);
  Serial.println(value); 

}