static const int ACCELEROMETER_SAMPLES = 4;
static const float IS_MOVING_TRESHOLD = 0.05;

float accel_x_vals[ACCELEROMETER_SAMPLES];
float accel_y_vals[ACCELEROMETER_SAMPLES];

int position = 0;

void AddValues(float x, float y) {
  accel_x_vals[position] = x;
  accel_y_vals[position] = y;
  Serial.print("Added x=");
  Serial.print(accel_x_vals[position]);
  Serial.print(". For Pos in Array: ");
  Serial.println(position);
  if (position == ACCELEROMETER_SAMPLES - 1) {
    for (int i = 0; i < ACCELEROMETER_SAMPLES; i++) {
      Serial.print(accel_x_vals[i]);
      Serial.print(",");
    }
    Serial.println();
    position = 0;
  } else {
    position++;
  }
}

bool IsMoving() {
  
  float min_x = 0;
  float max_x = 0;
  float min_y = 0;
  float max_y = 0;
  bool movingOnX = false;
  max_x = accel_x_vals[0];
  max_x = accel_x_vals[0];

  for (int i = 0; i < ACCELEROMETER_SAMPLES; i++) {

    float val_x = accel_x_vals[i];
    float val_y = accel_y_vals[i];

    if (val_x > max_x) {
      max_x = val_x;
    } else if (val_x < min_x) {
      min_x = val_x;
    }
  }

  Serial.print("Min=");
  Serial.print(min_x);
  Serial.print(", Max=");
  Serial.print(max_x);
  Serial.print(" => ");
  Serial.print(val_x);
  Serial.print(">");
  Serial.print(max_x);
  Serial.print(", Delta X = ");
  Serial.println(max_x - min_x);

  float result = (max_x - min_x);
  if ((max_x - min_x) >= IS_MOVING_TRESHOLD) {
    movingOnX = true;
  }
  // bool movingOnY;
  // if (max_y - min_y >= IS_MOVING_TRESHOLD) {
  //   movingOnY = true;
  // }
  Serial.print("Is Moving: ");
  Serial.println(movingOnX);
  return (movingOnX);
}