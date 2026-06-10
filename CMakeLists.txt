cmake_minimum_required(VERSION 3.14)
project(BuoyyVoxel)
set(CMAKE_C_STANDARD 99)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(INCLUDE_DIRECTORIES ext src)
if(WIN32)
    if(CMAKE_<LANG>_COMPILER_ID STREQUAL "MSVC") 
        set(LIBRARIES glfw3 opengl32)
        set(WARNINGS /W4)
    else()
        set(LIBRARIES glfw3 opengl32 gdi32 m)
        set(WARNINGS -Wall -Wextra -Werror)
    endif()
else()
set(LIBRARIES glfw3 GL)
set(WARNINGS -Wall -Wextra -Werror)
endif()

set(SOURCE_FILES 
    src/main.c
    src/glad.c
    src/stb_image.c
    src/engine/util/log.c
    src/engine/util/path.c
    src/engine/util/assert.c

    src/platform/opengl/gl_debug.c
    src/platform/window/window.c
    src/platform/opengl/gl_context.c
)

add_executable(game ${SOURCE_FILES})
target_include_directories(game PRIVATE ${INCLUDE_DIRECTORIES})
target_link_libraries(game PRIVATE ${LIBRARIES})
target_compile_options(game PRIVATE ${WARNINGS})
