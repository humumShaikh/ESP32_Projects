#include <Arduino.h>
#include <LSM303AGR_ACC_Sensor.h>

#define DEV_I2C Wire // Define I2C bus

LSM303AGR_ACC_Sensor Acc(&DEV_I2C);
// Sensitivity for LSM303AGR (for ±2g mode: 1 mg/digit)


void setup() 
{
 Serial.begin(115200);
 DEV_I2C.begin();
 // Initialize the accelerometer
 Acc.begin();
 Acc.Enable();
 Acc.EnableTemperatureSensor(); // Enable temperature sensor
}


void loop() 
{
 float temperature;
 Acc.GetTemperature(&temperature); // Get temperature data
 Serial.print(" | Temp (°C): ");
 Serial.print(temperature, 2);
 Serial.println();
 delay(100);
}