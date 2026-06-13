#include "tests/quad_test.h"

#include "engine/render/mesh.h"
#include "engine/render/shader.h"
#include "engine/util/log.h"
#include "platform/opengl/gl_context.h"
#include <glad/glad.h>
#include <stdbool.h>
#include "platform/window/window.h"

int quad_test_run(void)
{
    LOG_INFO("RUNNING TEST: triangle_test.c");
    if (!window_create(1280, 720, "BuoyyVoxel"))
        return 1;

    if (!gl_context_init())
    {
        window_destroy();
        return 1;
    }

    Shader shader;
    if (!shader_create_from_file(&shader, "res/shaders/simple.vert", "res/shaders/simple.frag"))
    {
        LOG_ERROR("Couldn't create shader 'simple'");
        return 1;
    }

    const float vertices[] = 
    {
        -0.5f,  -0.5f, 
         0.5f,  -0.5f,
         0.5f,   0.5f,
        -0.5f,   0.5f
    };

    const unsigned int indices[] = 
    {
        0, 1, 2,
        2, 3, 0
    };

    Mesh quad;
    mesh_create(&quad, vertices, sizeof(vertices), indices, sizeof(indices));

    shader_bind(&shader);
    while (!window_should_close())
    {
        glClear(GL_COLOR_BUFFER_BIT);

        mesh_draw(&quad);

        window_poll_events();
        window_swap_buffers();
    }

    shader_destroy(&shader);
    mesh_destroy(&quad);
    window_destroy();
    return 0;
}