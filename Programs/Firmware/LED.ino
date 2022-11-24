int greenLED_pin = 6;
int yellowLED_pin = 7;
int redLED_pin = 8;


void initializeLEDs() {
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

void BlinkYellowLED() {
  blinkLED(yellowLED_pin);
}
void BlinkRedLED() {
  blinkLED(redLED_pin);
}


void BlinkGreenLED() {
  blinkLED(greenLED_pin);
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

void SequenceLEDs() {
  turnLEDsOff();
  delay(200);
  digitalWrite(redLED_pin, HIGH);
  delay(300);
  digitalWrite(yellowLED_pin, HIGH);
  delay(300);
  digitalWrite(greenLED_pin, HIGH);
  delay(300);
}

bool IsOn;

void SwitchAllLEDs() {
  IsOn = 1;
  digitalWrite(redLED_pin, IsOn);
  digitalWrite(yellowLED_pin, IsOn);
  digitalWrite(greenLED_pin, IsOn);
  delay(80);
  IsOn = 0;
  digitalWrite(redLED_pin, IsOn);
  digitalWrite(yellowLED_pin, IsOn);
  digitalWrite(greenLED_pin, IsOn);
  IsOn = 0;
  delay(80);
  digitalWrite(redLED_pin, IsOn);
  digitalWrite(yellowLED_pin, IsOn);
  digitalWrite(greenLED_pin, IsOn);
  delay(80);
  IsOn = 1;
  digitalWrite(redLED_pin, IsOn);
  digitalWrite(yellowLED_pin, IsOn);
  digitalWrite(greenLED_pin, IsOn);
  delay(80);
}