#define ANALOG_IN_PIN A0

// float ref_voltage = 3.4;
float ref_voltage = 3.33;
//float R1 = 30000.0;
//float R2 = 7500.0;

// float R1 = 33000.0;
// float R2 = 10000.0;

float R1 = 33000.0;
float R2 = 10000.0;

float divider_voltage;
float battery_voltage;
int divider_adc_value;

float ReadVoltage() {
  // float divider_voltage;
  // float battery_voltage;
  // int divider_adc_value;

  // Read ADC value in divider lead
  divider_adc_value = analogRead(ANALOG_IN_PIN);

  // Determine voltage at ADC input
  divider_voltage = (divider_adc_value * ref_voltage) / 1024.0;

  battery_voltage = divider_voltage / (R2 / (R1 + R2));
  // Serial.println("***********************************");
  // Serial.print("Divider Voltage = ");
  // Serial.println(divider_voltage, 2);
  // Serial.print("divider_adc_value = ");
  // Serial.println(divider_adc_value, 2);
  // Serial.print("Battery Voltage = ");
  // Serial.println(battery_voltage, 2);
  return battery_voltage;
}
//  Ah=10(12.8-Vread)
float GetAH() {
  //float AH = 10 * (12.8 - ReadVoltage());
  float AH = 10 * (12.8 - ReadVoltage());
  Serial.print(divider_adc_value);
  Serial.print(",");
  Serial.print(divider_voltage);
  Serial.print(",");
  Serial.print(battery_voltage);
  Serial.print(",");
  Serial.println(AH);

  return AH;
}