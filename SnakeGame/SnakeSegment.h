#ifndef _SNAKE_SEGMENT_H_
#define _SNAKE_SEGMENT_H_

#include <Arduino.h>

#include "Display.h"

#define cols 16  
#define rows 8

extern Display display;

class SnakeSegment{
public:
    uint8_t xPos;
    uint8_t yPos;
    SnakeSegment* next;

    SnakeSegment(uint8_t _xPos, uint8_t _yPos);

    void draw();

    void erase();

    void moveLeft();

    void moveRight();
    
    void moveUp();
    
    void moveDown();
};

#endif // _SNAKE_SEGMENT_H_
