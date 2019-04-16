;/*
  Stopwatch.h - Library for timing.
  Created by Božo Durdov, April 16, 2019.
  Released into the public domain.
*/
#ifndef Stopwatch_h
#define Stopwatch_h

#include "Arduino.h"

class Stopwatch
{
public:
      Stopwatch();
      char *getValue();
      char *getValueMinSec();
      void start();
      void stop();
      void reset();
private:
      struct time{ 
      unsigned int initially;
      unsigned int elapsed; 
      unsigned int now; 
      } stpw ;
      char buffer [50];
      int n;

      int days,hours,minutes,seconds=0;                         
};

#endif