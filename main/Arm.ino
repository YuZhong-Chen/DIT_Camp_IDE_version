#include "Arm.h"

#include "Bluetooth.h"

namespace ARM {

Servo servo_[3];
int Angle[4];

void Init() {
  servo_[0].attach(SERVO_1_PIN);
  servo_[1].attach(SERVO_2_PIN);
  servo_[2].attach(SERVO_3_PIN);

  Angle[0] = 0;
  Angle[1] = 70;
  Angle[2] = 50;
  Angle[3] = 90;

  Update();
}

void Write(int num, int angle) {
  if (angle >= 0 && angle <= 180) {
    servo_[num].write(angle);
  }
}

void CheckLimit() {
  if (Angle[1] < 0)
    Angle[1] = 0;
  else if (Angle[1] > 125)
    Angle[1] = 125;
  else if (Angle[2] < 45)
    Angle[2] = 45;
  else if (Angle[2] > 135)
    Angle[2] = 135;
  else if (Angle[3] < 45)
    Angle[3] = 45;
  else if (Angle[3] > 135)
    Angle[3] = 135;
}

void Update() {
  for (int i = 0; i < 3; i++) {
    Write(i, Angle[i + 1]);
  }
}

void DigitalControl() {
  if (BLUETOOTH::Button != 0) {
    if (BLUETOOTH::Button == 1) {
      ARM::Angle[3] += 5;
    } else if (BLUETOOTH::Button == 2) {
      ARM::Angle[1] = 0;
      ARM::Angle[2] = 100;
    } else if (BLUETOOTH::Button == 3) {
      ARM::Angle[3] -= 5;
    } else if (BLUETOOTH::Button == 4) {
      ARM::Angle[1] = 70;
      ARM::Angle[2] = 50;
    }

    ARM::CheckLimit();
    ARM::Update();
    BLUETOOTH::Button = 0;
  }
}

void AnalogControl() {
  if (BLUETOOTH::Button != 0) {
    if (BLUETOOTH::Button == 1) {
      ARM::Angle[1] += 5;
    } else if (BLUETOOTH::Button == 2) {
      ARM::Angle[2] += 5;
    } else if (BLUETOOTH::Button == 3) {
      ARM::Angle[1] -= 5;
    } else if (BLUETOOTH::Button == 4) {
      ARM::Angle[2] -= 5;
    }

    ARM::CheckLimit();
    ARM::Update();
    BLUETOOTH::Button = 0;
  }
}


}