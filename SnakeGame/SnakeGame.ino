//---------------------------------------------------------------------------------------------------------------------------------------------------
// ATtiny: Snake
// Sean Price
// V0.7.0
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

int score = 0;
int highScore = 0;

void setup() 
{
  EEPROM.get(0, highScore);                                        // Load the high score from EEPROM
  display.blankScreen();
  display.titleScreen();
  delay(500);
  display.blankScreen();
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

      score++;
      
      do
      {
        apple.place();
              
      }while(snake.isOccupying(apple.xPos, apple.yPos));
  
      apple.draw();
    }
    
    delay(500);
  }

  delay(1000);

  if (score > highScore)
  {
    highScore = score;
    EEPROM.put(0, highScore);
    display.newHighScoreScreen(highScore);
    delay(2000);
  }

  display.gameOverScreen(score, highScore);

  delay(2000);

  display.blankScreen();

  snake.reset();

  score = 0;
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
