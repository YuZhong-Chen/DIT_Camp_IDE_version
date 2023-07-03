#include "LCD.h"

#include "Bluetooth.h"
#include "Arm.h"

namespace LCD {

LiquidCrystal_PCF8574 lcd(0x27);

// Init the lcd
void Init() {
  lcd.begin(16, 2);
  Clear();
}

void Clear() {
  lcd.setBacklight(255);
  lcd.home();
  lcd.clear();
  lcd.setCursor(0, 0);
}

void print(int col, int row, String str) {
  lcd.setCursor(col, row);
  lcd.print(str.c_str());
}

void print(int col, int row, double d) {
  lcd.setCursor(col, row);
  lcd.print(d);
}

void print(int col, int row, int i) {
  lcd.setCursor(col, row);
  lcd.print(i);
}

void print(int col, int row, char c) {
  lcd.setCursor(col, row);
  lcd.print(c);
}

void ShowData() {
  Clear();
  print(0, 0, BLUETOOTH::Angle);
  print(5, 0, BLUETOOTH::Strength);
  print(10, 0, BLUETOOTH::Button);
  print(0, 1, ARM::Angle[1]);
  print(5, 1, ARM::Angle[2]);
  print(10, 1, ARM::Angle[3]);
}

}
