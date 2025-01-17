// Display Library example for SPI e-paper panels from Dalian Good Display and boards from Waveshare.
// Requires HW SPI and Adafruit_GFX. Caution: these e-papers require 3.3V supply AND data lines!
//
// Display Library based on Demo Example from Good Display: http://www.e-paper-display.com/download_list/downloadcategoryid=34&isMode=false.html
//
// Author: Jean-Marc Zingg
//
// Version: see library.properties
//
// Library: https://github.com/ZinggJM/GxEPD2

#ifndef _GxEPD2_boards_added_H_
#define _GxEPD2_boards_added_H_

// Arduino DUE

// mapping suggestion for Arduino DUE
// BUSY -> 7, RST -> 9, DC -> 8, CS-> 77, CLK -> 76, DIN -> 75
// SPI pins are on 6 pin 2x3 SPI header

#if defined(ARDUINO_ARCH_SAM)
#define MAX_DISPAY_BUFFER_SIZE 15000ul // ~15k is a good compromise
#define MAX_HEIGHT(EPD) (EPD::HEIGHT <= MAX_DISPAY_BUFFER_SIZE / (EPD::WIDTH / 8) ? EPD::HEIGHT : MAX_DISPAY_BUFFER_SIZE / (EPD::WIDTH / 8))
// select one and adapt to your mapping
//GxEPD2_4G_4G<GxEPD2_213_flex, MAX_HEIGHT(GxEPD2_213_flex)> display(GxEPD2_213_flex(/*CS=77*/ SS, /*DC=*/ 8, /*RST=*/ 9, /*BUSY=*/ 7)); // GDEW0213I5F
//GxEPD2_4G_4G<GxEPD2_290_T5, MAX_HEIGHT(GxEPD2_290_T5)> display(GxEPD2_290_T5(/*CS=77*/ SS, /*DC=*/ 8, /*RST=*/ 9, /*BUSY=*/ 7)); // GDEW029T5
//GxEPD2_4G_4G<GxEPD2_270, MAX_HEIGHT(GxEPD2_270)> display(GxEPD2_270(/*CS=77*/ SS, /*DC=*/ 8, /*RST=*/ 9, /*BUSY=*/ 7));
//GxEPD2_4G_4G<GxEPD2_371, MAX_HEIGHT(GxEPD2_371)> display(GxEPD2_371(/*CS=77*/ SS, /*DC=*/ 8, /*RST=*/ 9, /*BUSY=*/ 7));
//GxEPD2_4G_4G<GxEPD2_420, MAX_HEIGHT(GxEPD2_420)> display(GxEPD2_420(/*CS=77*/ SS, /*DC=*/ 8, /*RST=*/ 9, /*BUSY=*/ 7));
//GxEPD2_4G_4G<GxEPD2_750_T7, MAX_HEIGHT(GxEPD2_750_T7)> display(GxEPD2_750_T7(/*CS=77*/ SS, /*DC=*/ 8, /*RST=*/ 9, /*BUSY=*/ 7));
#endif

// Arduino MKR1000 or MKRZERO

// mapping suggestion for Arduino MKR1000 or MKRZERO
// note: can't use SS on MKR1000: is defined as 24, should be 4
// BUSY -> 5, RST -> 6, DC -> 7, CS-> 4, CLK -> 9, DIN -> 8

#if defined(ARDUINO_ARCH_SAMD)
#define MAX_DISPAY_BUFFER_SIZE 15000ul // ~15k is a good compromise
#define MAX_HEIGHT(EPD) (EPD::HEIGHT <= MAX_DISPAY_BUFFER_SIZE / (EPD::WIDTH / 8) ? EPD::HEIGHT : MAX_DISPAY_BUFFER_SIZE / (EPD::WIDTH / 8))
// select one and adapt to your mapping
//GxEPD2_4G_4G<GxEPD2_213_flex, MAX_HEIGHT(GxEPD2_213_flex)> display(GxEPD2_213_flex(/*CS=4*/ 4, /*DC=*/ 7, /*RST=*/ 6, /*BUSY=*/ 5)); // GDEW0213I5F
//GxEPD2_4G_4G<GxEPD2_290_T5, MAX_HEIGHT(GxEPD2_290_T5)> display(GxEPD2_290_T5(/*CS=4*/ 4, /*DC=*/ 7, /*RST=*/ 6, /*BUSY=*/ 5)); // GDEW029T5
//GxEPD2_4G_4G<GxEPD2_270, MAX_HEIGHT(GxEPD2_270)> display(GxEPD2_270(/*CS=4*/ 4, /*DC=*/ 7, /*RST=*/ 6, /*BUSY=*/ 5));
//GxEPD2_4G_4G<GxEPD2_371, MAX_HEIGHT(GxEPD2_371)> display(GxEPD2_371(/*CS=4*/ 4, /*DC=*/ 7, /*RST=*/ 6, /*BUSY=*/ 5));
//GxEPD2_4G_4G<GxEPD2_420, MAX_HEIGHT(GxEPD2_420)> display(GxEPD2_420(/*CS=4*/ 4, /*DC=*/ 7, /*RST=*/ 6, /*BUSY=*/ 5));
//GxEPD2_4G_4G<GxEPD2_750_T7, MAX_HEIGHT(GxEPD2_750_T7)> display(GxEPD2_750_T7(/*CS=4*/ 4, /*DC=*/ 7, /*RST=*/ 6, /*BUSY=*/ 5));
#endif

