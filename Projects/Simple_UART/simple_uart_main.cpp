#define RxPin 16
#define TxPin 17

void setup(){
  Serial.begin(115200);
  Serial2.begin(115200, SERIAL_8N1, RxPin, TxPin);
}

void loop(){
  String message = Serial2.readString();
  Serial.println(message);
}




///for arduino///

void setup(){
  Serial.begin(115200);
}

void loop(){
  Serial.println("This is Arduino Speaking");
  delay(1500);
}