
#include "Snake.h"

Snake::Snake(uint8_t xPos, uint8_t yPos)
{
  this->head = new SnakeSegment(xPos, yPos);
  this->tail = head;

  this->direction = DOWN;

  this->length = 1;
}

void Snake::move()
{
  if (direction == UP)
  {
    head->moveUp();
  }
  if (direction == DOWN)
  {
    head->moveDown();
  }
  if (direction == LEFT)
  {
    head->moveLeft();
  }
  if (direction == RIGHT)
  {
    head->moveRight();
  } 

  head->draw();
}
