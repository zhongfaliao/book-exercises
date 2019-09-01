#include <iostream>
#include <string>
using std::string;

int main() {
	{const string s = "a string";
	std::cout << s << std::endl;

	{const string s = "another string";
	std::cout << s << std::endl; }}

	return 0;
}
