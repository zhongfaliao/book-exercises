#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

#include "6-8-classify.h"
#include "Student_info.h"
#include "grade.h"

//driver program for grade partitioning examples

using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::string;
using std::vector;


using std::max;


int main() {
  vector<Student_info> vs;
  Student_info s;
  string::size_type maxlen = 0;
  while (read(cin, s)) {
    maxlen = max(maxlen, s.name.size());
    vs.push_back(s);
  }

  sort(vs.begin(), vs.end(), compare);

  vector<Student_info> fails = classify(vs, pgrade);

  for (int i = 0; i < fails.size(); ++i)
    cout << fails[i].name << " " << grade(fails[i]) << endl;

  return 0;
}
