
#ifndef _SOUND_H_
#define _SOUND_H_

#include <Arduino.h>

const int Clock = ((F_CPU/1000000UL) == 16) ? 4 : ((F_CPU/1000000UL) == 8) ? 3 : 0;
const uint8_t scale[] PROGMEM = {239,226,213,201,190,179,169,160,151,142,134,127};

class Sound{
public:

  uint8_t buzzerPin;

  Sound(uint8_t _buzzerPin);

  void eating();
  void highScore();
  void gameOver();
  void note (int n, int octave);
};


#endif // _SOUND_H_
