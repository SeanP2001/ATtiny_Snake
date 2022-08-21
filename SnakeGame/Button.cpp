
#include "Button.h"

Button::Button(int _pin, uint8_t _lowerBound, uint8_t _upperBound)
{
  this->pin = _pin;
  this->lowerBound = _lowerBound;
  this->upperBound = _upperBound;
}


bool Button::isPressed()
{
  buttonValue = analogRead(pin);                                                                // read the button pin output
  
  if ((buttonValue > lowerBound) && (buttonValue <= upperBound))                                // if it is in the button range, set the button state HIGH
    return true;
  else
    return false;                                                    
}
