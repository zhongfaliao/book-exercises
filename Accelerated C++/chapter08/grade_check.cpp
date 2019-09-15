#include <algorithm>

#include "Student_info.h"

using std::find;

bool did_all_hw(const Student_info& s) {
  return (	(	find(s.homework.begin(), s.homework.end(), 0)   ) == s.homework.end()	);
	// find the first location where the element of s.homework is equal to 0
	// if no 0 is found between [begin() , end() ), then means the student did all the homework
}
