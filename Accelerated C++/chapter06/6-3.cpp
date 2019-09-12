#include "stdafx.h"

#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

	vector<int> u = {1,2,3,4,5};
	vector<int> v;

	// copy u's elements to v
	
	// ERROR! the following does not compile
	//copy(u.begin(), u.end(), v.begin());
	
	copy(u.begin(), u.end(), back_inserter(v));

	for (vector<int>::const_iterator i = v.begin(); i != v.end(); i++)
	{
		cout << *i << endl;
	}

	return 0;
}
