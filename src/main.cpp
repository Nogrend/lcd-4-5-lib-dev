#include <Arduino.h>
#include <LCD_4_5_Digits.h>
#include <esp8266_gpio_mapping.h>

#define MAX_VALUE  19999

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
  Serial.println("let's start");
  lcd.init();
  lcd.set_value(6666);
}



void loop()
{
  for (uint16_t counter=0; counter < MAX_VALUE; counter++){
    lcd.set_value(counter);
    delay(100);
  }

}





