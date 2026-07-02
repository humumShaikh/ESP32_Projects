#include <Arduino.h>
#include <LSM303AGR_ACC_Sensor.h>

#define DEV_I2C Wire // Define I2C bus

LSM303AGR_ACC_Sensor Acc(&DEV_I2C);
// Sensitivity for LSM303AGR (for ±2g mode: 1 mg/digit)

#define ACC_SENSITIVITY 0.001 // 1 mg = 0.001 g

void setup() 
{

  Serial.begin(115200);
  DEV_I2C.begin();
  // Initialize the accelerometer
  Acc.begin();
  Acc.Enable(); 

}


void loop() 
{

  int accelerometer[3];
  Acc.GetAxes(accelerometer); // Get raw acceleration data
  // Convert raw values to 'g' (gravity acceleration)
  float Ax = accelerometer[0] * ACC_SENSITIVITY;
  float Ay = accelerometer[1] * ACC_SENSITIVITY;
  float Az = accelerometer[2] * ACC_SENSITIVITY;
  // Display results
  Serial.print("Acceleration (g) - X: ");
  Serial.print(Ax, 4);
  Serial.print(", Y: ");
  Serial.print(Ay, 4);
  Serial.print(", Z: ");
  Serial.print(Az, 4);
  Serial.println();
  delay(100);

}