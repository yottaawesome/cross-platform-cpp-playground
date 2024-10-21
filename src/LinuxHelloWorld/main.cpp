#include <string>
#include <format>

import somemodule;

template<typename T>
concept Something = requires(T t)
{
    t();
};

template<typename V, template<typename T1> typename T2>
void Func() {}

int main()
{
    Func<int, Something>();
    SomeModule::SomeClass sc;
    SomeModule::SomeFunction();
    return 0;
}