/*
 * SimpleTimer.hh
 *
 *  Created on: Aug 30, 2013
 *      Author: georg
 */

#ifndef SIMPLETIMER_HH_
#define SIMPLETIMER_HH_

#include "TimerFunctionsInterface.hh"
#include <ctime>

class SimpleTimer
{
public:
	SimpleTimer(TimerFunctionsInterface *func) :  timerFunctions(func){}
	bool createTimer() {return true;}
	time_t startTimer() {return timerFunctions->getCurrentTime();}

	TimerFunctionsInterface *timerFunctions;
};


#endif /* SIMPLETIMER_HH_ */
