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
    SendNotification(AH, "Adriometer_micro_re-started");
    delay(500);
  } else {
    SignalWifiOff();
    delay(1000);
  }
  
  // Demo Battery charged
  for (int i = 0; i < 5; i++) {
    BlinkBatteryOK();
  }
  delay(2000);

  // Demo Battery Must be charged
  BlinkMustCharge();
  delay(2000);

  // Demo Battery Critically Low
  BlinkCriticallyLow();
   delay(2000);

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
<<<<<<< Updated upstream
      // A buffer to compensate for noise (for now)
      if (AH > 6 && warning_message_send) {
        BlinkMustCharge();
=======
      if (AH > 4.5 && warning_message_send) {
        BlinkYellowLED();
>>>>>>> Stashed changes
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