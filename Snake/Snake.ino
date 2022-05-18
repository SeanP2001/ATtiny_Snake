//---------------------------------------------------------------------------------------------------------------------------------------------------
// ATtiny: Snake
// Sean Price
// V0.1.0
//---------------------------------------------------------------------------------------------------------------------------------------------------


#include <ssd1306xled.h>
#include <font6x8.h>
#include <EEPROM.h>

#include "Sprites.h"

void setup() 
{
  SSD1306.ssd1306_init();             
  SSD1306.ssd1306_fillscreen(0x00);   // clear the screen
}

void loop() 
{
  for (int y0 = 0; y0 < screenHeight; y0++)
  {
    SSD1306.ssd1306_draw_bmp(0, y0, (0 + 8), (y0 + 1), filledBlock);
    delay(1000);
    SSD1306.ssd1306_draw_bmp(0, y0, (0 + 8), (y0 + 1), blankBlock);   
  } 

  for(int x0 = 0; x0 < screenWidth; x0=x0+8)
  {
    if (x0 == 120)
    {
      SSD1306.ssd1306_draw_bmp(x0, 0, (x0 + 7), (0 + 1), filledBlock);
      delay(1000);
      SSD1306.ssd1306_draw_bmp(x0, 0, (x0 + 7), (0 + 1), blankBlock);
    }
    else
    {
      SSD1306.ssd1306_draw_bmp(x0, 0, (x0 + 8), (0 + 1), filledBlock);
      delay(1000);
      SSD1306.ssd1306_draw_bmp(x0, 0, (x0 + 8), (0 + 1), blankBlock);
    }   
  }

  SSD1306.ssd1306_draw_bmp(0, 0, (0 + 8), (0 + 1), filledBlock);
  SSD1306.ssd1306_draw_bmp(120, 0, (120 + 7), (0 + 1), filledBlock);
  SSD1306.ssd1306_draw_bmp(0, 7, (0 + 8), (7 + 1), filledBlock);
  SSD1306.ssd1306_draw_bmp(120, 7, (120 + 7), (7 + 1), filledBlock);

  delay(3000);

  SSD1306.ssd1306_draw_bmp(0, 0, (0 + 8), (0 + 1), blankBlock);
  SSD1306.ssd1306_draw_bmp(120, 0, (120 + 7), (0 + 1), blankBlock);
  SSD1306.ssd1306_draw_bmp(0, 7, (0 + 8), (7 + 1), blankBlock);
  SSD1306.ssd1306_draw_bmp(120, 7, (120 + 7), (7 + 1), blankBlock);


  for (int y0 = 0; y0 < screenHeight; y0++)
  {
    for(int x0 = 0; x0 < screenWidth; x0=x0+8)
    {
      if (x0 == 120)
      {
        SSD1306.ssd1306_draw_bmp(x0, y0, (x0 + 7), (y0 + 1), filledBlock);
        delay(1000);
        SSD1306.ssd1306_draw_bmp(x0, y0, (x0 + 7), (y0 + 1), blankBlock);
      }
      else
      {
        SSD1306.ssd1306_draw_bmp(x0, y0, (x0 + 8), (y0 + 1), filledBlock);
        delay(1000);
        SSD1306.ssd1306_draw_bmp(x0, y0, (x0 + 8), (y0 + 1), blankBlock);
      } 
    }
  } 

  while(1)
  {
    delay(10000);
  }

}
