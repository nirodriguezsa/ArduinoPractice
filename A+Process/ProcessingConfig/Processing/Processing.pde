import processing.serial.*;

import controlP5.*;

PFont pfont;

ControlP5 cp5;

Serial myPort;

int myColor = color(0);


void setup() {
  size(200,200);
  
  printArray(Serial.list());
  
  myPort=new Serial(this, "COM3",9600);
  cp5 = new ControlP5(this);
  
  cp5.addButton("On")
     .setCaptionLabel("LED ON")
     .setPosition(40,20)
     .setSize(50,50)
     .setColorBackground(color(255, 0, 0))
     .setColorForeground(color(255,127,0))
     .updateSize();
     
   cp5.addButton("Off")
     .setCaptionLabel("LED OFF")
     .setPosition(110,20)
     .setSize(50,50)
     .setColorBackground(color(255, 0, 0))
     .setColorForeground(color(255,127,0))
     .updateSize();   
     
     cp5.addButton("OnB")
     .setCaptionLabel("LED ON")
     .setPosition(40,80)
     .setSize(50,50)
     .setColorBackground(color(0, 0, 255))
     .setColorForeground(color(0,150,150))
     .updateSize();
     
   cp5.addButton("OffB")
     .setCaptionLabel("LED OFF")
     .setPosition(110,80)
     .setSize(50,50)
     .setColorBackground(color(0, 0, 255))
     .setColorForeground(color(0,150,150))
     .updateSize();   
   
     PFont pfont = createFont("Arial",20,false); // use true/false for smooth/no-smooth
     ControlFont font = new ControlFont(pfont); //
     
       
     cp5.getController("On")
     .getCaptionLabel()
     .setFont(font)
     .toUpperCase(false)
     .setSize(10);
     
     cp5.getController("Off")
     .getCaptionLabel()
     .setFont(font)
     .toUpperCase(false)
     .setSize(10);
     
          
}

void draw() {
  background(myColor);
  text("LED Control Pad",10,10);
  textSize(10);
  
}

public void controlEvent(ControlEvent theEvent) {
  //println(theEvent.getController().getName());
  print(theEvent.getController().getLabel());
  println(" button has been pressed");
}

void On(){
  myPort.write("ON");
  println("LED ON");
}

void Off(){
  myPort.write("OFF");
  println("LED OFF");
}

void OnB(){
  myPort.write("ONB");
  println("LED ONB");
}

void OffB(){
  myPort.write("OFFB");
  println("LED OFFB");
}
