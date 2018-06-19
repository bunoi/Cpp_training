#include "int256.h"
#include <iostream>
#include <algorithm>

using namespace std;

const int ARRAY_SIZE = 8;
const int NUMBER_BIT = 32;
const uint64_t FIRST_1_BIT = 2147483648;
const uint64_t BLOCK = 4294967296;

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
        digit[lb] = x & UINT32_MAX;
        x >>= NUMBER_BIT;
		lb--;
    }
	if ( digit[ARRAY_SIZE-2] & FIRST_1_BIT  == FIRST_1_BIT )
	{
		for (int i=0; i <ARRAY_SIZE-2; i++ )
		{
			digit[i] = UINT32_MAX;
		}
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

int256& int256::operator *= (const int256& n)
{
	int256 temp;
	for (int i = 0; i < ARRAY_SIZE; ++i)
	{
		int pi = ARRAY_SIZE - i - 1;
		for (int j = 0; j < ARRAY_SIZE; ++j)
		{
			int pj = ARRAY_SIZE - j - 1;
			int pk = i - pj;
			if ( pk < 0 )	continue;
			int k = ARRAY_SIZE - pk - 1;
			uint64_t mul = (uint64_t) digit[j];
			mul *= n.digit[k];
			uint64_t left = mul >> 32;
			uint64_t right = mul & UINT32_MAX;
			
			// std::cout << mul << " " << left << " " << right << std::endl;
			right += temp.digit[pi];
			temp.digit[pi] = (uint32_t) (right & UINT32_MAX);
			if ( right > (uint64_t) UINT32_MAX )
			{
				temp.digit[pi-1]++;
				for (int ii = pi-1; ii > 0; ii--)
				{
					if (temp.digit[ii] == 0 )
					{
						temp.digit[ii-1]++;
					}
					else
					{
						break;
					}
				}
			}

			if (pi-1 < 0 )
				continue;
			left += temp.digit[pi-1];
			temp.digit[pi-1] = left & UINT32_MAX;
			if ( left > (uint64_t) UINT32_MAX )
			{				
				temp.digit[pi-2]++;
				for (int ii = pi-2; ii > 0; ii--)
				{
					if (temp.digit[ii] == 0 )
					{
						temp.digit[ii-1]++;
					}
					else
					{
						break;
					}
				}
			}
		}	
	}
	*this = temp;
	return *this;
}
int256& int256::operator /= (const uint32_t& n)
{
	uint64_t rem = 0;
	for (int i = 0; i < ARRAY_SIZE; ++i)
	{
		uint64_t sum = rem + digit[i];
		uint64_t res = sum / n;
		digit[i] = res;
		rem = (sum % n) * BLOCK;
	}
	return *this;
}

int256& int256::operator %= (const uint32_t& n)
{
	uint64_t rem = 0;
	for (int i = 0; i < ARRAY_SIZE-1; ++i)
	{
		uint64_t sum = rem + digit[i];
		uint64_t res = sum / n;
		digit[i] = 0;
		rem = (sum % n) * BLOCK;
	}
	uint64_t sum = rem + digit[7];
	sum %= n;
	digit[ARRAY_SIZE-1] = sum;
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

int256 int256::operator + (int256 a)
{
	int256 temp(*this);
	temp += a;
	return temp;
}

int256 int256::operator - (int256 a)
{
	int256 temp(*this);
	temp -= a;
	return temp;
}

int256 int256::operator * (int256 a)
{
	int256 temp(*this);
	temp *= a;
	return temp;
}

int256 int256::operator / (uint32_t a)
{
	int256 temp(*this);
	temp /= a;
	return temp;
}

int256 int256::operator % (uint32_t a)
{
	int256 temp(*this);
	temp %= a;
	return temp;
}
bool int256::operator == (const int256 a)
{
	for (int i = 0; i < ARRAY_SIZE; ++i)
	{
		if (digit[i] != a.digit[i])
			return false;
	}
	return true;
}

bool int256::operator < (const int256 a)
{
	bool neg = false;
	uint32_t f1 = digit[0] & FIRST_1_BIT;
	uint32_t f2 = a.digit[0] & FIRST_1_BIT;
	if ( f1 != f2 )
	{
		return f1 > f2;
	}
	if ( f1 == FIRST_1_BIT )	neg = true;
	for (int i = 0; i < ARRAY_SIZE; ++i)
	{
		if (digit[i] != a.digit[i])
			return (digit[i] < a.digit[i]) != neg;
	}
	return false;
}
std::string int256::tos()
{
	std::string S;
	int256 n = *this;
	bool neg = false;
	if ( n < 0 )
	{
		n = -n;
		neg = true;
	}
	while ( n != 0 )
	{
		int256 m = n % 10;
		n/= 10;
		S += '0' + m.digit[ARRAY_SIZE-1];
	}
	if(neg)
		S += '-';
	std::reverse(S.begin(),S.end());
	return S;
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
