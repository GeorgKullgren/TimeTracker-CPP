#include "SimpleTimerTest.hh"

TEST_F(SimpleTimerTest, test_create_timer)
{
	SimpleTimer timer;
	EXPECT_EQ(true, timer.createTimer());
}

TEST_F(SimpleTimerTest, test_start_timer)
{
	SimpleTimer timer;
	timer.startTimer();
}
