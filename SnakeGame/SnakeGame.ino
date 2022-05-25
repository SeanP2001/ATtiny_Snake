//---------------------------------------------------------------------------------------------------------------------------------------------------
// ATtiny: Snake
// Sean Price
// V0.8.3
//---------------------------------------------------------------------------------------------------------------------------------------------------


#include <EEPROM.h>

#include "Display.h"
#include "Button.h"
#include "Snake.h"
#include "Apple.h"
#include "Sound.h"

void checkButtons();                        // checks all of the buttons for user input
bool gameIsOver();                          // checks to see if the game is over

Display display;

#define directionButtons A2                 // direction buttons pin

Button UP(directionButtons, 67, 78);        // Button(int _pin, uint8_t _lowerBound, uint8_t _upperBound);
Button DOWN(directionButtons, 150, 200);
Button LEFT(directionButtons, 230, 255);
Button RIGHT(directionButtons, 50, 67);

#define buzzerPin 1
Sound sound(buzzerPin);

Snake snake(0, 0);                          // instantiate a snake which starts at position (0,0)

Apple apple;

int score = 0;
int highScore = 0;

int refreshDelay = 250;

void setup() 
{
  EEPROM.get(0, highScore);                                        // Load the high score from EEPROM
  display.blankScreen();
  display.titleScreen();                                           // and show the title screen
  sound.eating(refreshDelay);
  display.blankScreen();
}

void loop() 
{
  apple.place();
  apple.draw();
  snake.head->draw();                                               // render the snake
  delay(refreshDelay);

//---------------------------------------------------------------------------------------------------------------------------------------------------
  
  while(!gameIsOver())                                              // loop until game over
  {
    checkButtons();                                                 
  
    snake.move();
  
    if (apple.isEaten(snake.head->xPos, snake.head->yPos))          // when the apple gets eaten
    {
      sound.eating(refreshDelay);                              
      
      snake.grow();

      score++;
      
      do                                                            
      {
        apple.place();                                              // spawn an apple in a new location
                    
      }while(snake.isOccupying(apple.xPos, apple.yPos));            // ensuring that the apple is in a blank space
      
      apple.draw();        
    }
    else
    {
      delay(refreshDelay);                                          // wait before looping (don't need to delay if an apple is eaten because of the eating sound duration)
    } 
  }

//---------------------------------------------------------------------------------------------------------------------------------------------------

  delay(1000);                                                      // pause briefly when the snake crashes into itself

  if (score > highScore)                                            // if there is a new high score
  {
    highScore = score;
    EEPROM.put(0, highScore);                                       // save the new high score
    display.newHighScoreScreen(highScore);                          // and show the new high score screen
    sound.highScore();
    delay(2000);
  }

  display.gameOverScreen(score, highScore);                         // show the game over screen
  sound.gameOver();

  delay(2000);
  display.blankScreen();

  snake.reset();                                                    // reset the game
  score = 0;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void checkButtons()
{
  if (LEFT.isPressed() && snake.direction != Snake::RIGHT)          // if a direction is pressed and it will not cause the snake to turn back on itself
  {
    snake.direction = Snake::LEFT;                                  // set the snake to move in that direction
  }
  if (RIGHT.isPressed() && snake.direction != Snake::LEFT)
  {
    snake.direction = Snake::RIGHT;
  }
  if (UP.isPressed() && snake.direction != Snake::DOWN)
  {
    snake.direction = Snake::UP;
  }
  if (DOWN.isPressed() && snake.direction != Snake::UP)
  {
    snake.direction = Snake::DOWN;
  }
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
bool gameIsOver()
{
  if (snake.collided())                                           // if the snake's head collides with it's body
  {
    return true;                                                  // the game is over
  }
  else
  {
    return false;
  }
}
