int greenLED_pin = 6;
int yellowLED_pin = 7;
int redLED_pin = 8;


void initializeLEDs(){
  pinMode(greenLED_pin, OUTPUT);
  pinMode(yellowLED_pin, OUTPUT);
  pinMode(redLED_pin, OUTPUT);
}


void breathGreenLED() {
  //Fading the LED
  for (int i = 0; i < 255; i++) {
    analogWrite(greenLED_pin, i);
    delay(5);
  }

  for (int i = 255; i > 0; i--) {
    analogWrite(greenLED_pin, i);
    delay(5);
  }
}

void blinkLED(int pin) {
  digitalWrite(pin, HIGH);
  delay(1000);
  digitalWrite(pin, LOW);
  delay(1000);
}

void turnLEDsOff() {
  digitalWrite(greenLED_pin, LOW);
  digitalWrite(yellowLED_pin, LOW);
  digitalWrite(redLED_pin, LOW);
}

void charging() {
  turnLEDsOff();
  delay(400);
  digitalWrite(redLED_pin, HIGH);
  delay(400);
  digitalWrite(yellowLED_pin, HIGH);
  delay(400);
  digitalWrite(greenLED_pin, HIGH);
}