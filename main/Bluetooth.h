#ifndef _BLUETOOTH_H_
#define _BLUETOOTH_H_

/*********************************************************************/

// 如果是 ios 系統請使用 
// #define isAndroidSystem false
// 如果是 Android 系統請使用 
// #define isAndroidSystem true

#define isAndroidSystem false

/*********************************************************************/

// UART 腳位設定
#define RX_Pin 8
#define TX_Pin 9

// Baud Rate 設定
#define HM_10_Baud_Rate 9600
#define HC_05_Baud_Rate 115200

namespace BLUETOOTH {

// App 資料
extern int Angle;
extern int Strength;
extern int Button;

// 確認資料是否正確
extern bool isDataLegal;

// 初始化
void Init();

// 讀取藍芽資料
void Read();

// 等待藍芽連接
void WaitForConnection();

}

#endif