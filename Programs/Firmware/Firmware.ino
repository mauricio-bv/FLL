float AH;
bool critical_message_send = false;
bool warning_message_send = false;

void setup() {
  initializeLEDs();
  InitAccel();
}

void loop() {
  AH = GetAH();
  Serial.print("AH = ");
  Serial.println(AH);
  ReadAccelVals();
  AddValues(GetAccelX(), GetAccelY());

  if (IsMoving()) {
    SwitchAllLEDs();
  } else {
    //SequenceLEDs();
    turnLEDsOff();
    if (AH <= 70) {
      BlinkGreenLED();
      if (critical_message_send) {
        warning_message_send = false;
        critical_message_send = false;
      }
    } else if (AH > 90) {
      BlinkRedLED();
      if (!critical_message_send) {
        //sendCriticalMessage();
        critical_message_send = true;
      }
    } else {
      BlinkYellowLED();

      if (!warning_message_send) {
        //sendWarningMessage();
        warning_message_send = true;
      }
    }
  }
  delay(100);
}