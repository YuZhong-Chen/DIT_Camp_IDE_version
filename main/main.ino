#include "Arduino.h"

#include "Bluetooth.h"
#include "Buzzer.h"
#include "LCD.h"
#include "Arm.h"
#include "Car.h"

// 需要額外安裝的 Library :
//    LiquidCrystal_PCF8574.h
// 預設安裝的 Library :
//    Arduino.h
//    Servo.h
//    Wire.h
//    SoftwareSerial.h

void setup() {
  // 初始化
  BLUETOOTH::Init();
  BUZZER::Init();
  LCD::Init();
  ARM::Init();
  CAR::Init();

  // 等待藍芽連接
  BLUETOOTH::WaitForConnection();
}

// 主程式
void loop() {

  // 讀取藍芽資料
  BLUETOOTH::Read();

  // 確認資料是否正確
  if (BLUETOOTH::isDataLegal == true) {
    
    // 控制底盤
    CAR::EightDirectionControl();
    
    // 控制手臂
    ARM::DigitalControl();

    // LCD 顯示資料
    LCD::ShowData();
  }
}
