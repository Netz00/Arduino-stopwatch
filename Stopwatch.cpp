/*
  Stopwatch.cpp - Library for timing.
  Created by Božo Durdov, April 16, 2019.
  Released into the public domain.
*/

#include "Arduino.h"
#include "Stopwatch.h"

Stopwatch::Stopwatch(){
 
};



char *Stopwatch::getValue(){
    
    stpw.now=(millis()+stpw.elapsed)-stpw.initially;

int days = stpw.now / 86400000 ;                                
int hours = (stpw.now % 86400000) / 3600000;                      
int minutes = ((stpw.now % 86400000) % 3600000) / 60000 ;        
int seconds = (((stpw.now % 86400000) % 3600000) % 60000) / 1000;

  n=sprintf (buffer, "%02d day  %02d : %02d : %02d", days, hours, minutes,seconds);
return buffer;
}

char *Stopwatch::getValueMinSec(){
    
    stpw.now=(millis()+stpw.elapsed)-stpw.initially;

int minutes = ((stpw.now % 86400000) % 3600000) / 60000 ;        
int seconds = (((stpw.now % 86400000) % 3600000) % 60000) / 1000;

  n=sprintf (buffer, "%02d : %02d", minutes,seconds);
return buffer;
}

void Stopwatch::start(){
    stpw.initially=millis();
}
void Stopwatch::stop(){
    stpw.elapsed=millis()-stpw.initially;
    stpw.initially=0; 
}
void Stopwatch::reset(){
    stpw.initially=0;
    stpw.elapsed=0;
    stpw.now=0;
    days=hours=minutes=seconds=0; 
}
