
#include "SnakeSegment.h"

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
SnakeSegment::SnakeSegment(uint8_t _xPos, uint8_t _yPos)
{
  this->xPos = _xPos;
  this->yPos = _yPos;
  this->next = NULL;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void SnakeSegment::draw()
{
  display.block(xPos, yPos);
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void SnakeSegment::erase()
{
  display.blank(xPos, yPos);
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void SnakeSegment::moveLeft()
{
  if (xPos-1 < 0)                                 // if the segment will move out of bounds
  {
    this->next = new SnakeSegment(cols-1, yPos);  // loop around to the other side of the screen
  }
  else                                            
  {
    this->next = new SnakeSegment(xPos-1, yPos);  // otherwise, move the segment in the specified direction (left in this case)
  }
  
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void SnakeSegment::moveRight()
{
  if (xPos+1 >= cols)
  {
    this->next = new SnakeSegment(0, yPos);
  }
  else
  {
    this->next = new SnakeSegment(xPos+1, yPos);
  }
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void SnakeSegment::moveUp()
{
  if (yPos-1 < 0)
  {
    this->next = new SnakeSegment(xPos, rows-1);
  }
  else
  {
    this->next = new SnakeSegment(xPos, yPos-1);
  }
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void SnakeSegment::moveDown()
{
  if (yPos+1 >= rows)
  {
    this->next = new SnakeSegment(xPos, 0);
  }
  else
  {
    this->next = new SnakeSegment(xPos, yPos+1);
  }
}
