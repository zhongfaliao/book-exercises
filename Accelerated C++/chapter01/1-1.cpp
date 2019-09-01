#include <string>
using std::string;

int main() {
	const string hello = "Hello"; 
  // when a constant variable is defined, it must be initialized simultaneous
	const string message = hello + ", world" + "!";
	return 0;
}
