import processing.serial.*;

PImage LED1onImg;       // Declarar un objeto LED1 ON (RED ON) del tipo PImage
PImage LED1offImg;      // Declarar un objeto LED1 OFF (RED OFF) del tipo PImage
PImage LED2onImg;       // Declarar un objeto LED1 ON (Blue ON) del tipo PImage
PImage LED2offImg;      // Declarar un objeto LED1 ON (Blue OFF) del tipo PImage

int imageXwidth=80;     // Variable para fijar tamaño en eje X de las imagenes a mostrar
int imageYwidth=80;     // Variable para fijar tamaño en eje Y de las imagenes a mostrar

int led1Xpos=20;   // Posicion en X de las imgenes para LED1 (RED)
int led1Ypos=20;   // Posicion en Y de las imgenes para LED1 (RED)
int led2Xpos=170;   // Posicion en X de las imgenes para LED2 (Blue)
int led2Ypos=20;   // Posicion en Y de las imgenes para LED2 (Blue)

// Declarar e incializar el estado del LED1 (RED)
String LED1State = "off"; // Estado inicial del LED1 (RED) es OFF
String LED2State = "off"; // Estado inicial del LED2 (Blue) es OFF

int radius=40;         // Radio de la imagen: imagewidth/2

String charHeader = "H"; // Cabecera pra identificar el comienzo del mensaje transmitido al arduino
String outStream = "";   // Cadena de caracteres a enviar al arduino 

int mouseDelay = 150 ;   // Retardo para dejar de oprimir el mouse

Serial myPort;           // Crear un objeto de la clase serial

void setup() {

size(280,120);   // Tamaño de la ventana de visualizacion de Processing

// Cambiar "COM5" por el puerto donde se conecta arduino
myPort = new Serial(this,"COM3", 9600); // Arduino en el puerto serial "COM5"
myPort.clear();                   // Borrar datos en el puerto serial
delay(2000);                      // Retardo inicial
myPort.bufferUntil('\n');         // Almacenar datos hasta que aparezca el caracter newline

LED1onImg  = loadImage("redLed_on.png");    // Imagen LED1 (RED) ON
LED1offImg = loadImage("redLed_off.png");   // Imagen LED1 (RED) OFF
LED2onImg  = loadImage("greenLed_on.png");    // Imagen LED2 (Blue) ON
LED2offImg = loadImage("greenLed_off.png");   // Imagen LED2 (Blue) OFF

}

void draw() 
{
   background(128);
   
  // Distancia del mouse con respecto al centro de la imagen del LED1 (RED)
  int d1 = (int)dist(mouseX, mouseY, led1Xpos+(radius), led1Ypos+(radius) ); 
  int d2 = (int)dist(mouseX, mouseY, led2Xpos+(radius), led2Ypos+(radius) ); 
  
  // Verificar si el boton izquierdo del mouse ha sido oprimido sobre la imagen del LED1 (RED)

  if ((mousePressed && (mouseButton == LEFT)))
  {
    if (d1 < radius) 
    {
      // Procesar esta opresion: pasar numero del LED, posicion en X y Y
      processLED(1, led1Xpos, led1Ypos);
    } 
    else if (d2 < radius) 
    {
      // Procesar esta opresion: pasar numero del LED, posicion en X y Y
      processLED(2, led2Xpos, led2Ypos);
    }   
  }
  else 
  { 
    // Visualizacion por defecto para el LED: pasar numero del LED, posicion en X y Y 
    chkLEDnSetImage( 1, led1Xpos, led1Ypos); 
    chkLEDnSetImage( 2, led2Xpos, led2Ypos);
  }  
 
}


