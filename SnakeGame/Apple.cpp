
#include "Apple.h"

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Apple::Apple()
{
  xPos = 0;
  yPos = 0;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Apple::draw()
{
  display.apple(xPos, yPos);
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Apple::place()
{
  xPos = rand() % cols;                     // set a random x coordinate
  yPos = rand() % rows;                     // set a random y coordinate
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
bool Apple::isEaten(uint8_t x, uint8_t y)
{
  if ((x == xPos) && (y == yPos))           // if the argument coordinates match the position of the apple
  {
    return true;                            // the apple has been eaten
  }
  else
  {
    return false;
  }  
}
