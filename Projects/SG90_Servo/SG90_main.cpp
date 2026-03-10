//CWIR3
//written for ESP32 DOIT DEVKIT V1


//This is the minimum code required to move the SG90 micro servo at a defined position//

#include<Servo.h> //This is the header file for the servo and make sure to install the libraries seperately//

int servoPin = 16 ; //Defining the pin that we will be using on the esp32 to control the servo, you can choose another pin but make sure that it is a PWM capable pin//

int servoPosition = 0; //Creating a variable for the servo position so that if we wish to change it again and again, we can just do it from a single place instead of changing the value at multiple places//

Servo servo1; //'Servo' is the class or the controller, 'servo1' is the object that we created and named it as 'servo1'. The name can be user defined//

void loop(){

  servo1.attach(servoPin); //We attached the servo at the variable we created, if we wish to change the pin then we may simply change the variable value only making it easy and mistake free//
  
}
void setup(){

  servo1.write(servoPosition); //This command tells the servo to move at the particular angle, we can do so by changing the value assigned to the variable //
}


 //NOTE - Not all servos move from 0-180 because some are not that good quality so they may say that they move so and so but in reality they move from 0-165 or something like that//
 // So you better check the moving range by trial and error method and make sure not to overdrive  the servo motor//
 // You can do this by decreasing the angle from 180 a little by little every time until you can't hear the servo still buzzing after it completes the moving angle//