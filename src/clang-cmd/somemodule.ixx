module;

#include <string>
#include <iostream>

export module somemodule;

export namespace Blah
{
	void Oops(std::string_view s)
	{
		std::cout << s << std::endl;
	}
}