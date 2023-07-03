#include "Buzzer.h"

namespace BUZZER {

const int SCALE_Do = 523;
const int SCALE_Re = 587;
const int SCALE_Mi = 659;
const int SCALE_Fa = 698;
const int SCALE_So = 784;
const int SCALE_La = 880;
const int SCALE_Si = 988;

void Init() {
  pinMode(Buzzer_Pin, OUTPUT);
}

void Tone(int t) {
  tone(Buzzer_Pin, t);
}

void CloseTone() {
  noTone(Buzzer_Pin);
}

}
