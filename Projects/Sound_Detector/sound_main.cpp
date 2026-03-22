//This is the program to interface the KY-037 (sound detector module)//
//We will be using the analog output on the sensor//

int sensePin=36; //This is the GPIO on the ESP32 where the analog output is connected of the sound sensor//
int ledPin=23; // For controlling an LED on detecting sound//


int sound; //Making a variable for storing the sound value//

void setup(){

  Serial.begin(115200); //Starting the serial monitor at a baud rate of 115200 //
  pinMode(sensePin,INPUT); //Setting GPIO 36 as the input pin//
  pinMode(ledPin,OUTPUT); //Setting the GPIO 23 as the output pin//
  
}

void loop(){

  sound = analogRead(sensePin); //Instructing the controller to read the analog value on the sensePin (36) and store it in the variable 'sound' //
  Serial.println(sound); //Printing the value on the serial monitor//


  //NOW WHAT YOU HAVE TO DO IS, FIRST CONNECT THE SENSOR AND CHECK THE VALUES ON THE SERIAL MONITOR//
  //THE VALUES WILL BE FLUCTUATING AS THERE IS NOISE IN THE SIGNAL OR THE BACKGROUND//
  //BUT THE FLUCTUATIONS WILL BE IN A RANGE OF +- 15 OR WHATEVER IT MIGHT BE, NOTE IT//
  //THEN MAKE SOUNDS NEAR THE MICCROPHONE OF THE SENSOR (SOUNDS ON WHICH YOU WANT THE CONTROLLER TO TAKE ACTION)//
  //NOTE THE VALUES WHICH APPEAR ON THE SERIAL MONITOR WHEN YOUR MADE SOUND IS DETECTED AND PRINTED//
  //THAT'S THE VALUE YOU SHOULD USE IF YOU WANT THAT AS A TRIGGER//

  //This is an example program//

 if (sound>=60){
  digitalWrite(ledPin,HIGH);
  delay(150);
  digitalWrite(ledPin,LOW);
 }
  
}
