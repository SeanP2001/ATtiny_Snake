#ifndef _APPLE_H_
#define _APPLE_H_

#include <Arduino.h>

#include "Display.h"

extern Display display;

class Apple{
public:

    uint8_t xPos;
    uint8_t yPos; 
    
    Apple();

    void draw();

    void place();

    bool isEaten(uint8_t x, uint8_t y);
};

#endif // _APPLE_H_
