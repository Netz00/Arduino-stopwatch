/*
  Stopwatch.h - Library for timing.
  Created by Božo Durdov, April 16, 2019.
  Released into the public domain.
*/
/*PLEASE FOLLOW THE ORDER: START --> STOP --> START --> STOP/RESET --> START...*/
/*following code is going to explain library functions: .start() .getValue() .stop() .reset()*/
#include <Stopwatch.h>
Stopwatch timer1;
char  *Time;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115000);
  timer1.start();
}
void loop() {
  Time = timer1.getValue(); //read elapsed time since we started stopwatch, 1st WAY, PUT DATA IN "Time" and then display "Time"
  Serial.printf ("TIME: %s\n", Time); //display day, hour, minute, second, 
  delay(1000);
  Serial.printf ("TIME: %s\n", timer1.getValue()); //2nd PUT timer1.Time() IN PRINTF
    delay(1000);
  Serial.printf ("TIME: %s\n", timer1.getValue()); //2nd PUT timer1.Time() IN PRINTF
    delay(1000);
  Serial.printf ("TIME: %s\n", timer1.getValue()); //2nd PUT timer1.Time() IN PRINTF
  
  
  timer1.stop();//we paused timer
  delay(5000);//we wait for 5 secs
  timer1.start();//we continued timing
   Serial.printf ("TIME after 5 secs of FREEZE: %s\n",timer1.getValue());//almost same time becouse timer was stopped for 2 secs
  timer1.reset();//we reset timer to 0
   timer1.start();//we start again from 0
  Serial.printf ("TIME after reset: %s\n",timer1.getValue());//timer starts again from 0
}
