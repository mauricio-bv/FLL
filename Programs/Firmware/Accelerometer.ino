#include <Arduino_LSM6DS3.h>

float AccelVal_x;
float AccelVal_y;

void InitAccel() {
   if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1)
      ;
  }

  // Serial.print("Accelerometer sample rate = ");
  // Serial.print(IMU.accelerationSampleRate());
  // Serial.println(" Hz");
  // Serial.println();
  // Serial.println("Acceleration in G's");
  // Serial.println("X\tY\tZ");
}

float GetAccelX() {
  return AccelVal_x;
}
float GetAccelY() {
  return AccelVal_y;
}
void ReadAccelVals() {
  if (IMU.accelerationAvailable()) {
    float z;
    IMU.readAcceleration(AccelVal_x, AccelVal_y, z);

    // Serial.print(AccelVal_x);
    // Serial.print(',');
    // Serial.print(AccelVal_x);
    // Serial.print(',');
    // Serial.println(z);
  }
}