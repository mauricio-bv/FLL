#define ANALOG_IN_PIN A0

float divider_voltage = 0.0;
float battery_voltage = 0.0;
float ref_voltage = 3.3;
float R1 = 30000.0;
float R2 = 7500.0;
int divider_adc_value = 0;

void readVoltage() {
  // Read ADC value in divider lead
  divider_adc_value = analogRead(ANALOG_IN_PIN);

  // Determine voltage at ADC input
  divider_voltage = (divider_adc_value * ref_voltage) / 1024.0;

  battery_voltage = divider_voltage / (R2 / (R1 + R2));

  // Print results to Serial Monitor to 2 decimal places
  Serial.print("Input Voltage = ");
  Serial.println(in_voltage, 2);
}