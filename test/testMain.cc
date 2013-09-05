/*
 * testMain.cc
 *
 *  Created on: Aug 30, 2013
 *      Author: georg
 */
#include "gmock/gmock.h"



int main(int argc, char **argv)
{
	::testing::InitGoogleMock(&argc, argv);
	return RUN_ALL_TESTS();
}



