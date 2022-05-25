#ifndef _SNAKE_H_
#define _SNAKE_H_

#include <Arduino.h>

#include "SnakeSegment.h"


class Snake{
public:
    enum Direction {     
      UP,                       
      DOWN,
      LEFT,
      RIGHT,
    };

    Direction direction;
    uint8_t length;

    SnakeSegment* head = NULL;
    SnakeSegment* tail = NULL;
    SnakeSegment* end = NULL;

    Snake(uint8_t xPos, uint8_t yPos);

    void move();

    void grow();

    bool collided();

    bool isOccupying(uint8_t xPos, uint8_t yPos);

    void reset();

private:

    void moveHead();

    void moveTail();
};

#endif // _SNAKE_H_
