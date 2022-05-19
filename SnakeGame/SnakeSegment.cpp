
#include "SnakeSegment.h"

SnakeSegment::SnakeSegment(uint8_t _xPos, uint8_t _yPos)
{
  this->xPos = _xPos;
  this->yPos = _yPos;
  this->next = NULL;
}

void SnakeSegment::draw()
{
  display.block(xPos, yPos);
}

void SnakeSegment::erase()
{
  display.blank(xPos, yPos);
}

void SnakeSegment::moveLeft()
{
  xPos--;
}

void SnakeSegment::moveRight()
{
  xPos++;
}
    
void SnakeSegment::moveUp()
{
  yPos--;
}
    
void SnakeSegment::moveDown()
{
  yPos++;
}
