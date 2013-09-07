/*
 * SimpleTimer.cc
 *
 *  Created on: 6 sep 2013
 *      Author: georg
 */

#include "SimpleTimer.hh"


SimpleTimer::SimpleTimer(TimerFunctionsInterface *func)
: timerFunctions(func),
  startTime(0),
  spentTime(0)
{}

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
SimpleTimer::pauseTimer()
{
	if (startTime != 0)
	{
		time_t endTime = timerFunctions->getCurrentTime();
		spentTime += timerFunctions->calculateSpentTime(endTime, startTime);
		startTime = 0;
	}
	return spentTime;
}

int
SimpleTimer::stopTimer()
{
	int totalTime = spentTime;
	if (startTime != 0)
	{
		time_t endTime = timerFunctions->getCurrentTime();
		totalTime += timerFunctions->calculateSpentTime(endTime, startTime);
		startTime = 0;
		spentTime = 0;
	}
	return totalTime;
}
