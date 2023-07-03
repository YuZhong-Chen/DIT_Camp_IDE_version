#ifndef _CAR_H_
#define _CAR_H_

/* 
 * A 是右邊馬達
 * B 是左邊馬達
 * 
 * ENABLE 是強度
 * DIR    是方向
 * 
*/
#define MOTOR_A_ENABLE 10
#define MOTOR_B_ENABLE 11
#define MOTOR_A_DIR 12
#define MOTOR_B_DIR 13

namespace CAR {

// 初始化
void Init();

// 底盤移動 (基本移動)
void Forward();
void ForwardRight();
void ForwardLeft();
void Backward();
void BackwardRight();
void BackwardLeft();
void Right();
void Left();
void Stop();

// 底盤控制 (四向 / 八向控制)
void FourDirectionControl();
void EightDirectionControl();

}  

#endif