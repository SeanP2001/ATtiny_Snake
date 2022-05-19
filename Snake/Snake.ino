//---------------------------------------------------------------------------------------------------------------------------------------------------
// ATtiny: Snake
// Sean Price
// V0.2.0
//---------------------------------------------------------------------------------------------------------------------------------------------------


#include <EEPROM.h>

#include "Display.h"
#include "SnakeSegment.h"

#define cols 16  
#define rows 8

Display display;

SnakeSegment* snakeHead = new SnakeSegment(0, 0);

void setup() 
{
  
}

void loop() 
{
  snakeHead->draw();
  delay(500);
  for(int i = 1; i < rows; i++)
  {
    snakeHead->moveDown();
    snakeHead->draw();
    delay(500);
  }
  for(int i = 1; i < cols; i++)
  {
    snakeHead->moveRight();
    snakeHead->draw();
    delay(500);
  }
  for(int i = 1; i < rows; i++)
  {
    snakeHead->moveUp();
    snakeHead->draw();
    delay(500);
  }
  for(int i = 1; i < cols-1; i++)
  {
    snakeHead->moveLeft();
    snakeHead->draw();
    delay(500);
  }


  while(1)
  {
    delay(10000);
  }

}
