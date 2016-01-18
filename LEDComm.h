/*
 LEDComm library by Joshua Case. Offer void in Utah
 
 
 create led comm instance
 LEDComm talk;
 
 
 setup talk for led
 talk.Setup(cathode pin, anode pin);
 
 
 illuminate led for time in microseconds
 talk.LightOn(on time in microseconds);
 
 listen for another device, and return the length
 of time light was detected in microseconds. 
 talk.Listen(brightThresh,timeOut);
 
 
 
 bright threshold is how long the led
 waits to "see" another device, in microseconds. 
 This is the decay time of the led, which depends on the 
 brightness of the light falling on it. 
 
 timeOut is how long the led will check for a device
 before exiting the loop. If a device is detected
 within this time in microseconds, it will reset
 the timeout, and instead wait until this device "turns
 off", essentially waiting indefinately as long as light
 is detected at the intensity defined by "brightThresh"
 
 
 
 
 
 */



#ifndef LEDComm_h
#define LEDComm_h

#include "Arduino.h"
#include <utility/lcuTimer.h>


class LEDComm
{
public:
	//LEDComm();
	void Setup(int cathode2, int anode2);
	void LightOn(unsigned long lightOnTime);
	unsigned long Listen(unsigned long brightThresh, unsigned long  timeOut);
	int cathode2;
	int anode2;
	void LightOff();
	
	
	
	
private:	
	int _cathode;
	int _anode;
	unsigned long _bitTime;
	int _deviceAttached;
	unsigned long _highTime;
	unsigned long _startTime;
	lcuTimer _watchforLight;
	lcuTimer _recieveTime;
	lcuTimer _onTimr;	
};
#endif

