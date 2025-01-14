// source file for the 'median' function
#include <algorithm>    // to get the declaration of 'sort'
#include <stdexcept>    // to get the declaration of 'domain_error'
#include <vector>       // to get the declaration of 'vector'

using std::domain_error;   
using std::sort;   
using std::vector;

#include "median.h"

// compute the median of a 'vector<double>'
// note that calling this function copies the entire argument 'vector'

// why do we need to copy the vector?
// because calling .sort() changes the vector

double median(vector<double> vec)
{

  typedef std::vector<double>::size_type vec_sz;

  vec_sz size = vec.size();
  if (size == 0)
    throw domain_error("median of an empty vector");

  sort(vec.begin(), vec.end());

  vec_sz mid = size/2;

  // test whether the size is even or odd
  return size % 2 == 0 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid]; 
}
