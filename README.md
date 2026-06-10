# BuoyyVoxel
Welcome to **BuoyyVoxel**. This is a voxel game engine I am making entirely in C with OpenGL. Think of it as a Minecraft clone, perhaps.

## Features:
### Basics
- Basic logging system with log levels and macros
- Assertions (self-explanatory)
- Visible debugging for OpenGL

## Engine
- A simple, black window opens up for no reason at all (I programmed it)
- OpenGL debug messages with ARB_debug_output OpenGL extension

---

## How to build and run?
- Clone the repository by using this command:
- `git clone --recursive https://github.com/Buoyy/BuoyyVoxel.git`
- On Windows, use `build.bat`. 
- On Linux/Mac, use `build.sh`. 
- Should work on GCC and Clang for sure.
- Then `.\game.exe` on Windows or `./game` on Linux/Mac in root directory of the repository to run.

I haven't tested this on MSVC compilers, so if it fails, do tell me please. Thank you.

---
## Style Guide:
### Naming Convention:
- **Types/Structs:** PascalCase
- **Functions:** snake_case()
- **Variables:** snake_case
- **Macros/Enums:** UPPER_SNAKE_CASE
- **Files:** snake_case

### Code Blocks:
- Align your brackets. Be they parentheses, curly ones or square ones.