
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
  this->next = new SnakeSegment(xPos-1, yPos);
}

void SnakeSegment::moveRight()
{
  this->next = new SnakeSegment(xPos+1, yPos);
}
    
void SnakeSegment::moveUp()
{
  this->next = new SnakeSegment(xPos, yPos-1);
}
    
void SnakeSegment::moveDown()
{
  this->next = new SnakeSegment(xPos, yPos+1);
}
