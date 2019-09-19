#include <algorithm>
#include <iostream>

#include "PF-grader.h"

using namespace std;

// the following definitions act as the SOURCE CODE for "PF-grader.h"

PF_grader::PF_grader() { }

void PF_grader::add_student(Student_info student) {
  students.push_back(student);
  
  sort(students.begin(), students.end(), compare); // every time a new student is added
  // sort the new container
}

void PF_grader::print_grades() const {
  for (vector<Student_info>::const_iterator i = students.begin(); i != students.end(); ++i) {
    string pf = (i->passing()) ? "P" : "F";
    cout << i->name() << ": " << pf << endl;
  }
}

int main() {
  PF_grader pf_grader;
  Student_info student;

  while (student.read(cin)) pf_grader.add_student(student);
  pf_grader.print_grades();

  return 0;
}
