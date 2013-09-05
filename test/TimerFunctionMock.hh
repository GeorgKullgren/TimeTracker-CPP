/*
 * TimerFunctionMock.hh
 *
 *  Created on: 5 sep 2013
 *      Author: georg
 */

#ifndef TIMERFUNCTIONMOCK_HH_
#define TIMERFUNCTIONMOCK_HH_

#include "gmock/gmock.h"

class TimerFunctionMock : public TimerFunctionsInterface
{
public:
	MOCK_METHOD0(getCurrentTime, time_t());
	MOCK_METHOD2(calculateSpentTime, int(time_t end, time_t beginning));

	time_t currentTime;
};


#endif /* TIMERFUNCTIONMOCK_HH_ */
