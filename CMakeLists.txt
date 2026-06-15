cmake_minimum_required(VERSION 3.14)
project(BuoyyVoxel)
set(CMAKE_C_STANDARD 99)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(ext/glfw)

set(INCLUDE_DIRS 
    ext
    src 
    ext/glfw/include 
    ext/cglm/include
)
if(WIN32)
    if(CMAKE_C_COMPILER_ID STREQUAL "MSVC") 
        set(LIBRARIES glfw opengl32)
        set(WARNINGS /W4)
    else()
        set(LIBRARIES glfw opengl32 gdi32 m)
        set(WARNINGS -Wall -Wextra -Werror)
    endif()
else()
set(LIBRARIES glfw GL)
set(WARNINGS -Wall -Wextra -Werror)
endif()

set(SOURCE_FILES 
    src/main.c
    
    src/glad.c
    
    src/stb_image.c

    src/tests/triangle_test.c
    src/tests/quad_test.c
    src/tests/cube_test.c

    src/engine/util/log.c
    src/engine/util/path.c
    src/engine/util/assert.c
    src/engine/util/file.c

    src/engine/render/shader.c
    src/engine/render/vertex_buffer.c
    src/engine/render/element_buffer.c
    src/engine/render/vertex_array.c
    src/engine/render/texture.c
    src/engine/render/mesh.c
    src/engine/render/primitives.c
    
    src/engine/world/camera.c
    src/engine/world/transform.c

    src/platform/opengl/gl_debug.c
    src/platform/window/window.c
    src/platform/opengl/gl_context.c
)

add_executable(game ${SOURCE_FILES})
target_include_directories(game PRIVATE ${INCLUDE_DIRS})
target_link_libraries(game PRIVATE ${LIBRARIES})
target_compile_options(game PRIVATE ${WARNINGS})
