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
		TS_ASSERT_EQUALS(a.digit[7], 17);
	}

	void testInt256Addition(void)
	{
		int256 a = 89;
		int256 b = 72;
		int256 c = 162;
		TS_ASSERT(a+b != c);
		//TS_ASSERT_EQUALS(a+b, c);
	}

	void testInt256Multiplication(void)
	{
		int256 a = 96;
		int256 b = 128;
		int256 c = 12288;
		TS_ASSERT_EQUALS(a*128,c);

		int256 a1 = 4294967295;
		int256 b1 = a1;
		int256 c1 = 18446744065119617025;
		TS_ASSERT_EQUALS(a1*a1 + 1, c1 + 1);


		// Write more case later
	}

	void testInt256Division(void)
	{
		int256 c = 12288;
		TS_ASSERT_EQUALS(c/128,96);

		int256 a1 = 789;
		TS_ASSERT_EQUALS(a1/10, 78);


		// Write more case later
	}
};
