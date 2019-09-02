// chapter3-1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iomanip>
#include<iostream>
#include<ios>
#include<string>
#include<vector>
#include<algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::sort;
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

	//revised program
	double x;
	vector<double> homework;

	while (cin >> x) {
		homework.push_back(x);
		}

	//get the size of the vector variable homework;
	typedef vector<double>::size_type vec_sz;
	vec_sz size = homework.size();

	if (size == 0) {
		cout << endl << "You must enter your greades. "
			"Please try again." << endl;
		return 1;
	}

	// interesting thing below, even though didn't define using std::sort, still works.
	sort(homework.begin(), homework.end());

	vec_sz mid = size / 2;
	double median;
	median = size % 2 == 0 ? (homework[mid] + homework[mid]) / 2 : homework[mid];


	//write the result
	streamsize prec = cout.precision();
	cout << "Your final grade is " << setprecision(3)
		<< 0.2*midterm + 0.4*final + 0.4*median
		<< setprecision(prec) << endl;

}
