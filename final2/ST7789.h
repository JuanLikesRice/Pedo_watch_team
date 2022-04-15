#ifndef _ST7789H_
#define _ST7789H_

#include <ST77xx.h>

void ST7789(int8_t cs, int8_t dc, int8_t rst);
void setRotation(uint8_t m);
void init(uint16_t width, uint16_t height, uint8_t spiMode);
uint8_t _colstart2 = 0, ///< Offset from the right
      _rowstart2 = 0;     ///< Offset from the bottom
uint16_t windowWidth;
uint16_t windowHeight;
};

#endif // _ST7789H_
