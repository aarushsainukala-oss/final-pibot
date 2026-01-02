#include <Servo.h>

Servo rsServo;
Servo lsServo;

int rs = 0;
int ls = 0;

unsigned long starttime;
unsigned long runtime = 10000;

void setup() {
  Serial.begin(9600);

  rsServo.attach(9);   // RS servo
  lsServo.attach(10);  // LS servo

  starttime = millis();

  rsServo.write(180 -rs);
  lsServo.write(ls);
}

void loop() {
  if (millis() - starttime >= runtime) {

    if (Serial.available() > 0) {
      rs = Serial.parseInt();
      ls = Serial.parseInt();

      if (rs > 0 && rs < 180) {
        rsServo.write(180 -rs);
      }

      if (ls > 0 && ls < 180) {
        lsServo.write(ls);
      }
    }
  }
}
