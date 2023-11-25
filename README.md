# Cross-platform C++ playground

## Introduction

This repo is for experimenting with building cross-platform C++ in Visual Studio (with an emphasis on module-based code) across Windows and Linux and across the big three C++ compilers: MSVC, GCC and Clang. It also functions as a useful testing ground for evaluating support of various different C++ features across the big three compilers. This repo was originally borne out of some experiments I did in my cpp-playground repo, before I realised this isn't just any other random experiment, but something worthwhile pursuing in a separate repo.

I intend to add CMake into the mix at some point, just to make things even more complicated.

## Cross-compiling and building C++ with Visual Studio

### Set up

This repo assumes you work on a Windows machine with WSL2 and that Visual Studio 2022 is your primary IDE. You'll need the _Desktop development with C++_ and the _Linux and embedded development with C++_ workloads. Building for Clang requires the _C++ Clang Compiler for Windows_ and _MSBuild Support for LLVM (clang-cl) toolset_ optional components.

### Building for Clang

Visual Studio's Clang support requires installing the Clang components -- [follow this for more info](https://learn.microsoft.com/en-us/cpp/build/clang-support-msbuild?view=msvc-170).

### Building for Linux

* You need a WSL2 distro running on your machine. I use Ubuntu. You can list your WSL2 instances with `wsl --list -v`.
* Install the required tools for Visual Studio on your WSL2 VM: `sudo apt install -y openssh-server build-essential gdb rsync make zip`
* [Enable SSH on the VM](https://jmmv.dev/2022/02/wsl-ssh-access.html). Test locally with `ssh -p 22 <username>@localhost`.
* Configure Visual Studio  to connect to the VM: `TOOLS > Options > Cross Platform > Connection Manager`.
* [Install additional GCC/g++ versions if necessary](https://phoenixnap.com/kb/install-gcc-ubuntu) (I use GCC-13/g++-13). Update the C++ Compiler option to point to the preferred compiler (and don't forget to change the language standard and enable additional flags like `-fmodules-ts` as appropriate for your compiler).
* You should be able to open the solution and build any one of the projects. If building for Linux, your WSL2 distro _needs_ to be running (you can log into it with `wsl ~` assuming you've set it as your default).

## Notes

GCC's and Clang's support for C++20 modules is still a bit flaky and lags behind MSVC's support. In GCC-13, `#including <chrono>` appears to cause an ICE and GCC also appears to dislike it when a module implementation unit (e.g. `somemodule.cpp`) has the same name as its module interface unit (e.g. `somemodule.ixx`). I wasn't able to get modules behaving in Visual Studio with Clang, but I could build them by dropping to the `x64 Native Tools Command Prompt for VS 2022` tool and following Rainer Grimm's instructions (linked below). One thing to note with Clang's implementation is the `.cppm` extension that gets compiled into a `.pcm` file.

## Additional resources

* [C++20: Module Support of the Big Three](https://www.modernescpp.com/index.php/c20-module-support-of-the-big-three-compilers/)
* [C++20: More Details about Module Support of the Big Three](https://www.modernescpp.com/index.php/c20-more-details-about-module-support-of-the-big-three/)
* [Clang/LLVM support in Visual Studio projects](https://learn.microsoft.com/en-us/cpp/build/clang-support-msbuild?view=msvc-170)
* [Walkthrough: Build and debug C++ with WSL 2 and Visual Studio 2022](https://learn.microsoft.com/en-us/cpp/build/walkthrough-build-debug-wsl2?view=msvc-170)
* [Tutorial: Create C++ cross-platform projects in Visual Studio](https://learn.microsoft.com/en-us/cpp/build/get-started-linux-cmake?view=msvc-170)
* [C++ Compiler Support](https://en.cppreference.com/w/cpp/compiler_support): useful to ensure features used in your cross-platform code align with your available compilers.
