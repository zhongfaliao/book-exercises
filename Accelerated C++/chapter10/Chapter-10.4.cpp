// Chapter-10.4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>

#include <string>

int main(int argc, char** argv)
{
	// Chapter-10.4.cpp
	
	// if there are arguments

	/*if (argc > 1)
	{
		int i;
		for (i = 1; i < argc -1 ; i++)
		{
			std::cout << argv[i] << " ";
		}
		std::cout << argv[i] << std::endl;
	}
    return 0;*/

	// Chapter-10.5.cpp

	std::ifstream myInFile("my_in_file.txt");
	std::ofstream myOutFile("my_out_file.txt");

	std::string s;

	while (getline(myInFile,s))
	{
		myOutFile << s << std::endl;
	}

	return 0;
}
