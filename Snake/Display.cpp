
#include "Display.h"

Display::Display()
{
  SSD1306.ssd1306_init();             
  SSD1306.ssd1306_fillscreen(0x00); 
}

void Display::block(uint8_t x, uint8_t y)
{
  x0 = x * 8;
  
  if (x == 15) 
  {
    x1 = x0 + 7;
  }
  else
  {
    x1 = x0 + 8;
  }

  y0 = y;
  y1 = y0 + 1;

  SSD1306.ssd1306_draw_bmp(x0, y0, x1, y1, filledBlock);
}

void Display::blank(uint8_t x, uint8_t y)
{
  x0 = x * 8;
 
  if (x == 15) 
  {
    x1 = x0 + 7;
  }
  else
  {
    x1 = x0 + 8;
  }

  y0 = y;
  y1 = y0 + 1;

  SSD1306.ssd1306_draw_bmp(x0, y0, x1, y1, blankBlock);
}

void Display::apple(uint8_t x, uint8_t y)
{
  x0 = x * 8;
  x1;
  
  if (x == 15) 
  {
    x1 = x0 + 7;
  }
  else
  {
    x1 = x0 + 8;
  }

  y0 = y;
  y1 = y0 + 1;

  SSD1306.ssd1306_draw_bmp(x0, y0, x1, y1, circle);
}
