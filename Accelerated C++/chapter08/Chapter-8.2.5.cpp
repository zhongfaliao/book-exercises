// Chapter-8.2.5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
template<class Bi>
void my_reverse(Bi begin, Bi end) {
	while (begin != end)
	{
		end--;
		if (begin != end)
		{
			std::swap(*begin++, *end);
		}
	}
}

int main()
{
	int myarray[] = { 1,2,3,4,5 };
	my_reverse(myarray, myarray + 5);

	std::cout << sizeof(myarray)/sizeof(0) << std::endl;
	
	std::cout << "**********" << std::endl;
	for (size_t i = 0; i < 5; i++)
	{
		std::cout << myarray[i] << std::endl;
	}
    return 0;
}

