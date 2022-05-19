//---------------------------------------------------------------------------------------------------------------------------------------------------
// ATtiny: Snake
// Sean Price
// V0.1.2
//---------------------------------------------------------------------------------------------------------------------------------------------------


#include <EEPROM.h>

#include "Display.h"

#define cols 16  
#define rows 8

Display display;

void setup() 
{
  
}

void loop() 
{
  for (int y = 0; y < rows; y++)
  {
    display.block(0, y);
    delay(1000);
    display.blank(0, y);   
  } 

  for(int x = 0; x < cols; x++)
  {
    display.block(x, 0);
    delay(1000);
    display.blank(x, 0);  
  }
  

  for (int y = 0; y < rows; y++)
  {
    for(int x = 0; x < cols; x++)
    {
      display.block(x, y);
      delay(1000);
      display.blank(x, y);  
    }
  } 

  while(1)
  {
    delay(10000);
  }

}
