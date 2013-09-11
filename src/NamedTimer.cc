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
: timer(0)
{
}

NamedTimer::~NamedTimer() {
}

bool
NamedTimer::create(char *string)
{
	TimerFunctionsInterface *timerFunctions = new TimerFunctions;
	timer = new SimpleTimer(timerFunctions);
	return true;
}
