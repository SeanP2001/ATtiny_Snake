//---------------------------------------------------------------------------------------------------------------------------------------------------
// ATtiny: Snake
// Sean Price
// V0.4.1
//---------------------------------------------------------------------------------------------------------------------------------------------------


#include <EEPROM.h>

#include "Display.h"
#include "Button.h"
#include "Snake.h"
#include "Apple.h"

void checkButtons();                    // checks all of the buttons for user input

Display display;

#define directionButtons A2

Button UP(directionButtons, 67, 78);
Button DOWN(directionButtons, 150, 200);
Button LEFT(directionButtons, 230, 255);
Button RIGHT(directionButtons, 50, 67);

Snake snake(0, 0);

Apple apple;

void setup() 
{
  apple.place();
  apple.draw();
  snake.head->draw();
  delay(500);
}

void loop() 
{
  checkButtons();
  
  snake.move();

  if (apple.isEaten(snake.head->xPos, snake.head->yPos))
  {
    snake.grow();
    do
    {
      apple.place();
            
    }while(snake.isOccupying(apple.xPos, apple.yPos));

    apple.draw();
  }
  
  delay(500);
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void checkButtons()
{
  if (LEFT.isPressed())
  {
    snake.direction = Snake::LEFT;
  }
  if (RIGHT.isPressed())
  {
    snake.direction = Snake::RIGHT;
  }
  if (UP.isPressed())
  {
    snake.direction = Snake::UP;
  }
  if (DOWN.isPressed())
  {
    snake.direction = Snake::DOWN;
  }
}
