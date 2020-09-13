#define ledPin 4


void setup() {
  // put your setup code here, to run once:}
  pinMode(ledPin,OUTPUT);//El valor enviado al pin por defecto es 0: valor cercano a 0 voltios, Apagado

}

void loop() {
  digitalWrite(ledPin,HIGH);
  delay(500);//bloqueante
   digitalWrite(ledPin,LOW);
  delay(500);//bloqueante
}
