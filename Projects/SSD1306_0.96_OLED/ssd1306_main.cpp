//CWIR3
//written for ESP32 DOIT DEVKIT V1

//This is the minimum and basic code required to print text over the 0.96 inch I2C OLED Display//

#include<Adafruit_SSD1306.h> //This is the header file and also need to install the Adafruit_SSD1306 library seperately as well//
                             //Note - better install the Adafruit Bus IO library from the lbrary manager as well//

#define OLED_RESET 4    //Necessary to define the reseting point of different modules such as oled in this case, If don't know the reset pin then just use builtin led//

Adafruit_SSD1306 Oled(OLED_RESET); // 'Adafruit_SSD1306' is the controller of the oled we are using. It is also called as the class, This is the necessary reset protocol for the OLED we are using//
                              //'oled' is the name given to the object we created, it can be user defined, It is also called as an object//
void setup() {

   Oled.begin(SSD1306_SWITCHCAPVCC, 0x3C); //This is the address where the oled will begin, 0x3C is the address on the I2C signal lines, 'SSD1306_SWITCHWCAPVCC' is necessary//
   Oled.clearDisplay(); //To clear the display before use//    
   
}

void loop() {

  Oled.setTextSize(2); //Necessary protocol to set the text size for the oled which is set to 2//
  Oled.setTextColor(WHITE); // Necessary protocol to set the text color//
  Oled.setCursor(0,0); // Set the cursor location at the co-ordinates 0,0//
  Oled.println("AISKOOL"); //This is the place where we put what we wish to print//
  Oled.display(); //Necessary to use this command or else the oled won't display the text//
  
}
