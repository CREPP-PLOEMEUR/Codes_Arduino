
#include "SSD1306Ascii.h"
#include "SSD1306AsciiAvrI2c.h"
 
#define I2C_ADDRESS 0x3C
 
SSD1306AsciiAvrI2c oled;
 
void setup() {

  //Init size
  oled.begin(&Adafruit128x64, I2C_ADDRESS);
  oled.setFont(Adafruit5x7);  
  oled.clear();
  oled.set2X();

  
  oled.println("CREPP");
  oled.set1X();
  oled.println("Club de");
  oled.println("Robotique et");
  oled.println("d'Electronique");
  oled.println("Programmable");
 
}
void loop() {
 
}
