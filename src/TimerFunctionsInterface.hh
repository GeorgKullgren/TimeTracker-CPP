#ifndef TIMERFUNCTIONSINTERFACE_HH
#define TIMERFUNCTIONSINTERFACE_HH

#include <ctime>

class TimerFunctionsInterface
{
public:
	virtual ~TimerFunctionsInterface() {};
	virtual time_t getCurrentTime() = 0;
	virtual int calculateSpentTime(time_t end, time_t beginning) = 0;

};

#endif //TIMERFUNCTIONSINTERFACE_HH
