#include <Servo.h>
#include <Adafruit_SH1106.h>

#define OLED_SDA 21
#define OLED_SCL 22

int servoPin = 16;

int servoPos = 180;

Servo servo1;
Adafruit_SH1106 oled(21,22);

void setup(){
  
  Serial.begin(115200);

  oled.begin(SH1106_SWITCHCAPVCC,0x3C);
  oled.clearDisplay();

  servo1.attach(servoPin);
}

void loop(){

  oled.setTextSize(1);
  oled.setTextColor(WHITE);
  oled.setCursor(0,0);
  oled.print("Servo Position : ");
  oled.print(servoPos);
  oled.drawCircle(123, 2, 2, WHITE);
  oled.display();
  delay(10);
  oled.clearDisplay();
}
