// Pinouts //
//RFID Reader    -    ESP32 //
// SDA           -     IO5 //
// SCK           -     IO18 //
// MOSI          -     IO23 //
// MISO          -     IO19 //

#include <SPI.h>
#include <MFRC522.h>
#include <Adafruit_SH1106.h>
#include <Servo.h>

#define OLED_SDA 21
#define OLED_SCL 22
 
#define SS_PIN 5
#define RST_PIN 0

Adafruit_SH1106 oled(21,22);
Servo servo1;
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.

int relayPin = 14;
int buzzerPin = 25;
int servoPin = 16;
 
void setup() 
{
  Serial.begin(115200);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Approximate your card to the reader...");
  Serial.println();
  pinMode(relayPin,OUTPUT);
  pinMode(buzzerPin,OUTPUT);

  servo1.attach(servoPin);
  
  oled.begin(SH1106_SWITCHCAPVCC, 0x3C);
  oled.clearDisplay();
  servo1.write(0);

}
void loop() 
{

  oled.setTextColor(WHITE);
  oled.setTextSize(1);
  oled.setCursor(30,32);
  oled.println("READY TO SCAN");
  oled.display();
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "53 0A EF 31" ) //change here the UID of the card/cards that you want to give access
  {
    Serial.println("Authorized access");
    Serial.println();
    digitalWrite(relayPin,HIGH);
    servo1.write(90);
    oled.clearDisplay();
    oled.setTextSize(1);
    oled.setTextColor(WHITE);
    oled.setCursor(20,32);
    oled.println("AUTHORIZED ACCESS");
    oled.display();
    delay(3000);
    digitalWrite(relayPin,LOW);
    servo1.write(0);
    oled.clearDisplay();
    oled.setCursor(30,32);
    oled.println("READY TO SCAN");
    oled.display();

  }
 
 else   {
    Serial.println(" Access denied");
    digitalWrite(buzzerPin,HIGH);
    oled.clearDisplay();
    oled.setTextSize(1);
    oled.setTextColor(WHITE);
    oled.setCursor(30,32);
    oled.println("ACCESS DENIED");
    oled.display();
    delay(3000);
    digitalWrite(buzzerPin,LOW);
    oled.clearDisplay();
    oled.setCursor(30,32);
    oled.println("READY TO SCAN");
    oled.display();
  }
} 
