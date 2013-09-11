/*
 * NamedTimer.hh
 *
 *  Created on: 8 sep 2013
 *      Author: georg
 */

#ifndef NAMEDTIMER_HH_
#define NAMEDTIMER_HH_

#include <ctime>
#include "SimpleTimer.hh"

class NamedTimer {
public:
	NamedTimer();
	~NamedTimer();
	bool create(char *string);

	SimpleTimer *timer;
};


#endif /* NAMEDTIMER_HH_ */
