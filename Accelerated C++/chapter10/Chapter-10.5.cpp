// Chapter-10.5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
	int fail_count = 0;

	// for each file in the input list
	for (int i = 1; i < argc; ++i) {
		ifstream in(argv[i]);

		// if it exists, write its contents,
		// otherwise generate an error message
		if (in)
		{
			string s;
			while (getline(in, s))
			{
				cout << s << endl;
			}
		}
		else
		{
			cerr << "cannot open file " << argv[i] << endl;
		}
	}
    return fail_count;
}
