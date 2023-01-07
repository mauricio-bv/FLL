float AH;
bool critical_message_send = false;
bool warning_message_send = false;
bool loaded_reported = false;

void setup() {
  initializeLEDs();
  InitAccel();
  InitWifi();
  Serial.print("IS WIFI CONNECTED? ");
  Serial.println(IsWifiConnected());
}

void loop() {
  AH = GetAH();
  Serial.print("AH = ");
  Serial.println(AH);
  ReadAccelVals();
  AddValues(GetAccelX(), GetAccelY());
  delay(5000);
  if (IsMoving()) {
    SwitchAllLEDs();
  } else {
    turnLEDsOff();
    if (AH <= 40) {
      BlinkGreenLED();
      if (critical_message_send || warning_message_send) {
        warning_message_send = false;
        critical_message_send = false;
      }
      if (!loaded_reported) {
        Serial.print("Battery Charge Level Ok");
      }
    } else if (AH > 65) {
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