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
	SimpleTimer(TimerFunctionsInterface *func);
	bool createTimer();
	time_t startTimer();
	int stopTimer();

	TimerFunctionsInterface *timerFunctions;
	time_t startTime;
};


#endif /* SIMPLETIMER_HH_ */
