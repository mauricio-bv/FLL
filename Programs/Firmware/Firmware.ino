float AH;
bool critical_message_send = false;
bool warning_message_send = false;
bool loaded_reported = false;

void setup() {
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
  delay(500);
  BlinkBatteryOK();
  BlinkMustCharge();
  BlinkCriticallyLow();
}

void loop() {
  AH = GetAH();
  // Serial.print("AH = ");
  // Serial.println(AH);
  ReadAccelVals();
  AddValues(GetAccelX(), GetAccelY());
  delay(300);
  if (IsMoving()) {
    SwitchAllLEDs();
  } else {
    turnLEDsOff();
    if (AH < 9) {
      // A buffer to compensate for noise (for now)
      if (AH > 6 && warning_message_send) {
        BlinkMustCharge();
      } else {
        BlinkBatteryOK();
        if (critical_message_send || warning_message_send) {
          warning_message_send = false;
          critical_message_send = false;
        }
      }
    } else if (AH >= 11) {
      BlinkCriticallyLow();
      loaded_reported = false;
      if (!critical_message_send) {
        if (!IsWifiConnected()) {
          InitWifi();
        } else {
          critical_message_send = SendNotification(AH, "Battery_Charge_Very_Low");
        }
      }
    } else { 
      if (critical_message_send && AH >= 10) {
        BlinkCriticallyLow();
      } else {
        BlinkMustCharge();
        loaded_reported = false;
        if (!warning_message_send) {
          if (!IsWifiConnected()) {
            InitWifi();
          } else {
            warning_message_send = SendNotification(AH, "ChargeBattery");
            // Serial.print("Warning Message Was Sent?");
            // Serial.println(warning_message_send);
          }
        }
      }
    }
  }
  delay(100);
}