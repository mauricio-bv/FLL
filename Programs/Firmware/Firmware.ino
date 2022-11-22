

void setup() {
  Serial.begin(9600);
  Serial.println("Innitializing system...");
  initializeLEDs();
}

void loop() {
  charging();
  readVoltage();
  delay(200);
}