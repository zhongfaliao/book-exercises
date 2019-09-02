#include<iostream>
#include<string>


int main()
{
	//ask for the person's name
	std::cout << "Please enter your first name: ";

	// read the name
	std::string name;
	std::cin >> name;

	//building the message that we intend to write
	const std::string greeting = "Hello, " + name + "!";

	// we have to rewrite the part ...
	// ask to input the number of padding
	std::wcout << "Please enter the number of padding: ";

	//read the number of padding
	
	
	int pad;
	std::wcin >> pad;
	

	//total number of rows to write
	const int rows = pad * 2 + 3;
	//separate the input from the output
	std::cout << std::endl;

	// number of columns in a row
	const std::string::size_type cols = greeting.size() + pad * 2 + 2;

	//write rows of output
	int r = 0;
	while (r!=rows) {
		//write a row of output (as we will describe in section 2.4)

		std::string::size_type c = 0;
		//invariant: we have written c characters so far in the current row
		while (c != cols) {
			if (r == pad + 1 && c == pad + 1) {
				std::cout << greeting;
				c += greeting.size();
			}
			else {
				if ((r == 0) || (r == rows - 1) || (c == 0) || (c == cols - 1))
					std::cout << "*";
				else
					std::cout << " ";
				++c;
			}
		}
		std::cout << std::endl;
		++r;
	}

	return 0;
}
