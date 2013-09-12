/*
 * NamedTimer.cc
 *
 *  Created on: 8 sep 2013
 *      Author: georg
 */

#include "NamedTimer.hh"
#include "SimpleTimer.hh"
#include "TimerFunctions.hh"


NamedTimer::NamedTimer()
{
	timerFunctions = new TimerFunctions;
}

NamedTimer::NamedTimer(TimerFunctionsInterface *timerFunctionsInstance)
: timerFunctions(timerFunctionsInstance)
{
}


NamedTimer::~NamedTimer() {
}

bool
NamedTimer::create(const char *namedTimer)
{
	SimpleTimer *timer;
	timer = timerMap[namedTimer];
	if (timer != 0)
	{
		return false;
	}

	timerMap[namedTimer] = new SimpleTimer(timerFunctions);
	return true;
}

time_t
NamedTimer::start(const char *namedTimer)
{
	std::map<const char *, SimpleTimer *>::iterator timerIterator;
	timerIterator = timerMap.find(namedTimer);
	if (timerIterator != timerMap.end())
	{
		return timerIterator->second->startTimer();
	}
	return 0;
}

int
NamedTimer::pause(const char *namedTimer)
{
	std::map<const char *, SimpleTimer *>::iterator timerIterator;
	timerIterator = timerMap.find(namedTimer);
	if (timerIterator != timerMap.end())
	{
		return timerIterator->second->pauseTimer();
	}
	return 0;
}

bool
NamedTimer::remove(const char *namedTimer)
{
	std::map<const char *, SimpleTimer *>::iterator timerIterator;
	timerIterator = timerMap.find(namedTimer);
	if (timerIterator != timerMap.end())
	{
		timerMap.erase(timerIterator);
		return true;
	}
	return false;
}

