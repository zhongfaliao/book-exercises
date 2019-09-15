// Chapter-8.2.6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

template <class Ran, class X>
bool my_binary_search(Ran begin, Ran end, const X & x) {
	while (begin < end)
	{
		// find the mid point of the range
		Ran mid = begin + (end - begin) / 2;

		// see which part of the range contains x
		// keep looking only in that part
		if (x < *mid)
			end = mid;
		else if (*mid < x)
			begin = mid + 1;

		// if we got here, then *mid = x so we are done
		else
			return true;
	}
	return false;
}

int main()
{
	int my_array[] = { 1,3,4,5,6, 8, 9,10,12 };
	size_t my_size = sizeof(my_array) / sizeof(0);

	std::cout << my_binary_search(my_array, my_array + my_size, 8) << std::endl;

    return 0;
}

