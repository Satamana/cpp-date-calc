#include "stdafx.h"
#include "date.h"
int main()
{
	setlocale(0, "rus");
	date d1 (1,1,2001);
	std::cout << d1;
	date d2(9, 2, 2018);
	std::cout << d2;
	std::cout << d2.countdays() << std::endl;
	std::cout << d2 - d1 << std::endl;
	d2 + 10;
	std::cout << d2;
    return 0;
}