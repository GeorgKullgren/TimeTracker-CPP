/*
 * NamedTimer_test.cpp
 *
 *  Created on: 8 sep 2013
 *      Author: georg
 */

#include "NamedTimer.hh"
#include "NamedTimer_test.hh"

#include "gtest/gtest.h"
using ::testing::Return;

void
NamedTimer_test::SetUp()
{
	timerFunctions = new TimerFunctionMock;
}

void
NamedTimer_test::TearDown()
{
}

TEST_F(NamedTimer_test, test_create_named_timer_returns_current_time)
{
	NamedTimer myTimerContainer(timerFunctions);
	EXPECT_EQ(true, myTimerContainer.create("MyTimer"));
}

TEST_F(NamedTimer_test, test_create_two_named_timers)
{
	NamedTimer myTimerContainer(timerFunctions);
	EXPECT_EQ(true, myTimerContainer.create("MyTimer1"));
	EXPECT_EQ(true, myTimerContainer.create("MyTimer2"));
}

TEST_F(NamedTimer_test, test_create_and_start_timer)
{
	NamedTimer myTimerContainer(timerFunctions);
	EXPECT_EQ(true, myTimerContainer.create("MyTimer1"));
	EXPECT_NE(0, myTimerContainer.start("MyTimer1"));
}

TEST_F(NamedTimer_test, test_create_same_timer_twice_returns_false)
{
	NamedTimer myTimerContainer(timerFunctions);
	EXPECT_EQ(true, myTimerContainer.create("MyTimer1"));
	EXPECT_EQ(false, myTimerContainer.create("MyTimer1"));
}

TEST_F(NamedTimer_test, test_create_timer_and_start_twice_return_same_time)
{
	NamedTimer myTimerContainer(timerFunctions);
	EXPECT_EQ(true, myTimerContainer.create("MyTimer1"));

	time_t startTime = myTimerContainer.start("MyTimer1");
	EXPECT_EQ(startTime, myTimerContainer.start("MyTimer1"));
}


TEST_F(NamedTimer_test, test_create_and_start_two_timers_returns_different_times)
{
	NamedTimer myTimerContainer(timerFunctions);
	EXPECT_EQ(true, myTimerContainer.create("MyTimer1"));
	time_t startTime = myTimerContainer.start("MyTimer1");

	EXPECT_EQ(true, myTimerContainer.create("MyTimer2"));
	EXPECT_NE(startTime, myTimerContainer.start("MyTimer2"));
}


