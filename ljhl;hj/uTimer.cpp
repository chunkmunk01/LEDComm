#include "uTimer.h"
#include "Arduino.h"




uTimer::uTimer()
{
	
  uTimer::update();

}



void uTimer::update()
{
  if (_enable == true){
    if (_done == false){
      if (_timing == false){
        _startTime = micros();
        _timing = true;
      }
      _accumulate = micros()-_startTime;
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




void uTimer::start()
{
  _enable=true;
 uTimer::update();

}

void uTimer::stop()
{
  _enable=false;
  uTimer::update();

}


boolean uTimer::EN()
{
  uTimer::update();
  return _enable; 
}

boolean uTimer::TT()
{
  uTimer::update();
  return _timing;
}

boolean uTimer::DN()
{
  uTimer::update();
  return _done;
}


unsigned long uTimer::Pre()
{
	
	uTimer::update();
	return _preset;
}





unsigned long uTimer::Pre(unsigned long _prein)
{
  _preset = _prein;
  uTimer::update();
  return _preset;
}


unsigned long uTimer::Acc()
{
	uTimer::update();
	return _accumulate;
}


unsigned long uTimer::Acc(unsigned long _accin)
{
  if (_accin!=0)
    _accumulate = _accin;
  uTimer::update();
  return _accumulate;
}



