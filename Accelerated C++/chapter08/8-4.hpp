
#include <iterator>

// the following do the same thing as
/*
#include <algorithm>
template <class Type>
void my_swap(Type& a, Type& b) {
    std::swap(a, b);
}
*/

template <class Type>
void my_swap(Type& a, Type& b) {
  Type c = a;
  a = b;
  b = c;
}
