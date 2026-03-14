//CWIR3
//written for ESP32 DOIT DEVKIT V1


#include<DHT.h>
#include<Adafruit_SSD1306.h>

#define OLED_RESET 4

Adafruit_SSD1306 oled(OLED_RESET);

#define Type DHT11

int sensePin = 26;

float tempC;
float tempF;
float humidity;

DHT sensor(sensePin, Type);

void setup(){

  Serial.begin(115200);
  sensor.begin();

  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  oled.clearDisplay();
  delay(1000);
}

void loop(){

  tempC = sensor.readTemperature();
  tempF = sensor.readTemperature(true);
  humidity = sensor.readHumidity();

  Serial.print("Temperature at  ");
  Serial.print(tempC );
  Serial.print(" C");
  Serial.print(" or ");
  Serial.print(tempF);
  Serial.println(" F"); 
  Serial.print("Humidity: ");
  Serial.println(humidity);
  Serial.println();

  oled.setTextSize(3);
  oled.setTextColor(WHITE);
  oled.setCursor(0,0);
  
  oled.print( tempC);
  oled.println();
  oled.display();

  
  delay(500);

  oled.clearDisplay();
  
}
