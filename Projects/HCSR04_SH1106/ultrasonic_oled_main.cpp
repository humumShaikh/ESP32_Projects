86% of storage used … If you run out of space, you can't save to Drive, back up Google Photos, or use Gmail.
#include<Adafruit_SH1106.h>

#define OLED_SDA 21
#define OLED_SCL 22

int trigPin=25;
int echoPin=3;

int pingTravelTime;
float pingTravelDistance;
float targetDistance;

Adafruit_SH1106 oled(21,22);

void setup(){

  Serial.begin(115200);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  oled.begin(SH1106_SWITCHCAPVCC, 0x3C);
  oled.clearDisplay();
}

void loop(){

   digitalWrite(trigPin,LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  pingTravelTime = pulseIn(echoPin,HIGH);

  pingTravelDistance = 0.0348*pingTravelTime;

  targetDistance = pingTravelDistance/2;

  Serial.print("Distance: ");
  Serial.print(targetDistance);
  Serial.println(" cm");
  Serial.println();


  oled.setTextSize(1);
  oled.setTextColor(WHITE);
  oled.setCursor(0,0);
  oled.print("Distance: ");
  oled.print(targetDistance);
  oled.println(" cm");
  oled.display();
  delay(100);
  oled.clearDisplay();

}
