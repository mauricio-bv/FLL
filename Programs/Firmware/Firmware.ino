float AH;
bool critical_message_send = false;
bool warning_message_send = false;
bool loaded_reported = false;

void setup() {
  // initializeLEDs();
  pinMode(LED_BUILTIN, OUTPUT);
  StartupBlink();
  InitAccel();
  InitWifi();
  if (IsWifiConnected()) {
    SignalWifiOn();
    SendNotification(AH, "Hello_There -Obi_Wan_Kenobi");
  } else {
    SignalWifiOff();
  }
  delay(1000);
  BlinkGreenLED();
  BlinkYellowLED();
  BlinkRedLED();
}

void loop() {
  AH = GetAH();
  Serial.print("AH = ");
  Serial.println(AH);
  ReadAccelVals();
  AddValues(GetAccelX(), GetAccelY());
  delay(1000);
  if (IsMoving()) {
    SwitchAllLEDs();
  } else {
    turnLEDsOff();
    if (AH < 9) {
      BlinkGreenLED();
      if (critical_message_send || warning_message_send) {
        warning_message_send = false;
        critical_message_send = false;
      }
    } else if (AH >= 11) {
      BlinkRedLED();
      loaded_reported = false;
      if (!critical_message_send) {
        if (!IsWifiConnected()) {
          InitWifi();
        } else {
          critical_message_send = SendNotification(AH, "ChargeBattery");
        }
      }
    } else {
      BlinkYellowLED();
      loaded_reported = false;
      if (!warning_message_send) {
        if (!IsWifiConnected()) {
          InitWifi();
        } else {
          warning_message_send = SendNotification(AH, "ChargeBattery");
        }
      }
    }
  }
  delay(100);
}