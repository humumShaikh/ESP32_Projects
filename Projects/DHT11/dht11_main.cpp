//CWIR3
//Written for ESP32 DOIT DEVKIT V1

//This is the program to configure the DHT 11 temperature and humidity sensor with the ESP32 //
#include <DHT.h> //This is the header file for the DHT and you need to install the libraries seperately//

#define Type DHT11 //Need to define the sensor Type//

int sensePin = 26; //Creating an integer to store the pin no in case we change the pin later then we only need to change it from here//

float  TempC; //Creating a float to store the temperature(celsius) value since temperatures aren't normally natural numbers// 
float  TempF; //Creating a float to store the temperature(fahrenheit) value //
float  Humidity; //Creating a flot to store the humidity//

DHT sensor(sensePin, Type); //Defining the controller clasee that is 'DHT' and creating a virtual object and naming it as 'sensor' //

void setup(){

  Serial.begin(115200); //Beginning the serial at 115200 baud rate//
  sensor.begin(); //Beginning the sensor//
}

void loop(){

  TempC = sensor.readTemperature(); //Assigning the float 'TempC' to the temperature reading from the sensor//
  TempF = sensor.readTemperature(true); //Assigning the float 'TempF' to the temperature reading from the sensor, note that if we want to get the reading in fahrenheit we have to use (true) as shown//
  Humidity = sensor.readHumidity(); //Assigning the float 'Humidity' to the temperature reading from the sensor//

  Serial.print("Temperature: "); //Print //
  Serial.print(TempC);
  Serial.println(" C");

  Serial.print("Temperature: ");
  Serial.print(TempF);
  Serial.println(" F");

  Serial.print("Humidity: ");
  Serial.println(Humidity);

  delay(2000);
  
}
