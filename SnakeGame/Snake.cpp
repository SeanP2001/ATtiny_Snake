
#include "Snake.h"

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Snake::Snake(uint8_t xPos, uint8_t yPos)
{
  this->head = new SnakeSegment(xPos, yPos);
  this->tail = head;

  this->direction = DOWN;

  this->length = 1;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Snake::move()
{ 
  moveHead();
  
  moveTail();

  end->erase();
  free(end);
  
  head->draw();
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Snake::grow()
{
  moveHead();
  
  head->draw();

  length++;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Snake::moveHead()
{
  if (direction == UP)           // depending on the snake direction, move the snake head that way
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

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Snake::moveTail()
{
  end = tail;
  tail = tail->next;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
bool Snake::collided()
{
  SnakeSegment* check = tail;                                        // create a pointer to check the snake segments
 
  while (check->next != NULL)                                        // go through each segment of the snake
  { 
    if ((head->xPos == check->xPos) && (head->yPos == check->yPos))  // checking if the snake head coordinates match the coordinates of that segment
    {
      return true;                                                   // if it does then the snake has collided
    }

    check = check->next;                                             // move onto the next segment
  }

  return false;                                                      // if all of the segments have been checked, with no matches, then the snake has not collided
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
bool Snake::isOccupying(uint8_t xPos, uint8_t yPos)
{
  SnakeSegment* check = tail;                              // create a pointer to check the snake segments
 
  while (check != NULL)                                    // go through each segment of the snake
  { 
    if ((xPos == check->xPos) && (yPos == check->yPos))    // checking if the argument coordinates match the coordinates of that segment
    {
      return true;                                         // if it does then the snake is occupying that space
    }

    check = check->next;                                   // move onto the next segment
  }

  return false;                                            // if all of the segments have been checked, with no matches, then the snake is not occupying that space
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Snake::reset()
{
  SnakeSegment* current = tail;
  SnakeSegment* next = NULL;

  while (current != NULL)                                 // go through all of the snake's segments
  {
    next = current->next;
    free(current);                                        // freeing each memory address
    current = next;
  }

  head = new SnakeSegment(0, 0);                          // create a new snake
  tail = head;

  this->direction = DOWN;                                 

  this->length = 1;
}
