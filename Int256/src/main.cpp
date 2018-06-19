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

	std::cout << "Multiplication"<< std::endl;
	int256 a4(96);
	int256 b4(128);
	int256 c4;
	c4 = a4 * b4;
	std::cout << c4 << std::endl;
	std::cout << a4 << std::endl;

	uint64_t f1 = 4294967295 * 4294967295;
	std::cout << f1;


	// P swiss example
	std::cout << "Example 1" << std::endl;
	int256 x = 300;
	int256 y = -500;
	x *= 3000;
	x = x + y;
	std::cout << x << std::endl;  // print 899500
	std::cout << sizeof(x) << std::endl; // print 32


	// std::cin >> f;
}