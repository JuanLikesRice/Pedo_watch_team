/*
 * font.h
 *
 *  Created on: Apr 19, 2022
 *      Author: oreyn
 */

#ifndef FONT_H_
#define FONT_H_

void drawCharacter(char character, uint8_t xStartIndex, uint8_t yStartIndex, uint8_t brightness);

void drawString(const char* string, uint8_t xStartIndex, uint8_t yStartIndex, uint8_t brightness);

void drawPixel(uint8_t xStartIndex, uint8_t yStartIndex, uint8_t brightness);

#endif /* FONT_H_ */
