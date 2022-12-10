# About
`nvd-demo` is a simple demonstration of [NvDialog's](https://github.com/AndroGR/nvdialog) functionality as a library. It shows a series of dialogs and features with a simple OpenGL window behind for reference.

# Dependencies
You will have to install:
- GLFW (For the main application window),
- GLEW (Used for some OpenGL functions) and
- CMake (To build the application and NvDialog)

# Installation
**First, clone this repository:**
```sh
$ git clone https://github.com/AndroGR/nvd-demo --recursive
$ cd nvd-demo/
```
**Afterwards, generate the build files:**
```sh
$ mkdir build && cd build/
$ cmake ..
```
**And finally, build the final application:**
```sh
$ cmake --build .
```
The executable will be available as `./nvd-demo`.