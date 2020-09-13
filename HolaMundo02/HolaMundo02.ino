#define ledPin 4

void blink(unsigned long t_delay){
  digitalWrite(ledPin,HIGH);
  delay(t_delay);//bloqueante
  digitalWrite(ledPin,LOW);
  delay(t_delay);//bloqueante
    
  };

void setup() {
  // put your setup code here, to run once:}
  pinMode(ledPin,OUTPUT);//El valor enviado al pin por defecto es 0: valor cercano a 0 voltios, Apagado

}

void loop() {

  blink(500);
  
}
