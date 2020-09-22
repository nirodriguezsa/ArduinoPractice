String incomingString; // for incoming serial data
int action;

void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  // send data only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingString = Serial.readString();

    // say what you got:
    Serial.print("String received: ");
    Serial.println(incomingString);

    if (incomingString == "ON"){
        action = 1;
    }
    
    else if (incomingString == "OFF"){
        action = 2;
    }

    else if (incomingString == "ONB"){
        action = 3;
    }

    else if (incomingString == "OFFB"){
        action = 4;
    }
    else 
        action = 0;
        
switch (action) {
 
  case 1:
    //do something when var equals 1
    Serial.println("Turn ON LED");
    digitalWrite(LED_BUILTIN, HIGH);
    break;
  case 2:
    //do something when var equals 2
    Serial.println("Turn OFF LED");
    digitalWrite(LED_BUILTIN, LOW);
    break;

   case 3:
    //do something when var equals 3
    Serial.println("Turn ONB LED");
    digitalWrite(5, HIGH);
    break;
    
   case 4:
    //do something when var equals 2
    Serial.println("Turn OFFB LED");
    digitalWrite(5, LOW);
    break;
  default:
    // if nothing else matches, do the default
    // default is optional
    Serial.println("!! Not sure what you want");
    break;
}
  }
}


//-----------------------
