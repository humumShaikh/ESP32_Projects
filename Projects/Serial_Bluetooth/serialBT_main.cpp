#include<BluetoothSerial.h>

BluetoothSerial SerialBT;

int code;

int relayPin=14;

void setup() {

  Serial.begin(115200);
  SerialBT.begin("ESP32 ROBOT");
  Serial.println("Bluetooth has started");
  SerialBT.println("Bluetooth has started");
  pinMode(LED_BUILTIN,OUTPUT);
}

void loop() {

  SerialBT.println("Enter the Code: ");

  while (SerialBT.available()==0){
    
  }

  code=SerialBT.parseInt();

  if (code==69){
    digitalWrite(LED_BUILTIN,HIGH);
  }

  if (code==66){
    digitalWrite(LED_BUILTIN,LOW);
  }
  
}
