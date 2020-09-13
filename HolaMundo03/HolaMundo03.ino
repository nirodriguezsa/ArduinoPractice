class LedA{
  private:
  int ledPin;
  int ledState;
  unsigned long previousMillis;
  
  public:
  LedA(int t_ledPin){
     ledPin = t_ledPin;
     previousMillis = 0;
    };
    
  void pinConfig(){//configura como puerto de salida
    pinMode(ledPin,OUTPUT);  //El valor enviado al pin por defecto es 0: valor cercano a 0 voltios, Apagado
    ledState = HIGH;
    digitalWrite(ledPin,ledState);
    };
    
  void blink(unsigned long t_delay, unsigned long t_currentMillis){  //Titilar,periodo de parpadeo = 2 * delay
    if((t_currentMillis-previousMillis)>= t_delay){
      previousMillis=t_currentMillis;   //Guardamos tiempo del ultimo cambio
      ledState=!ledState; //cambiamos estado del led
      digitalWrite(ledPin,ledState);
    };
    };
};

LedA ledAzul(4);
LedA ledAmarillo(5);

void setup() {
  // put your setup code here, to run once:}
  ledAzul.pinConfig();
  ledAmarillo.pinConfig();

}

void loop() {
   unsigned long currentMillis;
   currentMillis = millis();

  ledAzul.blink(100, currentMillis);//funcion de titilar
  ledAmarillo.blink(500, currentMillis);//funcion de titilar
  
}
