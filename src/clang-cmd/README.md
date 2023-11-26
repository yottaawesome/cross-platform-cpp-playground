# Building modules with Clang and Visual Studio

## Introduction

Of the big three C++ compilers, Clang's support for C++ modules seems to be the weakest. The tooling support in Visual Studio for Clang also appears to be the weakest with GCC seemingly better supported. Nevertheless, this README details how to build modules via the VS developer command prompt. These instructions are adapted from Rainer Grimm's blog posts [here](https://www.modernescpp.com/index.php/c20-module-support-of-the-big-three-compilers/) and [here](https://www.modernescpp.com/index.php/c20-more-details-about-module-support-of-the-big-three/).

## Building from the `x64 Visual Studio Native Developer Command Prompt`

### Method 1

```
clang++ -std=c++20 -c somemodule.cppm --precompile -o somemodule.pcm
clang++ -std=c++20 main.cpp -fprebuilt-module-path=. somemodule.pcm -o test.exe
```

### Method 2

Compile module to pcm:

`clang++ -c -std=c++20 -fmodule-output somemodule.cppm -o somemodule.pcm`

Compile module with custom extension to pcm:

`clang++ -std=c++20 --precompile -x c++-module somemodule.ixx -o somemodule.pcm`

Compile pcm to o, then link and build
```
clang++ -std=c++20 -c somemodule.pcm -o somemodule.o
clang++ -std=c++20 -fprebuilt-module-path=. somemodule.o main.cpp -o test.exe
```

Compile with two modules:
`clang++ -std=c++20 -c main.cpp -fmodule-file=somemodule=anothermodule.pcm -o test.o`
