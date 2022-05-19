#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include <Arduino.h>
#include <ssd1306xled.h>
#include <font6x8.h>

#include "Sprites.h"


class Display{
public:
  uint8_t x0;
  uint8_t x1;
  uint8_t y0;
  uint8_t y1;

  Display();

  void block(uint8_t x, uint8_t y);

  void blank(uint8_t x, uint8_t y);

  void apple(uint8_t x, uint8_t y);
};


#endif // _SOUND_H_
