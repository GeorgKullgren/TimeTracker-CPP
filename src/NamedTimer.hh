/*
 * NamedTimer.hh
 *
 *  Created on: 8 sep 2013
 *      Author: georg
 */

#ifndef NAMEDTIMER_HH_
#define NAMEDTIMER_HH_

#include <ctime>
#include <map>
#include "SimpleTimer.hh"

class NamedTimer {
public:
	NamedTimer();
	NamedTimer(TimerFunctionsInterface *timerFunctionsInstance);
	~NamedTimer();
	bool create(const char *timerName);
	time_t start(const char *timerName);

	std::map<const char *, SimpleTimer *> timerMap;
	TimerFunctionsInterface *timerFunctions;
};


#endif /* NAMEDTIMER_HH_ */
