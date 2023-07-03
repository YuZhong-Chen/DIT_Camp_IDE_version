#ifndef _LCD_H_
#define _LCD_H_

#include <LiquidCrystal_PCF8574.h>
#include <Wire.h>

namespace LCD {

// LCD 預設 Address : 0x27
extern LiquidCrystal_PCF8574 lcd;

// 初始化
void Init();

// 清除 LCD 螢幕
void Clear();

// 印出資料到 LCD 螢幕上
// -> 注意 col 和 row 都是從 0 開始計算
void print(int col, int row, String str);
void print(int col, int row, double d);
void print(int col, int row, int i);
void print(int col, int row, char c);

// 顯示藍芽資料
void ShowData();

}

#endif