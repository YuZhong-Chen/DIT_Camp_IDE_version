#ifndef _ARM_H_
#define _ARM_H_

#include <Servo.h>

// Servo
#define SERVO_1_PIN A0
#define SERVO_2_PIN A1
#define SERVO_3_PIN A2

namespace ARM {

// Servo 角度 
// Angle[1] -> 後臂
// Angle[2] -> 前臂
// Angle[3] -> 夾爪
extern int Angle[4];

// 初始化
void Init();

// Servo 移動
void Write(int num, int angle);

// 確認角度上下限
void CheckLimit();

// Servo 輸出 
// -> 如果要移動，就呼叫此函式
void Update();

// 手臂數位控制
void DigitalControl();

// 手臂類比控制
void AnalogControl();

};  

#endif