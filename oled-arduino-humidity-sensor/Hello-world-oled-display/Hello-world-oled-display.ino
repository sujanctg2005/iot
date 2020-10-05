/*

  HelloWorld.ino

  Universal 8bit Graphics Library (https://github.com/olikraus/u8g2/)

  Copyright (c) 2016, olikraus@gmail.com
  All rights reserved.

  Redistribution and use in source and binary forms, with or without modification,
  are permitted provided that the following conditions are met:

  * Redistributions of source code must retain the above copyright notice, this list
    of conditions and the following disclaimer.

  * Redistributions in binary form must reproduce the above copyright notice, this
    list of conditions and the following disclaimer in the documentation and/or other
    materials provided with the distribution.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
  CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
  INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
  MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
  NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
  ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

#include <dht.h>

dht DHT;

#define DHT11_PIN 7


/*
  U8glib Example Overview:
    Frame Buffer Examples: clearBuffer/sendBuffer. Fast, but may not work with all Arduino boards because of RAM consumption
    Page Buffer Examples: firstPage/nextPage. Less RAM usage, should work with all Arduino boards.
    U8x8 Text Only Example: No RAM usage, direct communication with display controller. No graphics, 8x8 Text only.

*/

// Please UNCOMMENT one of the contructor lines below
// U8g2 Contructor List (Frame Buffer)
// The complete list is available here: https://github.com/olikraus/u8g2/wiki/u8g2setupcpp
// Please update the pin numbers according to your setup. Use U8X8_PIN_NONE if the reset pin is not connected
U8G2_SSD1306_128X64_NONAME_F_4W_SW_SPI u8g2(U8G2_R0, /* clock=*/ 13, /*
data=*/ 11, /* cs=*/ 10, /* dc=*/ 9, /* reset=*/ 8);


void setup(void) {
  Serial.begin(9600);
  u8g2.begin();
  u8g2.setFont(u8g2_font_profont11_tr);
}

void loop(void) {


int chk = DHT.read11(DHT11_PIN);
  //Serial.print("Temperature = ");
  //Serial.println(DHT.temperature);
  //Serial.print("Humidity = ");
  //Serial.println(DHT.humidity);
  delay(100);

  
  //static unsigned long thisMicros = 0;
 // static unsigned long lastMicros = 0;
  //static byte i=0;

  // picture loop
  u8g2.firstPage();
  do {

//    u8g2.drawStr(0,7,"Now is the time for  ");
//    u8g2.drawStr(0,14," all good me to come");
//    u8g2.drawStr(0,21,"to the aid the party");
//    u8g2.drawStr(0,28," The quick brown fox");
//    u8g2.drawStr(0,35,"jumps over a lazy ");
//    u8g2.drawStr(0,42,"dog ");

    u8g2.setCursor( 5,20);
    u8g2.print("Humidity: ");
    //u8g2.print(thisMicros - lastMicros);
    u8g2.setCursor( 60,20);
    u8g2.print( DHT.humidity);
     u8g2.setCursor( 3,40);
    u8g2.print(" Temp:");
    u8g2.setCursor( 60,40);
    u8g2.print( DHT.temperature);  
   // u8g2.setCursor( 0, 46);
    //u8g2.print( "u8g2xxxx library"); // xxxx makes the same as other test

  } while( u8g2.nextPage() );

  //lastMicros = thisMicros;
 // thisMicros = micros();
}

