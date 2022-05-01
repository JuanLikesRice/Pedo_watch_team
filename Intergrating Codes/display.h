/*
 * display.h
 *
 *  Created on: Apr 29, 2022
 *      Author: phuso
 */

#ifndef DISPLAY_H_
#define DISPLAY_H_
#include <msp430.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pedo.h>
//Define some common commands.
#define SWRESET 0x01 //Software Reset - 163
#define SLPIN 0x10   //Sleep in - 182
#define SLPOUT 0x11  //Sleep out - 184
#define PTLON 0x12   //Partial Display Mode On - 186
#define NORON 0x13   //Normal Display Mode On - 187
#define INVOFF 0x20   //Display Inversion Off  - 188
#define INVON 0x21     //Display Inversion On  - 188
#define DISPOFF 0x28   //Display Off  - 194
#define DISPON 0x29   //Display On  - 196
#define CASET 0x2A //Column Address Set - 198
#define RASET 0x2B //Row Address Set - 200
#define RAMWR 0x2C // Memory Write - 202
#define MADCTL 0x36 //Memory Data Access Control  - 215
#define COLMOD 0x3A //Interface Pixel Format - 224
#define WRDISBV 0x51 //Write Display Brightness - 233
#define WRCTRLD 0x53 //Write CTRL Display - 237
#define WRCACE 0x55 //Write Content Adaptive Brightness Control and Color Enhancement - 241
#define WRCABCMB 0x5E //Write CABC Minimum Brightness -245

#define CHAR_WIDTH 6
#define CHAR_HEIGHT 8

//Define some common colors
#define WHITE 0xFFFF
#define YELLOW 0xFFE0
#define MAGENTA 0xF81F
#define RED 0xF800
#define CYAN 0x07FF
#define GREEN 0x07E0
#define BLUE 0x001F
#define BLACK 0x0000

void delay_setup();
void delay(unsigned int time);
void display_spi_setup(void);
void sendBytes(uint8_t dc, uint8_t *spiBytes, int num_bytes);
void sendColor(uint8_t dc, uint16_t col, int num_pix);
void send1Byte(uint8_t dc, uint8_t spiByte);
void caset(uint8_t a, uint8_t b, uint8_t c, uint8_t d);
void raset(uint8_t a, uint8_t b, uint8_t c, uint8_t d);
void initDisplay();
void sendScreenColor(uint16_t color);
void drawPixel(uint8_t xStartIndex, uint8_t yStartIndex);
void drawCharacter(char character, uint8_t xStartIndex, uint8_t yStartIndex, uint8_t brightness) ;
void drawString(char* string, uint8_t xStartIndex, uint8_t yStartIndex, uint8_t brightness);
char* itoa(int num, char* str, int count);
void displayClock();
#endif /* DISPLAY_H_ */
