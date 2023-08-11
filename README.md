# OpenGameInput

OpenGameInput (**OGI**, or "OG Input") is a **simple, platform-agnostic input abstraction layer meant for games, written in C++17**. 

## Building
### Prerequisites
- A C++17 compiler (MSVC, Clang, GCC, etc..)
- CMake
- Ninja (Windows and macOS only)

### Examples
To build examples, simply use `cmake -DBUILD_EXAMPLES=ON ..`. The examples should be located in the `examples` subdirectory of the build directory (e.g. `build/examples/test_info[.exe]`).

### Linux
Building on Linux is easy; just use the following commands:
```
git clone https://github.com/colleen05/OpenGameInput
cd OpenGameInput
mkdir build && cd build
cmake ..
make 
```

### Windows and macOS
Building with CMake for Visual Studio or Xcode can be a little more involved or redundant, so using the [Ninja](https://ninja-build.org/) build system can make the process a little easier. If you already know how to use CMake with your IDE, feel free to use whichever generator you please. The process will be much the same, just without Ninja.

1. If you do not have Ninja installed, do so now. Instructions can be found under the "Getting Ninja" section on the website linked above.
2. Use the following commands:
    ```
    git clone https://github.com/colleen05/OpenGameInput
    cd OpenGameInput
    mkdir build && cd build
    cmake -G Ninja ..
    ninja
    ```