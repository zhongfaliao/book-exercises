#include <iostream>

#include "Student_info.h"

using namespace std;

int main() {
  Student_info record; // created but the record.homework is not defined
  record.grade();      // trigger
  return 0;
}
