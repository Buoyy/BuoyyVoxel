# BuoyyVoxel
Welcome to **BuoyyVoxel**. This is a voxel game engine I am making entirely in C with OpenGL. Think of it as a Minecraft clone, perhaps.

## Features:
### Basics
- Basic logging system with log levels and macros
- Assertions (self-explanatory)
- Visible debugging for OpenGL

### Rendering
- A simple window opens up and shows a dirt block rotating like crazy for no reason at all (I programmed it)
- OpenGL debug messages with `ARB_debug_output` OpenGL extension
- Shader abstraction with external file support
- Vertex buffer, element buffer and vertex array abstraction
- Mesh abstraction with above
- Texture abstraction

### Engine
- Time and Input module
- Minimal main file through game abstraction
- Free Camera system, move around with WASD and rotate with mouse (change mouse_invert in engine/core/input.c if you need to)
- Transforms (Position, Rotation and Scale)

---

## How to build and run?
- Clone the repository recursively by using this command:
- `git clone --recursive https://github.com/Buoyy/BuoyyVoxel.git`
- On Windows, use `build_msvc.bat` if using Visual Studio as a compiler, else use `build_!msvc.bat`. 
- On Linux/Mac, use `build.sh`. 
- Should work on GCC and Clang for sure.
- Then `.\game.exe` on Windows or `./game` on Linux/Mac in root directory of the repository to run.

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