// recibe numero del LED, posicion en X y Y
void processLED(int LEDnum, float xLoc, float yLoc)
{
    // Asignar numero del LED a la cadena de salida
    String ardLEDnum   = Integer.toString(LEDnum); 
    String ardLEDState = "" ; // Valor inicial en la cadena que indica el estado del LED: para enviar a arduino
    
    if (LEDnum == 1 )
    {
      if (LED1State.equals("off"))
      {
        LED1State = "on";  
        // Convertir 1 a string
        ardLEDState = Integer.toString(1);            
        // Colocar imagen del LED1 ON en la ventana
        image(LED1onImg, xLoc, yLoc, imageXwidth, imageYwidth); 
      }
      else if (LED1State.equals("on"))
      {
        LED1State = "off";
        // Convertir 0 a string
        ardLEDState = Integer.toString(0);    
        // Colocar imagen del LED1 OFF en la ventana
        image(LED1offImg, xLoc, yLoc, imageXwidth, imageYwidth); 
      }
    } else if(LEDnum == 2){
      if (LED2State.equals("off"))
      {
        LED2State = "on";  
        // Convertir 1 a string
        ardLEDState = Integer.toString(1);            
        // Colocar imagen del LED1 ON en la ventana
        image(LED2onImg, xLoc, yLoc, imageXwidth, imageYwidth); 
      }
      else if (LED2State.equals("on"))
      {
        LED2State = "off";
        // Convertir 0 a string
        ardLEDState = Integer.toString(0);    
        // Colocar imagen del LED1 OFF en la ventana
        image(LED2offImg, xLoc, yLoc, imageXwidth, imageYwidth); 
      }
    }
    
    // Construir el mensaje a enviar al arduino
    outStream = charHeader + ',' +ardLEDnum + ',' + ardLEDState+ '\n'; 
    myPort.write(outStream);       // Escribir en el puerto serial el mensaje
    //println("Data sent to Arduino="+outStream); // Para verificacion en la consola de Processing
    delay(mouseDelay);  // Espera mientras se libera la opresion
}

// Funcion para verificar estado del LED y desplegar imagen cuando el mouse no esta oprimido 
// Recibe numero del LED, posicion en X y Y 
void chkLEDnSetImage(int LEDnum, float xLoc, float yLoc)
{
  if(LEDnum == 1)
    // Visualizacion de imagen OFF por defecto
    if (LED1State.equals("off")) 
    { 
        image(LED1offImg, xLoc, yLoc, imageXwidth, imageYwidth);
    } 
    // Visualizacion de imagen ON por defecto
    else if (LED1State.equals("on")) { 
        image(LED1onImg, xLoc, yLoc, imageXwidth, imageYwidth); 
    } 
    
    if(LEDnum == 2)
    // Visualizacion de imagen OFF por defecto
    if (LED2State.equals("off")) 
    { 
        image(LED2offImg, xLoc, yLoc, imageXwidth, imageYwidth);
    } 
    // Visualizacion de imagen ON por defecto
    else if (LED2State.equals("on")) { 
        image(LED2onImg, xLoc, yLoc, imageXwidth, imageYwidth); 
    } 
}

// Siempre que un dato es recibido por el puerto serial COM, se ejecuta esta funcion 
void serialEvent(Serial p) {
  String message = p.readStringUntil('\n'); // leer el mensaje serial
  if(message != null)   // Si el mensaje no esta vacio
  { //println("Mensaje recibido desde Arduino="+message); // Para depuracion
      //Procesar el mensaje recibido desde Arduino
      String [] data = message.split(","); // Dividir el mensaje usando las comas como separador
       // Verificar si el mensaje comienza con la cabecera 'H' y si es de longitud 3
      if(data[0].charAt(0) == 'H' && data.length == 3)   
      { 
          for( int i = 1; i <= data.length; i++) 
          {   
            if (i == 1 ){print("LED '"+data[i]+"'");}
            if (i == 2 )
            { 
              if ((data[i].charAt(0) == '0'))
              { 
                println(" set to OFF");
              }
              else if ((data[i].charAt(0) == '1')) 
              { 
              println(" set to ON");
              }
            }
          }
       }
   } 
  delay(100); // delay
}
