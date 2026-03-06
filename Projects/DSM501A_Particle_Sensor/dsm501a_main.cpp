//written for ESP32 DOIT DEVKIT V1

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
int pin = 8;
unsigned long duration;
unsigned long starttime;
unsigned long sampletime_ms = 1000;
unsigned long lowpulseoccupancy = 0;
float ratio = 0;
float concentration = 0;

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);



void setup() {
  Serial.begin(9600);
  pinMode(8,INPUT);
display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  delay(2000);
  display.clearDisplay();
  display.setTextColor(WHITE);
  delay(10);
  starttime = millis();//get the current time;
}

void loop() {
  duration = pulseIn(pin, LOW);
  lowpulseoccupancy = lowpulseoccupancy+duration;

  if ((millis()-starttime) > sampletime_ms)
  {
    ratio = lowpulseoccupancy/(sampletime_ms*10.0);  // Integer percentage 0=>100
    concentration = 1.1*pow(ratio,3)-3.8*pow(ratio,2)+520*ratio+0.62; // using spec sheet curve
    lowpulseoccupancy = 0;
    display.clearDisplay();
     display.setTextSize(2);
  display.setCursor(0, 10);
  display.print("C:"+String(concentration)); 



 if (concentration < 1000) {

  display.setTextSize(2);
  display.setCursor(0, 40);
  display.print("Clean"); 
  }

  if (concentration > 1000 && concentration < 10000) {

  display.setTextSize(2);
  display.setCursor(0, 40);
  display.print("Good"); 
    }

     if (concentration > 10000 && concentration < 20000) {

  display.setTextSize(2);
  display.setCursor(0, 40);
  display.print("Acceptable"); 
    }

    if (concentration > 20000 && concentration < 50000) {
  display.setTextSize(2);
  display.setCursor(0, 40);
  display.print("Heavy"); 
  }

 if (concentration > 50000 ) {

  display.setTextSize(2);
  display.setCursor(0, 40);
  display.print("Hazard"); 
    } 

  
   display.display();

    starttime = millis();
  }
}
