#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
#define textSize 2
#define demora 1000 // 1 seg

Adafruit_SSD1306 display(OLED_RESET);

class Moneda{
  int vertical;
  int horizontal;
  int radio;
  int state;
  unsigned long previousMillis;
  
  public:
  Moneda(int c){
    radio = c;
    state = true;
    previousMillis = 0;
    };

  void configuracion(){
    display.drawCircle(display.width()/4, display.height()/2, radio, WHITE); //posicion derecha
    display.drawCircle((3*display.width())/4, display.height()/2, radio, WHITE); //posicion izquierda
    display.setTextSize(textSize);
    display.display(); 
  };
    
  void llenar(int radio,uint16_t color,char letra, char pos){// i=17
    if(pos=='i'){
      int x1=1; int x2=4; int  y2=2; float setX1=1; float setX2=4.5; float setY2=2.5;
      display.fillCircle(x1*display.width()/x2, display.height()/y2, radio, color);
      if(color==WHITE) display.setTextColor(BLACK);
      else display.setTextColor(WHITE);
      display.setCursor((setX1*display.width())/setX2,(display.height())/setY2);
      display.print(letra);  
      display.display();  
    }
    else{
      int x1=3; int x2=4; int  y2=2; float setX1=2.9; float setX2=4; float setY2=2.5;
      display.fillCircle(x1*display.width()/x2, display.height()/y2, radio, color);
      if(color==WHITE) display.setTextColor(BLACK);
      else display.setTextColor(WHITE);
      display.setCursor((setX1*display.width())/setX2,(display.height())/setY2);
      display.print(letra);  
      display.display();  
    }
    
    };
    
  void blink(unsigned long t_delay, unsigned long t_currentMillis, int radio,uint16_t color,char letra, char pos){  //Titilar,periodo de parpadeo = 2 * delay
    if((t_currentMillis-previousMillis)>= t_delay){
      previousMillis=t_currentMillis;   //Guardamos tiempo del ultimo cambio
      if(state) llenar(radio, color, letra, pos);
      else {
        if(color==WHITE) llenar(radio, BLACK, letra, pos);
        else llenar(radio, WHITE, letra, pos);        
      }
      state=!state; //cambiamos estado del led

    };
    };
};

Moneda izquierda(24);
Moneda derecha(24);

void setup() {
  
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.display();
  
  izquierda.configuracion();
  derecha.configuracion();

}

void loop() {
   unsigned long currentMillis;
   currentMillis = millis();


  izquierda.blink(demora*3, currentMillis, 20, WHITE, 'A', 'i');
  derecha.blink(demora, currentMillis, 20, WHITE, 'B', 'd');
  
  
}
