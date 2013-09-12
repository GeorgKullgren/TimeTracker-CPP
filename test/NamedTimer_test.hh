/*
 * NamedTimer_test.hh
 *
 *  Created on: 8 sep 2013
 *      Author: georg
 */

#ifndef NAMEDTIMER_TEST_HH_
#define NAMEDTIMER_TEST_HH_

#include "gmock/gmock.h"
#include "TimerFunctionMock.hh"

class NamedTimer_test : public ::testing::Test
{
protected:
	virtual void SetUp();
	virtual void TearDown();

	TimerFunctionMock *timerFunctions;
	NamedTimer *myTimerContainer;
};


#endif /* NAMEDTIMER_TEST_HH_ */
