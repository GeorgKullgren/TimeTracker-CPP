/*
 * SimpleTimer.cc
 *
 *  Created on: 6 sep 2013
 *      Author: georg
 */

#include "SimpleTimer.hh"


SimpleTimer::SimpleTimer(TimerFunctionsInterface *func)
: timerFunctions(func),
  startTime(0)
{}

bool
SimpleTimer::createTimer()
{
	return true;
}

time_t
SimpleTimer::startTimer()
{
	if (startTime == 0)
	{
		startTime = timerFunctions->getCurrentTime();
	}
	return startTime;
}

int
SimpleTimer::stopTimer()
{
	int spentTime = 0;
	if (startTime != 0)
	{
		time_t endTime = timerFunctions->getCurrentTime();
		spentTime = timerFunctions->calculateSpentTime(endTime, startTime);
		startTime = 0;
	}
	return spentTime;
}
