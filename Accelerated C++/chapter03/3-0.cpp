#include<iomanip> // defines the manipulator setprecision
#include<iostream>
#include<ios> // this header defines streamsize
#include<string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::setprecision;
using std::streamsize;

int main()
{
	//ask for and read the studnet's name
	cout << "Please enter your first name: ";
	string name;
	cin >> name;
	cout << "Hello, " << name << "!" << endl;

	//ask for and read the midterm and final grades
	cout << "Please enter your midterm and final exam grades: ";
	double midterm, final;
	cin >> midterm >> final;

	//ask for the homework grades
	cout << "Enter all your homework grades, "
		"followed by end-of-file: ";

	//the number and sum of grades read so far
	int count = 0;
	double sum = 0;

	//a variable into which to read
	double x;
	//invariant:
	//we have read count grades so far, and
	//sum is the sum of the first count grades

	while (cin >> x) {
		++count;
		sum += x;

	}

	//write the result
	streamsize prec = cout.precision(); // store the old settings of precision
	cout << "Your final grade is " << setprecision(3) // set our precision
		<< 0.2*midterm + 0.4*final + 0.4*sum / count
		<< setprecision(prec) << endl; //re-store the previous settings
		
}
