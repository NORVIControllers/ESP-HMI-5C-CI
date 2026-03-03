#include <Wire.h>
#include <TAMC_GT911.h>

// GT911 I2C Pins and configuration
#define GT911_SDA 19
#define GT911_SCL 20
#define GT911_INT -1   // optional interrupt pin
#define GT911_RST 38   // optional reset pin

TAMC_GT911 ts(GT911_SDA, GT911_SCL, GT911_INT, GT911_RST, 800, 480); // max raw X/Y

bool lastTouch = false;

void setup() {
  Serial.begin(115200);
  Wire.begin(GT911_SDA, GT911_SCL);

  ts.begin();
  ts.setRotation(0); // adjust rotation if needed
  delay(100);
  Serial.println("GT911 Capacitive Touch Test (Proper Event Handling)");
}

void loop() {
  ts.read(); // update touch points

  if (ts.isTouched && !lastTouch) { // only print when a new touch starts
    lastTouch = true;

    for (int i = 0; i < ts.touches; i++) {
      int x = ts.points[i].x;
      int y = ts.points[i].y;

      // Only print valid coordinates
      if (x < 800 && y < 480) {
        Serial.print("x = ");
        Serial.print(x);
        Serial.print(", y = ");
        Serial.println(y);

        Serial.println("------------------------------------------------------------------------");
      }
    }
  } else if (!ts.isTouched) {
    lastTouch = false; // reset when touch released
  }

  delay(50); // small delay for loop stability
}
