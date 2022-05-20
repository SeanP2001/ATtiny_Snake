
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
  moveHead();
  
  head->draw();
  
  moveTail();
  
  end->erase();
  
  free(end);
}

void Snake::grow()
{
  moveHead();
  
  head->draw();

  length++;
}

void Snake::moveHead()
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
  
  head = head->next;
}

void Snake::moveTail()
{
  end = tail;
  tail->erase();
  tail = tail->next;
}

bool Snake::isOccupying(uint8_t xPos, uint8_t yPos)
{
  SnakeSegment* check = tail;

  while (check->next != NULL)
  {
    if ((xPos == check->xPos) && (yPos == check->yPos))
    {
      return true;
    }

    check = check->next;
  }

  return false;
}
