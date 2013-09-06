/*
 * SimpleTimerTest.hh
 *
 *  Created on: Aug 30, 2013
 *      Author: georg
 */

#ifndef SIMPLETIMERTEST_HH_
#define SIMPLETIMERTEST_HH_

#include "SimpleTimer.hh"
#include "gtest/gtest.h"
#include "TimerFunctionMock.hh"


class SimpleTimerTest : public ::testing::Test
{
protected:

	virtual void SetUp();

	virtual void TearDown();
	TimerFunctionMock *timerFunctions;
	SimpleTimer *timer;
};

#endif /* SIMPLETIMERTEST_HH_ */
