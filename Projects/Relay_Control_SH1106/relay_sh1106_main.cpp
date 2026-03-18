//CWIR3
//written for ESP32 DOIT DEVKIT V1


#include<Adafruit_SH1106.h>

#define OLED_SDA 21
#define OLED_SCL 22

int relayPin = 14;

Adafruit_SH1106 oled(21,22);

void setup(){

  Serial.begin(115200);
  oled.begin(SH1106_SWITCHCAPVCC, 0x3C);
  oled.clearDisplay();

  pinMode(relayPin,OUTPUT);
  
  digitalWrite(relayPin,LOW);

  delay(2000);
}

void loop(){
  
  oled.setTextSize(1);
  oled.setTextColor(WHITE);
  
  oled.clearDisplay();
  oled.setCursor(0,0);
  digitalWrite(relayPin,HIGH);
  oled.println("RELAY IS ON");
  oled.display(); 
  Serial.println("RELAY IS ON");
  delay(1000);
 
  oled.clearDisplay();
  oled.setCursor(0,0);
  digitalWrite(relayPin,LOW);
  oled.println("RELAY IS OFF");
  oled.display();
  Serial.println("RELAY IS OFF");
  delay(1000);

}
