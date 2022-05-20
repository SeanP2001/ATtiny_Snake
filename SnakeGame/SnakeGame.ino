//---------------------------------------------------------------------------------------------------------------------------------------------------
// ATtiny: Snake
// Sean Price
// V0.5.1
//---------------------------------------------------------------------------------------------------------------------------------------------------


#include <EEPROM.h>

#include "Display.h"
#include "Button.h"
#include "Snake.h"
#include "Apple.h"

void checkButtons();                    // checks all of the buttons for user input
bool gameIsOver();                      // checks to see if the game is over

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
  
}

void loop() 
{
  apple.place();
  apple.draw();
  snake.head->draw();
  delay(500);
  
  while(!gameIsOver())
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

  delay(1000);

  display.gameOverScreen();

  delay(2000);

  display.blankScreen();

  snake.reset();
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

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
bool gameIsOver()
{
  if (snake.isOccupying(snake.head->xPos, snake.head->yPos))
  {
    return true;
  }
  else
  {
    return false;
  }
}
