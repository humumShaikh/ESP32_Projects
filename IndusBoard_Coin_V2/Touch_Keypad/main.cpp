#include <Arduino.h>


const int num_keys = 10;
int touch_pins[num_keys] = { 1, 3, 4, 7, 6, 5, 10, 11, 12,
13 };

// int baseline;

// void calibrate_baselines() {
//  // Optional: Calibrate and print baselines (can be removed
// // if not needed)

//  for (int i = 0; i < num_keys; i++) {
//  uint32_t sum = 0;
//  // Average 100 readings for stable baseline
//  for (int j = 0; j < 100; j++) {
//  sum += touchRead(touch_pins[i]);
//  delay(2); // Short delay between reads
//  }
//  baseline = sum / 100;
//  Serial.print("Baseline for pin ");
//  Serial.print(touch_pins[i]);
//  Serial.print(": ");
//  Serial.println(baseline);
//  }
//  Serial.println("Calibration complete.");
// }


void setup()
{

  Serial.begin(115200);

  // calibrate_baselines(); 

}


void loop()
{

  int value = touchRead(touch_pins[8]);
  Serial.println(value); 

}
