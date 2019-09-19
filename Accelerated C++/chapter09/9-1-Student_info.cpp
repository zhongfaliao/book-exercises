#include <iostream>
#include <vector>

#include "grade.h"
#include "9-1-Student_info.hpp"

using std::istream;
using std::vector;

double Student_info::grade() const {
  return g;
}

bool compare(const Student_info& x, const Student_info& y) {
  return x.name() < y.name();
}

Student_info::Student_info(): midterm(0), final(0) { } 
// name and homework variables can automatically implicitly initialized to empty string
// and 0.0 vector respectively, therefore no need to EXPLICITLY initialize them

Student_info::Student_info(istream& is) { read(is); }	

// read homework grades from an input stream into a 'vector<double>'
istream& read_hw(istream& in, vector<double>& hw) {
  if (in) {
    // get rid of previous contents
    hw.clear();

    // read homework grades
    double x;
    while (in >> x)
      hw.push_back(x);

    // clear the stream so that input will work for the next student
    in.clear();
  }

  return in;
}

istream& Student_info::read(istream& in) {
  in >> n >> midterm >> final;
  read_hw(in, homework);
  g = ::grade(midterm, final, homework); // agian, the :: is to tell the compiler that
  // not to call the member function, call the grade() defined somewhere else
  return in;
}


// note, if the default constructor is called to initialize a Student_info subject
// the grade variable 'g' is not set, it could be anything like garbage
