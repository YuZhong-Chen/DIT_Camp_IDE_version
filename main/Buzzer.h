#ifndef _BUZZER_H_
#define _BUZZER_H_

#define Buzzer_Pin 4

namespace BUZZER {

// 定義音階頻率
extern const int SCALE_Do;
extern const int SCALE_Re;
extern const int SCALE_Mi;
extern const int SCALE_Fa;
extern const int SCALE_So;
extern const int SCALE_La;
extern const int SCALE_Si;

// 初始化
void Init();

// 發出音階
void Tone(int t);

// 停止發出音階
void CloseTone();

}

#endif