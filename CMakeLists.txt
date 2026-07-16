cmake_minimum_required(VERSION 3.14)

project(BuoyyVoxel
    # VERSION 0.4.0
    LANGUAGES C
)

# ---------------------------------------------------------------------------
# Project settings
# ---------------------------------------------------------------------------

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "Exporting compile_commands.json")

# ---------------------------------------------------------------------------
# Dependencies
# ---------------------------------------------------------------------------

add_subdirectory(ext/glfw)

# ---------------------------------------------------------------------------
# Sources
# ---------------------------------------------------------------------------

set(CORE_SOURCES
    src/engine/core/game.c
    src/engine/core/input.c
    src/engine/core/time.c
)

set(UTIL_SOURCES
    src/engine/util/assert.c
    src/engine/util/dyn_array.c
    src/engine/util/file.c
    src/engine/util/log.c
    src/engine/util/path.c
)

set(RENDER_BACKEND_SOURCES
    src/engine/render/backend/element_buffer.c
    src/engine/render/backend/primitives.c
    src/engine/render/backend/shader.c
    src/engine/render/backend/texture.c
    src/engine/render/backend/vertex_array.c
    src/engine/render/backend/vertex_buffer.c
)

set(RENDER_RESOURCES_SOURCES
    src/engine/render/resources/mesh.c
    src/engine/render/resources/texture_atlas.c
)

set(WORLD_SOURCES
    src/engine/world/camera.c
    src/engine/world/chunk.c
    src/engine/world/transform.c
    src/engine/world/block_registry.c
)

set(PLATFORM_SOURCES
    src/platform/opengl/gl_context.c
    src/platform/opengl/gl_debug.c
    src/platform/window/window.c
)

set(THIRD_PARTY_SOURCES
    src/glad.c
    src/stb_image.c
)

# Disable pedantic warnings ONLY for THIRD_PARTY_SOURCES
if(NOT MSVC)
    set_source_files_properties(${THIRD_PARTY_SOURCES} PROPERTIES
        COMPILE_OPTIONS "-Wno-pedantic;-Wno-cast-qual"
    )
endif()
# Uncomment while developing individual tests
#
# set(TEST_SOURCES
#     src/tests/triangle_test.c
#     src/tests/quad_test.c
#     src/tests/cube_test.c
# )

# ---------------------------------------------------------------------------
# Executable
# ---------------------------------------------------------------------------

add_executable(game
    src/main.c

    ${THIRD_PARTY_SOURCES}
    ${CORE_SOURCES}
    ${UTIL_SOURCES}
    ${RENDER_BACKEND_SOURCES}
    ${RENDER_RESOURCES_SOURCES}
    ${WORLD_SOURCES}
    ${PLATFORM_SOURCES}

    # ${TEST_SOURCES}
)

# ---------------------------------------------------------------------------
# Includes
# ---------------------------------------------------------------------------

target_include_directories(game PRIVATE
    src
    ext
    ext/glfw/include
    ext/cglm/include
)

# ---------------------------------------------------------------------------
# Compiler warnings
# ---------------------------------------------------------------------------

if(MSVC)

    target_compile_options(game PRIVATE
        /W4
        /WX
    )

else()

    target_compile_options(game PRIVATE
        -Wall
        -Wextra
        -Werror

        -Wshadow
        -Wformat=2
        -Wundef
        -Wcast-qual
        -Wwrite-strings
        -Wstrict-prototypes
        -Wmissing-prototypes
    )

endif()

# ---------------------------------------------------------------------------
# Link libraries
# ---------------------------------------------------------------------------

target_link_libraries(game PRIVATE
    glfw
)

if(WIN32)

    target_link_libraries(game PRIVATE
        opengl32
        gdi32
    )

    if(NOT MSVC)
        target_link_libraries(game PRIVATE
            m
        )
    endif()

else()

    target_link_libraries(game PRIVATE
        GL
        m
    )

endif()
