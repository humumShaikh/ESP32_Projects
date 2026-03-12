//CWIR3

#include <Adafruit_SH1106.h>

#define SDA 21
#define SCL 22

int signalPin = 39;

int value;

Adafruit_SH1106 oled(21,22);

void setup(){
  oled.begin(SH1106_SWITCHCAPVCC, 0x3C);
  oled.clearDisplay();
    Serial.begin(115200);
  pinMode(signalPin,INPUT);
}

void loop(){

  value = analogRead(signalPin);

  Serial.print("Analog Value :  ");
  Serial.println(value);
  
  oled.setTextSize(1);
  oled.setTextColor(WHITE);
  oled.setCursor(0,0);
  oled.print("Analog Value :  ");
  oled.println(value);
  oled.display();
  delay(100);
  oled.clearDisplay();

}
