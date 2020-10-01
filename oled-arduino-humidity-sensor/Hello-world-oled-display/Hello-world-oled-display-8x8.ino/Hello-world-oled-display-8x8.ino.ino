#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// If using software SPI (the default case):
#define OLED_MOSI   11
#define OLED_CLK   13
#define OLED_DC    9
#define OLED_CS    8
#define OLED_RESET 10

Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS); // sw spi
//Adafruit_SSD1306 display(OLED_DC, OLED_RESET, OLED_CS); // hw spi

void setup()   {
//  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC);
  display.display();
  delay(2000);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
}

void loop()
{
  static unsigned long thisMicros = 0;
  static unsigned long lastMicros = 0;
  display.clearDisplay();
  display.setCursor(0,40);
  display.println("Adafruit library");
//  display.setCursor(0,0);
//  display.print("Now is the time for all good men to come to the aid the party \n");
//  display.print("The quick brown fox jumps over a lazy dog \n");
  display.setCursor(0,49);
  display.print(thisMicros - lastMicros);
//  display.print(" microseconds");
  display.display();
  lastMicros = thisMicros;
  thisMicros = micros();
}

