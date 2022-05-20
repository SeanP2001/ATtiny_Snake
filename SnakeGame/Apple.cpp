
#include "Apple.h"

Apple::Apple()
{
  xPos = 0;
  yPos = 0;
}

void Apple::draw()
{
  display.apple(xPos, yPos);
}

void Apple::place()
{
  xPos = rand() % cols;
  yPos = rand() % rows;

  draw();
}

bool Apple::isEaten(uint8_t x, uint8_t y)
{
  if ((x == xPos) && (y == yPos))
  {
    return true;
  }
  else
  {
    return false;
  }  
}
