
#ifndef _BUTTON_H_
#define _BUTTON_H_

#include <Arduino.h>

class Button{
public:
  int pin;                                     // button pin

  uint8_t lowerBound;
  uint8_t upperBound;
  
  uint8_t buttonValue = 0;                     // button analogue output value

  Button(int _pin, uint8_t _lowerBound, uint8_t _upperBound);

  bool isPressed();
};


#endif // _BUTTON_H_
