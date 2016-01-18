#include "lcuTimer.h"
#include "Arduino.h"




lcuTimer::lcuTimer()
{
	
  lcuTimer::update();

}



void lcuTimer::update()
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




void lcuTimer::start()
{
  _enable=true;
 lcuTimer::update();

}

void lcuTimer::stop()
{
  _enable=false;
  lcuTimer::update();

}


boolean lcuTimer::EN()
{
  lcuTimer::update();
  return _enable; 
}

boolean lcuTimer::TT()
{
  lcuTimer::update();
  return _timing;
}

boolean lcuTimer::DN()
{
  lcuTimer::update();
  return _done;
}


unsigned long lcuTimer::Pre()
{
	
	lcuTimer::update();
	return _preset;
}





unsigned long lcuTimer::Pre(unsigned long _prein)
{
  _preset = _prein;
  lcuTimer::update();
  return _preset;
}


unsigned long lcuTimer::Acc()
{
	lcuTimer::update();
	return _accumulate;
}


unsigned long lcuTimer::Acc(unsigned long _accin)
{
  if (_accin!=0)
    _accumulate = _accin;
  lcuTimer::update();
  return _accumulate;
}



