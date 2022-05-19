//---------------------------------------------------------------------------------------------------------------------------------------------------
// ATtiny: Snake
// Sean Price
// V0.2.2
//---------------------------------------------------------------------------------------------------------------------------------------------------


#include <EEPROM.h>

#include "Display.h"
#include "Snake.h"

#define cols 16  
#define rows 8

Display display;

Snake snake(0, 0);

void setup() 
{
  
}

void loop() 
{
  snake.head->draw();
  delay(500);
  
  for(int i = 1; i < rows; i++)
  {
    snake.move();
    delay(500);
  }

  snake.direction = Snake::RIGHT;
  
  for(int i = 1; i < cols; i++)
  {
    snake.move();
    delay(500);
  }

  snake.direction = Snake::UP;
  
  for(int i = 1; i < rows; i++)
  {
    snake.move();
    delay(500);
  }

  snake.direction = Snake::LEFT;
  
  for(int i = 1; i < cols-1; i++)
  {
    snake.move();
    delay(500);
  }

  for(int i = 1; i < 48; i++)
  {
    snake.tail->erase();
    snake.tail = snake.tail->next;
    delay(500);
  }

  while(1)
  {
    delay(10000);
  }

}
