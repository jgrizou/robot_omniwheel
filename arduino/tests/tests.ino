// pins for the LED:
const int led = 13;

float yaw = 0.0;
float pitch = 0.0;
float roll = 0.0; 

String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete

String inputAHRS = "";         // a string to hold incoming data
boolean AHRSComplete = false;  // whether the string is complete

void setup() {
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);    
  digitalWrite(led, HIGH);
  delay(1000); // wait 5 sec for wifly to connect
  digitalWrite(led, LOW);
  // initialize serial:
  Serial.begin(57600);
  Serial.println("Hello world!");  
  
  Serial3.begin(57600);
  // Set Razor output parameters
  Serial3.write("#o0"); //- (default) DISABLE continuous streaming output. Also see #f below.
  //"#o1" - ENABLE continuous streaming output.
  //Serial3.write("#ob"); // - Output angles in BINARY format (yaw/pitch/roll as binary float, so one output frame is 3x4 = 12 bytes long).
  Serial3.write("#ot");  // (default) - Output angles in TEXT format (Output frames have form like "#YPR=-142.28,-5.38,33.52", followed by carriage return and line feed [\r\n]).
  Serial3.write("#oe0");   // Disable error message output
  Serial3.flush();
  
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
  inputAHRS.reserve(200);
}

void loop() {
  
  // print the string when a newline arrives:
  if (stringComplete) {
  Serial.println(inputString); 
  //Serial3.write("#f");
  // clear the string:
  inputString = "";
  
  stringComplete = false;
  }
    
  if(AHRSComplete){
    Serial.println(inputAHRS);
    
    inputAHRS = "";
    AHRSComplete = false;
    digitalWrite(led, LOW);
  }
  
  Serial.println(yaw);  
  Serial.println(pitch);  
  Serial.println(roll);  

  Serial3.write("#f");
  delay(100);

}


/*
  SerialEvent occurs whenever a new data comes in the
 hardware serial RX.  This routine is run between each
 time loop() runs, so using delay inside loop can delay
 response.  Multiple bytes of data may be available.
 */
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read(); 

    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
      digitalWrite(led, HIGH);
    }
    else{
    // add it to the inputString:
    inputString += inChar;
    }
  }

    
}

void serialEvent3() {
  while (Serial3.available()) {
    // get the new byte:
    char inChar = (char)Serial3.read(); 
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      AHRSComplete = true;
      
      
      int s;
      int e;
      
      char charBuf[50];  
      String strBuf = "";
      //yaw
      s = inputAHRS.indexOf("=") + 1;
      e = inputAHRS.indexOf(",");
      strBuf = inputAHRS.substring(s,e);
      strBuf.toCharArray(charBuf, 50);
      yaw = atof(charBuf);
      //pitch
      
      s = e + 1;;
      e = inputAHRS.indexOf(",", s);
      strBuf = inputAHRS.substring(s,e);
      strBuf.toCharArray(charBuf, 50);
      pitch = atof(charBuf);
      //roll
      s = e + 1;;
      e = inputAHRS.length();
      strBuf = inputAHRS.substring(s,e);
      strBuf.toCharArray(charBuf, 50);
      roll = atof(charBuf);
    
    }
    else{
    // add it to the inputString:
    inputAHRS += inChar;
    }
  }    
}
