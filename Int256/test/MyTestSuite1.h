#include <cxxtest/TestSuite.h>
#include "../include/int256.h"

class MyTestSuite1 : public CxxTest::TestSuite
{
public:
	void testAddition(void)
	{
		TS_ASSERT(1 + 1 > 1);
		TS_ASSERT_EQUALS(1 + 1, 2);
	}

	void testInt256(void)
	{
		int256 a = 17;
		TS_ASSERT_EQUALS(a.digit[7], 16);
	}
};