#include <Wire.h>

#include <SPI.h>

#include <Adafruit_SSD1306.h>

#include <FreqCount.h>

#define OLED_RESET 4

Adafruit_SSD1306 display(OLED_RESET);

int analogInput = 0;

float vout = 0.0;

float vin = 0.0;

float R1 = 100000.0; // resistance of R1 (100K)

float R2 = 10000.0; // resistance of R2 (10K)

int value = 0;

void setup(){

   Serial.begin(19200);

   display.begin(SSD1306_SWITCHCAPVCC, 0x3C); 

   display.clearDisplay();

   display.display();

   FreqCount.begin(1000); 

}

void loop(){

   // read the value at analog input

   value = analogRead(analogInput);

   vout = (value * 5.0) / 1024.0; 

   vin = vout / (R2/(R1+R2)); 

   if (vin<0.09) {

   vin=0.0;

  

}

if (FreqCount.available()) {                    

    float count = FreqCount.read();                   

    float period = (1/count);

    

  display.setTextSize(1);

  display.clearDisplay(); 

  display.setTextColor(WHITE, BLACK);

  display.setCursor(35,23);                                                        

  display.println(count); 

  display.setCursor(45,11);                                                        

  display.println(period);

  display.setCursor(75,11);                                

  display.print("ms");

  display.setCursor(0,23);                                

  display.print("Freq:");

  display.setCursor(70,24);                                

  display.print("Hz");

  display.setCursor(0,11);                                

  display.print("Period:");

    

}

 Serial.println(vin);

 

  display.setTextSize(1);

  display.setTextColor(WHITE, BLACK);

  display.setCursor(40,0);

  display.println(vin);

  delay(1000);

  

  

  display.setTextSize(1);

  display.setCursor(0,0);

  display.print("V");

  

  display.setTextSize(1);

  display.setCursor(11,-1);

  display.print("...");

  display.setCursor(11,-3);

  display.print("___");

  display.display();                          

  

}
