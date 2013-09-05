/*
 * TimerFunctions.hh
 *
 *  Created on: 4 sep 2013
 *      Author: georg
 */

#ifndef TIMERFUNCTIONS_HH_
#define TIMERFUNCTIONS_HH_

#include "TimerFunctionsInterface.hh"
#include <ctime>

class TimerFunctions : public TimerFunctionsInterface
{
public:
	~TimerFunctions();
	virtual time_t getCurrentTime() {return time(0);}
	virtual int calculateSpentTime(time_t end, time_t beginning) {return difftime(end, beginning);}
};

#endif /* TIMERFUNCTIONS_HH_ */
