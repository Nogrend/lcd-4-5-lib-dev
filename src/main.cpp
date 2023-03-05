#include <Arduino.h>
#include <LCD_4_5_Digits.h>
#include <esp8266_gpio_mapping.h>

#define MAX_VALUE 19999

// 0x57
// 0x68

// prototype

// void updateShiftRegister();

// 21, 22, 23 // example
// 21, 27, 12 // esp32
//  8,   ,     // uno
//  1,   ,      // esp8266

// // for ESP32 Microcontrollers
// uint8_t latchPin = 21;
// uint8_t clockPin = 13;
// uint8_t dataPin = 12;

// for ESP8266 Microcontrollers
// uint8_t latchPin = 5; // 1
// uint8_t clockPin = 4; // 2
// uint8_t dataPin = 2;  // 3

uint8_t latchPin = D8; // 1
uint8_t clockPin = D6; // 2
uint8_t dataPin = D7;  // 3

LCD_4_5_Digits lcd(latchPin, clockPin, dataPin);

void setup()
{
  // Serial.begin(9600);
  // Serial.println("let's start");
  lcd.init();
  lcd.set_integer(6666);
}

void loop()
{
  lcd.set_float(0.1, 1);
  delay(1000);
  lcd.set_float(0.01, 2);
  delay(1000);
  lcd.set_float(0.001, 3);
  delay(1000);
  lcd.set_float(0.0001, 4);
  delay(1000);

  for (float i = -1.0; i < 1.0; i += 0.1)
  {
    lcd.set_float(i, 1);
    delay(1000);
  }

  for (float i = -1.00; i < 1.00; i += 0.01)
  {
    lcd.set_float(i, 2);
    delay(100);
  }
  for (float i = -1.000; i < 1.000; i += 0.001)
  {
    lcd.set_float(i, 3);
    delay(100);
  }

  for (float i = -110.0; i < 110.0; i += 0.1)
  {
    lcd.set_float(i, 1);
    delay(100);
  }
  for (float i = -110.0; i < 110.0; i += 0.01)
  {
    lcd.set_float(i, 2);
    delay(100);
  }
}
