#include <vector>
#include <cstdint>
#include <iostream>

class int256
{
public:
	friend class MyTestSuite1;
	int256();
	int256(const int256& n);
	int256(int256&& n);
    int256(uint64_t x);

	~int256() {};

	int256& operator = (const int256& n);
	int256& operator = (int256&& n);

	int256& operator - ();

	int256& operator += (const int256& n);
	int256& operator -= (const int256& n);
	int256& operator <<= (const int bit);
	int256& operator >>= (const int bit);

	int256 operator + (const int256 a);
	int256 operator - (const int256 a);

	template<typename T>
	friend T& operator>>(T& is, int256& n);
	template<typename T>
	friend T& operator<<(T& os, int256& n)
	{
		for (int i = 0; i < 8; ++i)
		{
			os << (int)n.digit[i] << " ";
		}
		return os;
	}


protected:
	uint32_t digit[8];
};
