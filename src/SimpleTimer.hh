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

	time_t startTimer();
	int pauseTimer();
	int stopTimer();

	TimerFunctionsInterface *timerFunctions;
	time_t startTime;
	int spentTime;
};


#endif /* SIMPLETIMER_HH_ */
