#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <stdexcept>
#include <vector>

#include "Student_info.h"
#include "grade.h"
#include "median.h"

using std::accumulate;           using std::back_inserter;
using std::domain_error;         using std::endl;
using std::ostream;              using std::remove_copy;
using std::string;               using std::transform;
using std::vector;

bool did_all_hw(const Student_info& s) {
	// return the iterator/address starting from .begin() where the first '0' is
	// found. If the find() function returns .end(), it means no '0' is found in
	// s. Conclusion: the student did all the homework.
	return ((find(s.homework.begin(), s.homework.end(), 0)) == s.homework.end());
}

double grade_aux(const Student_info& s) {
  try {
    return grade(s);
  } catch (domain_error) {
	  // student not done any homework, pass '0' as homework to the overload function grade()
    return grade(s.midterm, s.final, 0); 
  }
}

// this version works fine
double median_analysis(const vector<Student_info>& students) {
  vector<double> grades;

  transform(students.begin(), students.end(),
	    back_inserter(grades), grade_aux);

  return median(grades);
}

void write_analysis(ostream& out, const string& name,
                    double analysis(const vector<Student_info>&),
		    // THIS ARGUMENT is defined be to a function which takes vector<Student_info>& as input
		    // when write_analysis is called in  the main(){} function, we are going to pass the actual
		    // function to use
		    
                    const vector<Student_info>& did,
                    const vector<Student_info>& didnt) {
  out << name << ": median(did) = " << analysis(did) <<
    ", median(didnt) = " << analysis(didnt) << endl;
}

double average(const vector<double>& v) {
	// the third argument of acccumulate(,,) is for typedef
	// e.g. here, '0.0' means we want a double type of return
  return accumulate(v.begin(), v.end(), 0.0) / v.size();
}

double average_grade(const Student_info& s) {
  return grade(s.midterm, s.final, average(s.homework));
}



double average_analysis(const vector<Student_info>& students) {
  vector<double> grades;

  transform(students.begin(), students.end(),
	    back_inserter(grades), average_grade);

  return median(grades);
}

// median of the nonzero elements of 's.homework', or '0' if no such elements exist
double optimistic_median(const Student_info& s) {
  vector<double> nonzero;
  remove_copy(s.homework.begin(), s.homework.end(),
	      back_inserter(nonzero), 0);

  if (nonzero.empty())
    return grade(s.midterm, s.final, 0);
  else
    return grade(s.midterm, s.final, median(nonzero));
}

double optimistic_median_analysis(const vector<Student_info>& students) {
  vector<double> grades;

  transform(students.begin(), students.end(),
	    back_inserter(grades), optimistic_median);

  return median(grades);
}
