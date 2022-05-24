
// Based on the excellent code by David Johnson-Davies - Found HERE -> http://www.technoblogy.com/show?20MO 

#include "Sound.h"

//---------------------------------------------------------------------------------------------------------------------------------------------------
Sound::Sound(uint8_t _buzzerPin)
{
  this->buzzerPin = _buzzerPin;
}

//---------------------------------------------------------------------------------------------------------------------------------------------------
void Sound::eating()
{
  note(0, 4);
  delay(20);
  note(3, 4);
  delay(20);
  note(0, 0);  
}

//---------------------------------------------------------------------------------------------------------------------------------------------------
void Sound::highScore()
{
  note(0, 4);
  delay(200);
  note(0, 0);
  delay(100);
  note(0, 4);
  delay(200);
  note(7, 4);
  delay(500);
  note(0, 0);  
}

//---------------------------------------------------------------------------------------------------------------------------------------------------
void Sound::gameOver()
{
  note(6, 4);
  delay(100);
  note(0, 4);
  delay(250);
  note(0, 0);  
}

//---------------------------------------------------------------------------------------------------------------------------------------------------
void Sound::note (int n, int octave)
{
  int prescaler = 8 + Clock - (octave + n/12);
  if (prescaler<1 || prescaler>15 || octave==0) prescaler = 0;
  DDRB = (DDRB & ~(1<<buzzerPin)) | (prescaler != 0)<<buzzerPin;
  OCR1C = pgm_read_byte(&scale[n % 12]) - 1;
  GTCCR = (buzzerPin == 4)<<COM1B0;
  TCCR1 = 1<<CTC1 | (buzzerPin == 1)<<COM1A0 | prescaler<<CS10;  
}
