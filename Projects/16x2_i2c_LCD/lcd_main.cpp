
//This is the minimum and basic code required to print text over the 16x2 I2C LCD Display

#include<LiquidCrystal_I2C.h>  //header file has to be included and requires the library to be installed as well//

LiquidCrystal_I2C lcd(0x27, 16, 2);   //'LiquiCrystal_I2C' is the class we are using, 'lcd' is the object that we have created and it's name can be user defined.
                      //0x27 is the address of the lcd over the I2C signal lines, 16 is the no. of columns in the lcd we used and 2 is the no. of rows//


 void setup(){

  lcd.init(); //initializing the lcd//
  lcd.backlight(); //powering on the backlight of the lcd//

 
 }

 void loop() {

  lcd.setCursor(0,0); //setting the cursor at column 0 and row 0 of the lcd//
  lcd.print("Hello World"); //printing the text on the lcd//
 }
