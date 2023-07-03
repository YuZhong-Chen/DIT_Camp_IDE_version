#include "Car.h"

#include "Bluetooth.h"

namespace CAR {

void Init() {
  pinMode(MOTOR_A_ENABLE, OUTPUT);
  pinMode(MOTOR_B_ENABLE, OUTPUT);
  pinMode(MOTOR_A_DIR, OUTPUT);
  pinMode(MOTOR_B_DIR, OUTPUT);
}

void Forward() {
  digitalWrite(MOTOR_A_DIR, HIGH);
  digitalWrite(MOTOR_B_DIR, HIGH);
  digitalWrite(MOTOR_A_ENABLE, HIGH);
  digitalWrite(MOTOR_B_ENABLE, HIGH);
}

void ForwardRight() {
  digitalWrite(MOTOR_A_DIR, LOW);
  digitalWrite(MOTOR_B_DIR, HIGH);
  digitalWrite(MOTOR_A_ENABLE, LOW);
  digitalWrite(MOTOR_B_ENABLE, HIGH);
}

void ForwardLeft() {
  digitalWrite(MOTOR_A_DIR, HIGH);
  digitalWrite(MOTOR_B_DIR, LOW);
  digitalWrite(MOTOR_A_ENABLE, HIGH);
  digitalWrite(MOTOR_B_ENABLE, LOW);
}

void Backward() {
  digitalWrite(MOTOR_A_DIR, LOW);
  digitalWrite(MOTOR_B_DIR, LOW);
  digitalWrite(MOTOR_A_ENABLE, HIGH);
  digitalWrite(MOTOR_B_ENABLE, HIGH);
}

void BackwardRight() {
  digitalWrite(MOTOR_A_DIR, LOW);
  digitalWrite(MOTOR_B_DIR, LOW);
  digitalWrite(MOTOR_A_ENABLE, LOW);
  digitalWrite(MOTOR_B_ENABLE, HIGH);
}

void BackwardLeft() {
  digitalWrite(MOTOR_A_DIR, LOW);
  digitalWrite(MOTOR_B_DIR, LOW);
  digitalWrite(MOTOR_A_ENABLE, HIGH);
  digitalWrite(MOTOR_B_ENABLE, LOW);
}

void Right() {
  digitalWrite(MOTOR_A_DIR, LOW);
  digitalWrite(MOTOR_B_DIR, HIGH);
  digitalWrite(MOTOR_A_ENABLE, HIGH);
  digitalWrite(MOTOR_B_ENABLE, HIGH);
}

void Left() {
  digitalWrite(MOTOR_A_DIR, HIGH);
  digitalWrite(MOTOR_B_DIR, LOW);
  digitalWrite(MOTOR_A_ENABLE, HIGH);
  digitalWrite(MOTOR_B_ENABLE, HIGH);
}

void Stop() {
  digitalWrite(MOTOR_A_DIR, LOW);
  digitalWrite(MOTOR_B_DIR, LOW);
  digitalWrite(MOTOR_A_ENABLE, LOW);
  digitalWrite(MOTOR_B_ENABLE, LOW);
}

void FourDirectionControl() {
  if (BLUETOOTH::Strength >= 50) {
    if (BLUETOOTH::Angle >= 45 && BLUETOOTH::Angle < 135) {
      CAR::Forward();
    } else if (BLUETOOTH::Angle >= 135 && BLUETOOTH::Angle < 225) {
      CAR::Left();
    } else if (BLUETOOTH::Angle >= 225 && BLUETOOTH::Angle < 315) {
      CAR::Backward();
    } else if (BLUETOOTH::Angle >= 315 || BLUETOOTH::Angle < 45) {
      CAR::Right();
    }
  } else {
    CAR::Stop();
  }
}

void EightDirectionControl() {
  if (BLUETOOTH::Strength >= 50) {
    if (BLUETOOTH::Angle >= 22.5 && BLUETOOTH::Angle < 67.5) {
      CAR::ForwardRight();
    } else if (BLUETOOTH::Angle >= 67.5 && BLUETOOTH::Angle < 112.5) {
      CAR::Forward();
    } else if (BLUETOOTH::Angle >= 112.5 && BLUETOOTH::Angle < 157.5) {
      CAR::ForwardLeft();
    } else if (BLUETOOTH::Angle >= 157.5 && BLUETOOTH::Angle < 202.5) {
      CAR::Left();
    } else if (BLUETOOTH::Angle >= 202.5 && BLUETOOTH::Angle < 247.5) {
      CAR::BackwardLeft();
    } else if (BLUETOOTH::Angle >= 247.5 && BLUETOOTH::Angle < 292.5) {
      CAR::Backward();
    } else if (BLUETOOTH::Angle >= 292.5 && BLUETOOTH::Angle < 337.5) {
      CAR::BackwardRight();
    } else if (BLUETOOTH::Angle >= 337.5 || BLUETOOTH::Angle < 22.5) {
      CAR::Right();
    }
  } else {
    CAR::Stop();
  }
}

}