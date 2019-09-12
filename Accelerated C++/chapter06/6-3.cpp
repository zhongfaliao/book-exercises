#include <algorithm>
#include <vector>

using namespace std;

int main() {
  
  vector<int> u(10, 100);
  vector<int> v;
  
  // copy u's elements to v
  // in the end, in a reversed order
  copy(u.begin(), u.end(), v.begin());
  
  return 0;
}
