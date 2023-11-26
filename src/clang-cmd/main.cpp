// Clang in MSVC appears to be completely broken with modules
//#include <iostream> // Causes it to break
import somemodule;

int main(int argc, char* argv[])
{
	Blah::Oops("Hello, world!");
	return 0;
}
