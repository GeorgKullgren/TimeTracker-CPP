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
}

void
NamedTimer_test::TearDown()
{
}

TEST_F(NamedTimer_test, test_create_named_timer_returns_current_time)
{
	time_t startTime = time(0);
	NamedTimer myTimerContainer;
	EXPECT_EQ(true, myTimerContainer.create("MyTimer"));
}
