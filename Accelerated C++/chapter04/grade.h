#ifndef GUARD_grade_h
#define GUARD_grade_h

// 'grade.h'

#include <vector>
#include "Student_info.h"

// overloading the function with different settings of arguments

double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
double grade(const Student_info&);

#endif
