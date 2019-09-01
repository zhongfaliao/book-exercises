#include <string>
using std::string;

int main() {
	const string exclam = "!"; 
  	// when a constant variable is defined, it must be initialized simultaneous
    
	const string message = "Hello" + ", world" + exclam;
  	// the above is wrong
  	// cannot add two string literals: "Hello" and ", world"
	return 0;
}
