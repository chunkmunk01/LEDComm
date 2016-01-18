
//#include "lcuTimer.h"

#include "LEDComm.h"
#include "Arduino.h"


void LEDComm::Setup(int cathode2, int anode2){
	_cathode = cathode2;
	_anode = anode2;
	pinMode(_cathode,INPUT);
	pinMode(_anode,INPUT);
	digitalWrite(_cathode,LOW);
	digitalWrite(_anode,LOW);
	
}

void LEDComm::LightOff(){
	digitalWrite(_cathode,LOW);
	digitalWrite(_anode,LOW);

}


void LEDComm::LightOn(unsigned long lightOnTime){	

	if (_onTimr.TT()==false){
		_onTimr.stop();
		_onTimr.Pre(lightOnTime);
		_onTimr.start();
	}
	
	digitalWrite(_cathode,LOW);
	digitalWrite(_anode,HIGH);
	pinMode(_cathode,OUTPUT);
	pinMode(_anode,OUTPUT);
	while (_onTimr.TT()){}
	LEDComm::LightOff();
	
	
}


unsigned long LEDComm::Listen(unsigned long brightThresh, unsigned long  timeOut){

	_bitTime=0;
	
	_recieveTime.Pre(200000);
	_recieveTime.stop();
	_watchforLight.stop();
	_watchforLight.Pre(timeOut);
	_watchforLight.start();
	_deviceAttached=0;
	while(_watchforLight.TT()){
		pinMode(_cathode,OUTPUT);
		pinMode(_anode,OUTPUT);
		digitalWrite(_cathode,HIGH);
		digitalWrite(_anode,LOW);
		delayMicroseconds(16);
		pinMode(_cathode,INPUT);
		digitalWrite(_cathode,LOW);
		_highTime = 0;
		_startTime = micros();		
		while((digitalRead(_cathode)==1) & (_highTime<brightThresh)){
			_highTime=micros()-_startTime;
		}
		
		
		
		
		if (_highTime<brightThresh){
			_watchforLight.stop();
			_watchforLight.start();
			_deviceAttached=1;
			_recieveTime.start();
		}
		else 
			
		{
			if (_deviceAttached==1){
				_watchforLight.stop();
				_bitTime=_recieveTime.Acc(); 
			}
		}		
	}
		
	return _bitTime;
	
}


