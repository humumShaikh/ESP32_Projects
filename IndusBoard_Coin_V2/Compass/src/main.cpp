//Written for ESP32 S2 Mini 2U 
//Install the LSM303AGR Sensor library seperately

#include <Arduino.h>
#include <LSM303AGR_MAG_Sensor.h>

LSM303AGR_MAG_Sensor Mag(&Wire);

void setup() {
  Serial.begin(115200);
  Wire.begin();
  Mag.begin();
  Mag.Enable();
}

void loop() {
  int32_t mag[3];
  Mag.GetAxes(mag);

  // Calculate heading cleanly in a single line
  float heading = atan2(mag[1], mag[0]) * 180.0 / M_PI;
  heading = (heading < 0) ? (heading + 360) : heading;

  // Compact terminal output
  Serial.print("Heading: ");
  Serial.println(heading, 1);
  
  delay(150);
}
