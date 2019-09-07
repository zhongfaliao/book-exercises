#include <algorithm>
#include <list>
#include <iostream>
#include <string>
#include <ctime>

#include "Student_info.h"
#include "grade.h"

//driver program for grade partitioning examples

using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::string;
using std::list;


using std::max;

list<Student_info> extract_fails(list<Student_info>& students) {
  list<Student_info> fail;

  list<Student_info>::iterator iter = students.begin();

  while (iter != students.end()) {
    if (fgrade(*iter)) {
      fail.push_back(*iter);
      iter = students.erase(iter);
    } else
      ++iter;
  }

  return fail;
}

int main() {
  list<Student_info> vs;
  Student_info s;
  string::size_type maxlen = 0;
  while (read(cin, s)) {
    maxlen = max(maxlen, s.name.size());
    vs.push_back(s);
  }

  vs.sort(compare);

  clock_t start = clock();
  list<Student_info> fails = extract_fails(vs);
  clock_t elapsed = clock() - start;

  cout << "Elapsed: " << elapsed << endl;

  //  for (list<Student_info>::const_iterator i = fails.begin(); i != fails.end(); ++i)
  //    cout << i->name << " " << grade(*i) << endl;

  return 0;
}
