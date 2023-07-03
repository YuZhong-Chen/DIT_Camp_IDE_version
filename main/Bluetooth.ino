#include "Bluetooth.h"
#include "LCD.h"

#include <SoftwareSerial.h>

namespace BLUETOOTH {

SoftwareSerial BT(RX_Pin, TX_Pin);

int Angle;
int Strength;
int Button;
bool isDataLegal;
static int count = 0;

void Init() {
  if (isAndroidSystem) {
    BT.begin(HC_05_Baud_Rate);
  } else {
    BT.begin(HM_10_Baud_Rate);
  }

  isDataLegal = false;
}

void Read() {
  isDataLegal = false;

  if (isAndroidSystem) {
    if (BT.available()) {
      String Data = BT.readStringUntil('#');

      if (Data.length() == 7) {
        Angle = Data.substring(0, 3).toInt();
        Strength = Data.substring(3, 6).toInt();
        Button = Data.substring(6, 8).toInt();

        isDataLegal = true;
      }

      BT.flush();
    }
  } else {
    if (BT.available()) {
      int Data = BT.read();

      if (count == 5) {
        int i = 0;
        for (i = 0; Data != 0; i++)
          Data = Data / 2;

        Button = (i - 2) > 0 ? (i - 2) : 0;

        count++;
      } else if (count == 6) {
        Angle = (Data >> 3) * 15;
        Strength = map((Data & 0x07), 0, 7, 0, 100);

        if (Angle == 15 && Strength == 0) {
          Angle = 0;
          Strength = 100;
        } else if (Angle == 0 && Strength == 14) {
          Angle = 90;
          Strength = 100;
        } else if (Angle == 0 && Strength == 28) {
          Angle = 270;
          Strength = 100;
        } else if (Angle == 0 && Strength == 57) {
          Angle = 180;
          Strength = 100;
        }

        count++;
      } else if (count == 7) {
        isDataLegal = true;

        count = 0;
      } else if (Data == 255) {
        count = 1;
      } else {
        count++;
      }
    }
  }
}

void WaitForConnection() {
  LCD::print(0, 0, "Wait for");
  LCD::print(0, 1, "connecting...");
  
  while (true) {
    if (BT.available()) {
      break;
    }
    delay(100);
  }
  BT.flush();

  LCD::Clear();
}

}
