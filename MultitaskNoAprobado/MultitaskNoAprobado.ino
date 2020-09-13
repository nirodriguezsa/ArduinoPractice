#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
 
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
 
void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.display(); 

  int i=20; // radio

  display.drawCircle(display.width()/4, display.height()/2, i, WHITE); //posicion derecha
  display.drawCircle((3*display.width())/4, display.height()/2, i, WHITE); //posicion izquierda
  display.setTextSize(2);
  display.display(); 
 
}
 
void loop() {
  // put your main code here, to run repeatedly:
  
  int i=16; //radio
  int delayA=200;
  
  display.fillCircle(display.width()/4, display.height()/2, i, WHITE);
  display.setTextColor(BLACK);
  display.setCursor(display.width()/4.5, display.height()/2.5);
  display.print("N");  
  display.display();  

  delay(delayA*3);

  display.fillCircle(display.width()/4, display.height()/2, i, BLACK);
  display.setTextColor(WHITE);
  display.setCursor(display.width()/4.5, display.height()/2.5);
  display.print("R"); 
  display.display();

  delay(delayA*3);

  /////////////////////////////////
  
  display.fillCircle((3*display.width())/4, display.height()/2, i, WHITE);
  display.setTextColor(BLACK);
  display.setCursor((2.9*display.width())/4, display.height()/3);
  display.print("R");  
  display.display();  

  delay(delayA);

  display.fillCircle((3*display.width())/4, display.height()/2, i, BLACK);
  //void fillCircle(uint16_t x0, uint16_t y0, uint16_t r, uint16_t color);
  display.setTextColor(WHITE);
  display.setCursor((2.9*display.width())/4, display.height()/3);
  display.print("N"); 
  display.display();

  delay(delayA);
  
}
