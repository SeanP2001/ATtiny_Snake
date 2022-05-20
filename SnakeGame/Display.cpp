
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

void Display::blankScreen()
{
  SSD1306.ssd1306_fillscreen(0x00); 
}

void Display::titleScreen()
{
  SSD1306.ssd1306_fillscreen(0x00);

  SSD1306.ssd1306_draw_bmp(0, 0, 128, 8, title);

  apple(7,0);
  
  int x = 0;
  int y = 7;

  block(x, y);
  delay(100);
  
  while (x<3)
  {
    x++;
    block(x, y);
    delay(100);
  }
  while (y>2)
  {
    y--;
    block(x, y);
    delay(100);
  }
  while (x>0)
  {
    x--;
    block(x, y);
    delay(100);
  }
  while (y>0)
  {
    y--;
    block(x, y);
    delay(100);
  }
  while (x<5)
  {
    x++;
    block(x, y);
    delay(100);
  }
}

void Display::gameOverScreen(int score, int highScore)
{
  SSD1306.ssd1306_fillscreen(0x00);
  SSD1306.ssd1306_setpos(32, 2);
  SSD1306.ssd1306_string_font6x8("Game Over");
  
  SSD1306.ssd1306_setpos(32, 4);
  printScore(score);

  SSD1306.ssd1306_setpos(2, 6);
  printHighScore(highScore);
}

void Display::newHighScoreScreen(int highScore)
{
  SSD1306.ssd1306_fillscreen(0x00);
  SSD1306.ssd1306_setpos(16, 3);
  SSD1306.ssd1306_string_font6x8("New High Score");

  SSD1306.ssd1306_setpos(2, 5);
  printHighScore(highScore);
}

void Display::printScore(int score)
{
  char scoreStr[5];
  
  SSD1306.ssd1306_string_font6x8("Score: ");
  itoa(score, scoreStr, 10);  
  SSD1306.ssd1306_string_font6x8(scoreStr);
}

void Display::printHighScore(int highScore)
{
  char highScoreStr[5];

  SSD1306.ssd1306_string_font6x8("High Score: ");
  itoa(highScore, highScoreStr, 10);
  SSD1306.ssd1306_string_font6x8(highScoreStr);  
}
