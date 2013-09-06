#include "SimpleTimerTest.hh"
#include <ctime>

#include "gmock/gmock.h"
using ::testing::Return;

void
SimpleTimerTest::SetUp()
{
	timerFunctions = new TimerFunctionMock;
	timer = new SimpleTimer(timerFunctions);
}

void
SimpleTimerTest::TearDown()
{
}

TEST_F(SimpleTimerTest, test_create_timer)
{
	EXPECT_EQ(true, timer->createTimer());
}

TEST_F(SimpleTimerTest, test_start_timer_returns_current_time)
{
	time_t startTime = time(0);

	EXPECT_CALL(*timerFunctions, getCurrentTime()).
			WillOnce(Return(startTime));

	EXPECT_EQ(startTime, timer->startTimer());
}

TEST_F(SimpleTimerTest, test_start_already_started_timer_returns_previous_start_time)
{
	time_t startTime = time(0);

	EXPECT_CALL(*timerFunctions, getCurrentTime()).
			WillOnce(Return(startTime));

	EXPECT_EQ(startTime, timer->startTimer());
	EXPECT_EQ(startTime, timer->startTimer());
}

TEST_F(SimpleTimerTest, test_stop_timer_returns_767)
{
	time_t startTime = time(0);
	time_t endTime = time(0);

	EXPECT_CALL(*timerFunctions, getCurrentTime()).
			WillOnce(Return(startTime)).
			WillOnce(Return(endTime));
	EXPECT_CALL(*timerFunctions, calculateSpentTime(endTime, startTime)).
			WillOnce(Return(767));


	EXPECT_EQ(startTime, timer->startTimer());
	EXPECT_EQ(767, timer->stopTimer());
}

TEST_F(SimpleTimerTest, test_stop_timer_returns_55)
{
	time_t startTime = time(0);
	time_t endTime = time(0);

	EXPECT_CALL(*timerFunctions, getCurrentTime()).
			WillOnce(Return(startTime)).
			WillOnce(Return(endTime));
	EXPECT_CALL(*timerFunctions, calculateSpentTime(endTime, startTime)).
			WillOnce(Return(55));


	EXPECT_EQ(startTime, timer->startTimer());
	EXPECT_EQ(55, timer->stopTimer());
}

TEST_F(SimpleTimerTest, test_stop_not_started_timer_returns_0)
{
	EXPECT_EQ(0, timer->stopTimer());
}

TEST_F(SimpleTimerTest, test_stop_already_stopped_timer_returns_0)
{
	time_t startTime = time(0);
	time_t endTime = time(0);

	EXPECT_CALL(*timerFunctions, getCurrentTime()).
			WillOnce(Return(startTime)).
			WillOnce(Return(endTime));
	EXPECT_CALL(*timerFunctions, calculateSpentTime(endTime, startTime)).
			WillOnce(Return(55));


	EXPECT_EQ(startTime, timer->startTimer());
	EXPECT_EQ(55, timer->stopTimer());
	EXPECT_EQ(0, timer->stopTimer());
}
