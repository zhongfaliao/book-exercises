#include <iostream>
#include <string>
using std::string;

int main() {
	{string s = "a string";

	{string x = s + ", really";
	std::cout << s << std::endl; }

	std::cout << x << std::endl; // this line is wrong
  
	}
	return 0;
}
