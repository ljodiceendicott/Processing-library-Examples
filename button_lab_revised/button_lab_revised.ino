const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin


int buttonState = 0;         // variable for reading the pushbutton status

void setup() {

  pinMode(ledPin, OUTPUT);

  // NOTE: INPUT_PULLUP -- an internal resistor
  // prevents 'floating' values on this pin
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {

  buttonState = digitalRead(buttonPin);

  // question: should buttonState HIGH
  // turn the ledPin ON?? 
  // Figure out *Why* this the case?
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }

}
