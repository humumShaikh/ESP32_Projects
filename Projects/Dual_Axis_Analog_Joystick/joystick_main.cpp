//CWIR3
//written for ESP32 DOIT DEVKIT V1

//This is the program to read inputs from a dual axis analog Joystick//
//Note that the joystick needs to be powered up with 3.3V if being used with the ESP32 //
//If you will be using an arduino then connect a 5V power supply//


int Xpin = 36; //Declare a pin for the VRx (X stick)// //(You can use any GPIO pins for this purpose)//
int Ypin = 39; //Declare a pin for the VRy (Y stick)//
int Spin = 34; //Declare a pin for the switch (SW)//

int Xval; //Making a variable for storing the analog value of the X stick//
int Yval; //Making a variable for storing the analog value of the Y stick//
int Sval; //Making a variable for storing the digital value of the Switch pin//

void setup(){

Serial.begin(9600); //Starting the serial monitor at the baud rate of 9600//

pinMode(Xpin,INPUT); //Declaring the XPin as an input pin//
pinMode(Ypin,INPUT); //Declaring the YPin as an input pin//
pinMode(Spin,INPUT); //Declaring the switch pin as an input pin//
digitalWrite(Spin,HIGH); // Doesn't work properly with the ESP32 but works as it should with the Arduino//


}

void loop(){

  Xval = analogRead(Xpin); //Assigning the analog value from the xpin to the variable Xval//
  Yval = analogRead(Ypin); // same from the above but from the Ypin for the Yval//
  Sval = digitalRead(Spin);// Same from the above but from the Spin for the Sval//

  Serial.print("X= ");                 //This is all the printing sequence //
  Serial.print(Xval);
  Serial.print("Y= ");
  Serial.print(Yval);
  Serial.print("Switch State= ");
  Serial.println(Sval);
}
