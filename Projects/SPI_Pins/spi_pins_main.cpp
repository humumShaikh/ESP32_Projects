//CWIR3
//written for ESP32 DOIT DEVKIT V1

void setup(){

  Serial.begin(115200);

  Serial.print("MOSI : "); //usually 23//
  Serial.println(MOSI);
  
  Serial.print("MISO : "); //usually 19//
  Serial.println(MISO);

  Serial.print("SCK : "); //usually 18//
  Serial.println(SCK);

  Serial.print("SS : "); //usually 5//
  Serial.println(SS);
}

void loop(){
  
}
