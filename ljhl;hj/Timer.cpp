#include "Timer.h"
#include "Arduino.h"




Timer::Timer()
{
	
  Timer::update();

}



void Timer::update()
{
  if (_enable == true){
    if (_done == false){
      if (_timing == false){
        _startTime = millis();
        _timing = true;
      }
      _accumulate = millis()-_startTime;
      if (_accumulate >= _preset){
        _done = true;
        _timing = false;
      }
    }
  }
  else
  {
    _timing = false;
    _done = false;
    _accumulate = 0;
  }
}




void Timer::start()
{
  _enable=true;
 Timer::update();

}

void Timer::stop()
{
  _enable=false;
  Timer::update();

}


boolean Timer::EN()
{
  Timer::update();
  return _enable; 
}

boolean Timer::TT()
{
  Timer::update();
  return _timing;
}

boolean Timer::DN()
{
  Timer::update();
  return _done;
}


unsigned long Timer::Pre()
{
	
	Timer::update();
	return _preset;
}





unsigned long Timer::Pre(unsigned long _prein)
{
  _preset = _prein;
  Timer::update();
  return _preset;
}


unsigned long Timer::Acc()
{
	Timer::update();
	return _accumulate;
}


unsigned long Timer::Acc(unsigned long _accin)
{
  if (_accin!=0)
    _accumulate = _accin;
  Timer::update();
  return _accumulate;
}



