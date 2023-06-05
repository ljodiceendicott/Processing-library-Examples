const int buttonPin = 2;     // the number of the pushbutton pin
const int ledBluePin =  11;      // the number of the LED pin
const int ledGreenPin =  10;      // the number of the LED pin
const int ledRedPin =  9;      // the number of the LED pin
const int potPin = A0;

int state = 0;  // 0 set red
                // 1 set green
                // 2 set blue
                // 3 show RGB color
                
int buttonState = 0;         // variable for reading the pushbutton status
boolean lightOn = false;
int ledPin=9;
void setup() {
  pinMode(potPin, INPUT);
  pinMode(ledBluePin, OUTPUT);
  pinMode(ledGreenPin, OUTPUT);
  pinMode(ledRedPin, OUTPUT);

  // NOTE: INPUT_PULLUP -- an internal resistor
  // prevents 'floating' values on this pin
  pinMode(buttonPin, INPUT_PULLUP);
}

boolean buttonIsDown(){
  int tmp = digitalRead(buttonPin);
  if(tmp == LOW) 
    return true;
  return false;
}

/**
 * if the button is down, this function 
 * returns true after the button is released
 * otherwise it returns false immediately
 */
boolean detectButtonAndWait(){
  buttonState = buttonIsDown();
  if (buttonState) {
    // button is down
    
    while(buttonIsDown()){
      // do nothing while the button remains down
      delay(10);
    }
    // done stalling, button is back up
    return true;
  } 
  else // button wasn't down when we checked
    return false;
}

void loop() {
  // read the button
  buttonState = buttonIsDown();
  if (buttonState) {
   if(state==0){
    lightOn = not(lightOn);
    digitalWrite(11,0);
    digitalWrite(10,0);
    digitalWrite(9, 1);
   
    // while the button is still down
    while(buttonIsDown()){
      // do nothing...
      delay(10);
    }
    // done stalling, button is back up
  state=1;
  }
  else if(state==1){
     lightOn = not(lightOn);
    digitalWrite(9,0);
    digitalWrite(10,1);
   
    // while the button is still down
    while(buttonIsDown()){
      // do nothing...
      delay(10);
    }
    // done stalling, button is back up
  state=2;
  }
  else if(state==2){
     lightOn = not(lightOn);
     digitalWrite(10, 0);
    digitalWrite(11, 1);
   
    // while the button is still down
    while(buttonIsDown()){
      // do nothing...
      delay(10);
    }
    // done stalling, button is back up
  state=3;
    
  }
  else if(state==3){
     lightOn = not(lightOn);
    digitalWrite(9, 1);
    digitalWrite(10, 1);
    digitalWrite(11,1);
   
    // while the button is still down
    while(buttonIsDown()){
      // do nothing...
      delay(10);
    }
    // done stalling, button is back up
  state=0;
  }
  } 
  
}
