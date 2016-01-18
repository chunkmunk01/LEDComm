/*
This library is an effort to create more PLC like 
timers to the arduino, because fuck math.
*/




#ifndef Timer_h
#define Timer_h

#include "Arduino.h"



class Timer
{
  public:
    Timer();
    void start();
    void stop();
    boolean EN();
    boolean TT();
    boolean DN();
	unsigned long Pre();
	//void Pre(unsigned long);
    unsigned long Pre(unsigned long);
	unsigned long Acc();
	//void Acc();
    unsigned long Acc(unsigned long);
  private:
	void update();
	boolean _enable;
    boolean _timing;
    boolean _done;
    unsigned long _startTime;
    unsigned long _preset;
    unsigned long _accumulate;
    unsigned long _prein;
    unsigned long _accin;
    
};
    
    


// the #include statment and code go here...

#endif