// mapping suggestion for ESP32, e.g. LOLIN32 D32 PRO
// BUSY -> 15, RST -> 2, DC -> 0, CS -> 5, CLK -> SCK(18), DIN -> MOSI(23), GND -> GND, 3.3V -> 3.3V
// note: use explicit value for CS, as SS is re-defined to TF_CS(4) in pins_arduino.h for Board: "LOLIN D32 PRO"

#if defined(ESP32) && defined(ARDUINO_LOLIN_D32_PRO)
// select one and adapt to your mapping, can use full buffer size (full HEIGHT)
//GxEPD2_4G_4G<GxEPD2_213_flex, GxEPD2_213_flex::HEIGHT> display(GxEPD2_213_flex(/*CS=5*/ 5, /*DC=*/ 0, /*RST=*/ 2, /*BUSY=*/ 15)); // GDEW0213I5F
//GxEPD2_4G_4G<GxEPD2_290_T5, GxEPD2_290_T5::HEIGHT> display(GxEPD2_290_T5(/*CS=5*/ 5, /*DC=*/ 0, /*RST=*/ 2, /*BUSY=*/ 15)); // GDEW029T5
//GxEPD2_4G_4G<GxEPD2_270, GxEPD2_270::HEIGHT> display(GxEPD2_270(/*CS=5*/ 5, /*DC=*/ 0, /*RST=*/ 2, /*BUSY=*/ 15));
//GxEPD2_4G_4G<GxEPD2_371, GxEPD2_371::HEIGHT> display(GxEPD2_371(/*CS=5*/ 5, /*DC=*/ 0, /*RST=*/ 2, /*BUSY=*/ 15));
//GxEPD2_4G_4G<GxEPD2_420, GxEPD2_420::HEIGHT> display(GxEPD2_420(/*CS=5*/ 5, /*DC=*/ 0, /*RST=*/ 2, /*BUSY=*/ 15));
// note: need to use half height buffer, to stay < 96000 bytes of RAM, would hang on setup else
//GxEPD2_4G_4G<GxEPD2_750_T7, GxEPD2_750_T7::HEIGHT / 2> display(GxEPD2_750_T7(/*CS=5*/ 5, /*DC=*/ 0, /*RST=*/ 2, /*BUSY=*/ 15));
#endif

// mapping suggestion for ESP32, e.g. TTGO T8 ESP32-WROVER
// BUSY -> 4, RST -> 0, DC -> 2, CS -> SS(5), CLK -> SCK(18), DIN -> MOSI(23), GND -> GND, 3.3V -> 3.3V
// for use with Board: "ESP32 Dev Module":

#if defined(ESP32) && defined(ARDUINO_ESP32_DEV)
// select one and adapt to your mapping, can use full buffer size (full HEIGHT)
//GxEPD2_4G_4G<GxEPD2_213_flex, GxEPD2_213_flex::HEIGHT> display(GxEPD2_213_flex(/*CS=5*/ 5, /*DC=*/ 2, /*RST=*/ 0, /*BUSY=*/ 4)); // GDEW0213I5F
//GxEPD2_4G_4G<GxEPD2_290_T5, GxEPD2_290_T5::HEIGHT> display(GxEPD2_290_T5(/*CS=5*/ 5, /*DC=*/ 2, /*RST=*/ 0, /*BUSY=*/ 4)); // GDEW029T5
//GxEPD2_4G_4G<GxEPD2_270, GxEPD2_270::HEIGHT> display(GxEPD2_270(/*CS=5*/ 5, /*DC=*/ 2, /*RST=*/ 0, /*BUSY=*/ 4));
//GxEPD2_4G_4G<GxEPD2_371, GxEPD2_371::HEIGHT> display(GxEPD2_371(/*CS=5*/ 5, /*DC=*/ 2, /*RST=*/ 0, /*BUSY=*/ 4));
//GxEPD2_4G_4G<GxEPD2_420, GxEPD2_420::HEIGHT> display(GxEPD2_420(/*CS=5*/ 5, /*DC=*/ 2, /*RST=*/ 0, /*BUSY=*/ 4));
// note: need to use half height buffer, to stay < 96000 bytes of RAM, would hang on setup else
//GxEPD2_4G_4G<GxEPD2_750_T7, GxEPD2_750_T7::HEIGHT / 2> display(GxEPD2_750_T7(/*CS=5*/ 5, /*DC=*/ 2, /*RST=*/ 0, /*BUSY=*/ 4));
#define CLK   (18)
#define MOSI  (23)
GxEPD2_4G_4G<GxEPD2_213_T5, GxEPD2_213_T5::HEIGHT> display(GxEPD2_213_T5(5,17,16,4));
#endif

#endif
