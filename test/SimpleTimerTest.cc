#include "SimpleTimerTest.hh"
#include "TimerFunctionMock.hh"
#include <ctime>

#include "gmock/gmock.h"
using ::testing::Return;


TEST_F(SimpleTimerTest, test_create_timer)
{
	TimerFunctionMock timerFunctions;
	SimpleTimer timer(&timerFunctions);
	EXPECT_EQ(true, timer.createTimer());
}

TEST_F(SimpleTimerTest, test_start_timer_returns_current_time)
{
	TimerFunctionMock timerFunctions;
	SimpleTimer timer(&timerFunctions);
	time_t startTime = time(0);

	EXPECT_CALL(timerFunctions, getCurrentTime()).
			WillOnce(Return(startTime));

	EXPECT_EQ(startTime, timer.startTimer());
}


