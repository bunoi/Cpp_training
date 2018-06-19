#include "int256.h"
#include <iostream>
#include <vector>

int main()
{
    int256 a(1987);
	int256 b(-16);
	int256 c(19);
	std::cout << sizeof(a) << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	a += b;
	std::cout << a << std::endl;

	int256 a2(255);
	int256 b2(255);
	std::cout << sizeof(a) << std::endl;
	std::cout << a2 << std::endl;
	std::cout << b2 << std::endl;
	a2 += b2;
	std::cout << a2 << std::endl;

	b = -b;
	std::cout << b << std::endl;
	int f;

	int256 a3(372);
	int256 b3(160);
	int256 c3;
	c3 = a3 - b3;
	a3 -= b3;
	std::cout << c3 << std::endl;
	std::cout << a3 << std::endl;

	std::cin >> f;
}