#include <iostream>
#include <vector>

#include "grade.h"
#include "Student_info.h"

using std::istream;
using std::vector;

double Student_info::grade() const {
  return ::grade(midterm, final, homework); // :: is to say grade() function in this line is not 
  // a member function of Student_info, rather is somewhere else defined
  // otherwise without ::, compiler would think we are calling a member function of Student_info
  // and complain about incorrect argument list
}

bool compare(const Student_info& x, const Student_info& y) {
  return x.name() < y.name();
}

Student_info::Student_info(): midterm(0), final(0) { } // we use "constructor initializers" to explicitly set them to zero
// otherwise, they could be random garbage, which we should avoid

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
  return in;
}
