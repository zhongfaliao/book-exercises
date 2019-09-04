//#include<string>
//#include<iostream>
//#include<iomanip>
//
//int square(int i) {
//	return i * i;
//}
//
//int main()
//{
//	std::cout << "Here is the output." << std::endl;
//	for (int i = 0; i < 10; ++i) {
//		std::cout << std::setw(3) << i << std::setw(5) << square(i) << std::endl;
//	}
//	std::cout << "End of output." << std::endl;
//    return 0;
//}

#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
	for (int i = 1; i <= 100; ++i) {
		cout << setw(3)
			<< i
			<< setw(6)
			<< i * i
			<< endl;
	}

	return 0;
}
