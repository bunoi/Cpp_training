#include "int256.h"
#include <iostream>

using namespace std;

const int ARRAY_SIZE = 8;
const int NUMBER_BIT = 32;
const uint64_t FIRST_1_BIT = 4611686018427387904;

int256::int256()
{
    for (int i = 0; i < ARRAY_SIZE; ++i)
        digit[i] = 0;
}
int256::int256(const int256& n)
{
	for (int i = 0; i < ARRAY_SIZE; ++i)
		digit[i] = n.digit[i];
}

int256::int256(int256&& n) 
{
	*this = n;
}
int256::int256(uint64_t x)
{	
    for (int i = 0; i < ARRAY_SIZE; ++i)
        digit[i] = 0;
    int lb = ARRAY_SIZE -1;
    while (x != 0 && lb >= 0)
    {
		std::cout << x << std::endl;
        digit[lb] = x & UINT32_MAX;
        x >>= NUMBER_BIT;
		lb--;
    }
}

int256& int256::operator= (const int256& n)
{
	for (int i = 0; i < ARRAY_SIZE; ++i)
		digit[i] = n.digit[i];
	return *this;
}

int256& int256::operator= (int256&& n)
{
	*this = n;
	return *this;
}

int256& int256::operator - ()
{
	for (int i = 0; i < ARRAY_SIZE; ++i)
	{
		digit[i] ^= UINT32_MAX;
	}

	int256 *temp = this;
	*temp += 1;
	return *this;
}
int256& int256::operator += (const int256& n)
{
	int rem = 0;
    for (int i = ARRAY_SIZE -1; i >= 0; i--)
    {
		bool oneth = ((uint64_t) digit[i] & FIRST_1_BIT) == FIRST_1_BIT;
		bool onen = ((uint64_t) n.digit[i] & FIRST_1_BIT) == FIRST_1_BIT;
		if (oneth && onen)
		{
			digit[i] += n.digit[i] + rem;
			rem = 1;
		}
		else if (!(oneth || onen))
		{
			digit[i] += n.digit[i] + rem;
			rem = 0;
		}
		else
		{
			digit[i] += n.digit[i] + rem;
			if (((uint64_t)digit[i] & FIRST_1_BIT) == FIRST_1_BIT)
			{
				rem = 0;
			}
			else
			{
				rem = 1;
			}
		}
    }
	return *this;
}

int256& int256::operator -= (const int256& n)
{
	int256 *temp = this;
	int256 nn = n;
	*temp += (-nn);
	return *this;
}

int256& int256::operator <<= (const int bit)
{
	return *this;
}

int256& int256::operator >>= (const int bit)
{
	return *this;
}

int256 int256::operator + (const int256 a)
{
	int256 temp(*this);
	temp += a;
	return temp;
}

int256 int256::operator - (const int256 a)
{
	int256 temp(*this);
	temp -= a;
	return temp;
}
// cin
/*template<typename T>
T& operator>>(T& is, int256& n)
{
    for ( int i = 0; i < digit.size(); ++i )
    {
        
    }
}

// cout
template<typename T>
T& operator<<(T& os, int256& n)
{
    for ( int i = 0; i < digit.size(); ++i )
    {
        os << digit[i] << " ";
    }
}*/
