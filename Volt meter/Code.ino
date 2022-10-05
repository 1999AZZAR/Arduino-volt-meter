#include <SPI.h>

#include <Adafruit_SSD1306.h>

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

}

void loop(){

   // read the value at analog input

   value = analogRead(analogInput);

   vout = (value * 5.0) / 1024.0;

   vin = vout / (R2/(R1+R2)); 

   if (vin<0.09) {

   vin=0.0;

} 

 Serial.println(vin);

  display.setTextSize(2);

  display.setTextColor(WHITE, BLACK);

  display.setCursor(65,10);

  display.println(vin);

  delay(1000);

  

  display.setTextSize(2);

  display.setCursor(1,10);

  display.print("V");

  

  display.setTextSize(1);

  display.setCursor(20,12);

  display.print("...");

  display.setCursor(20,10);

  display.print("___");

  display.display();

}
