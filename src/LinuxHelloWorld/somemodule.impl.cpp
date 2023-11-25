module;

#include <iostream>

module somemodule;

// GCC craps out if the implementation file 
// has the same name as the ixx file.
namespace SomeModule
{
	void SomeFunction() 
	{
		std::cout << "Hello, world!\n";
	}
}