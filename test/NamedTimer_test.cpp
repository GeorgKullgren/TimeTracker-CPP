/*
 * NamedTimer_test.cpp
 *
 *  Created on: 8 sep 2013
 *      Author: georg
 */

#include "NamedTimer.hh"
#include "NamedTimer_test.hh"

#include "gmock/gmock.h"
using ::testing::Return;

void
NamedTimer_test::SetUp()
{
	timerFunctions = new TimerFunctionMock;
	myTimerContainer = new NamedTimer(timerFunctions);
}

void
NamedTimer_test::TearDown()
{
	delete myTimerContainer;
	delete timerFunctions;
}

TEST_F(NamedTimer_test, test_create_named_timer_returns_current_time)
{
	EXPECT_EQ(true, myTimerContainer->create("MyTimer"));
}

TEST_F(NamedTimer_test, test_create_two_named_timers)
{
	EXPECT_EQ(true, myTimerContainer->create("MyTimer1"));
	EXPECT_EQ(true, myTimerContainer->create("MyTimer2"));
}

TEST_F(NamedTimer_test, test_create_and_start_timer)
{
	time_t startTime = time(0);

	EXPECT_CALL(*timerFunctions, getCurrentTime()).
			WillOnce(Return(startTime));

	EXPECT_EQ(true, myTimerContainer->create("MyTimer1"));
	EXPECT_EQ(startTime, myTimerContainer->start("MyTimer1"));
}

TEST_F(NamedTimer_test, test_create_same_timer_twice_returns_false)
{
	EXPECT_EQ(true, myTimerContainer->create("MyTimer1"));
	EXPECT_EQ(false, myTimerContainer->create("MyTimer1"));
}

TEST_F(NamedTimer_test, test_create_timer_and_start_twice_return_same_time)
{
	EXPECT_EQ(true, myTimerContainer->create("MyTimer1"));

	time_t startTime = myTimerContainer->start("MyTimer1");
	EXPECT_EQ(startTime, myTimerContainer->start("MyTimer1"));
}


TEST_F(NamedTimer_test, test_create_and_start_two_timers_returns_different_times)
{
	time_t startTime1 = time(0);
	time_t startTime2 = time(0) + 100;

	EXPECT_CALL(*timerFunctions, getCurrentTime()).
			WillOnce(Return(startTime1)).
			WillOnce(Return(startTime2));

	EXPECT_NE(startTime1, startTime2);

	EXPECT_EQ(true, myTimerContainer->create("MyTimer1"));
	EXPECT_EQ(startTime1, myTimerContainer->start("MyTimer1"));

	EXPECT_EQ(true, myTimerContainer->create("MyTimer2"));
	EXPECT_EQ(startTime2, myTimerContainer->start("MyTimer2"));
}

TEST_F(NamedTimer_test, test_start_pause_timer_returns_laptime)
{
	time_t startTime = time(0);
	time_t pauseTime = startTime + 100;

	EXPECT_CALL(*timerFunctions, getCurrentTime()).
			WillOnce(Return(startTime)).
			WillOnce(Return(pauseTime));
	EXPECT_CALL(*timerFunctions, calculateSpentTime(pauseTime, startTime)).
			WillOnce(Return(100));

	EXPECT_EQ(true, myTimerContainer->create("MyTimer"));
	EXPECT_EQ(startTime, myTimerContainer->start("MyTimer"));
	EXPECT_EQ(100, myTimerContainer->pause("MyTimer"));

}

TEST_F(NamedTimer_test, test_delete_existing_timer_returns_true)
{
	EXPECT_EQ(true, myTimerContainer->create("MyTimer"));
	EXPECT_EQ(true, myTimerContainer->remove("MyTimer"));
}

TEST_F(NamedTimer_test, test_delete_already_deleted_timer_returns_false)
{
	EXPECT_EQ(true, myTimerContainer->create("MyTimer"));
	EXPECT_EQ(true, myTimerContainer->remove("MyTimer"));
	EXPECT_EQ(false, myTimerContainer->remove("MyTimer"));
}
