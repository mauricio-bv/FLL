void setup() {
  Serial.begin(9600);
  Serial.println("Innitializing system...");
}
void loop() {
  IsMoving();
  //delay(1000);
}

float accel_x_vals[10];  // = { 0.3, 0.1, -0.2, -0.15, -.8, 0.3, 0.3, 0.3, 0.1, 0.1 };
float accel_y_vals[10];  // = { 0.3, 0.1, -0.2, -0.15, .3, 0.3, 0.3, 0.3, 0.1, 0.1 };
int position = 0;

void AddValues(float x, float y) {
  accel_x_vals[position] = x;
  accel_y_vals[position] = y;
  if (position == 9) {
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
  for (int i = 0; i < 10; i++) {
    float val_x = accel_x_vals[i];
    float val_y = accel_y_vals[i];
    //accel_x_vals[10]
    // Serial.print("i=");
    // Serial.println(i);
    // Serial.print("x=");
    // Serial.println(accel_x_vals[i]);
    // Serial.print("y=");
    // Serial.println(val_y);
    if (val_x > max_x) {
      max_x = val_x;
    } else if (val_x < min_x) {
      min_x = val_x;
    }
    // if (val_y > max_y) {
    //   max_y = val_y;
    // } else if (val_y < min_y) {
    //   min_y = val_y;
    // }
  }
  float result = (max_x - min_x);
  if ((max_x - min_x) >= 0.6) {
    Serial.println(result);
    movingOnX = true;
  }
  // bool movingOnY;
  // if (max_y - min_y >= 0.6) {
  //   movingOnY = true;
  // }

  Serial.print("max=");
  Serial.println(max_x);
  Serial.print("min=");
  Serial.println(min_x);
  Serial.print("Is Moving: ");
  Serial.println(movingOnX);
  delay(10000);
  return (movingOnX);  // || movingOnY);
}