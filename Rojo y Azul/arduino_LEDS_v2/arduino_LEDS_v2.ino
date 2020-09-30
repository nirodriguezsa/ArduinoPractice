//Definir numero del pin para LED1
const int LED1 = 3; 
const int LED2 = 4;  

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // Inicializar puerto serial   
  // Colocar el pin del LED1 como salida
  pinMode(LED1, OUTPUT);   
  pinMode(LED2, OUTPUT); 

}

void loop() {
  // put your main code here, to run repeatedly:
   String content = "";         // Declarar e inicializar string que guardara el mensaje recibido
   char character;              // Variable para almacenar cada caracter recibido
   while(Serial.available()) {   
       character = Serial.read();   // Leer cada caracter
       content.concat(character);   // Agregarlo a la cadena content  
       delay (10); 
   } 
   // Si el mensaje recibido no esta vacio
   if (content != "")
   {                
         String myString = content; 
         // Encontrar la primera coma (las comas son lo delimitadores)
         int commaIndex = myString.indexOf(',');
         //  Buscar la siguiente coma despues de la primera
         int secondCommaIndex = myString.indexOf(',', commaIndex + 1);
         //  Buscar la ultima coma
         int lastCommaIndex = myString.lastIndexOf(',');
         
         String messageHeader = myString.substring(0, commaIndex);
         // Si la cabecera del mensaje es 'H' significa que es el comienzo del mensaje recibido
         if ( messageHeader.charAt(0) == 'H' )
         {     
            // Obtener el segundo y tercer valor del mensaje recibido 
            String secondValue = myString.substring(commaIndex+1, secondCommaIndex);
            String thirdValue = myString.substring(lastCommaIndex+1);
            
            // El segundo valor es el numero del LED y el tercero es su estado (1:ON/0:OFF)    
            int LEDnum = secondValue.toInt();
            int LEDstatus = thirdValue.toInt();

            // Actualizar estado del LED
            boolean setLEDto = false;
            if (LEDstatus == 0)
            {  
              setLEDto = LOW;
            }
            else if (LEDstatus == 1)
            { 
              setLEDto = HIGH;
            }
            
            // Ejecutar esta actualizacion
            if(LEDnum == 1)
            {
              digitalWrite(LED1, setLEDto);
            }
            else if(LEDnum == 2)
            { 
              digitalWrite(LED2, setLEDto);
            }

            // Construir y enviar mensaje a Processing a través del puerto serial 
            Serial.print(messageHeader);
            Serial.print(",");
            Serial.print(LEDnum);
            Serial.print(",");
            Serial.print(LEDstatus);
            Serial.println();  // enviar cr/lf
            delay(100);    // retardo
        }         
   }                
}
