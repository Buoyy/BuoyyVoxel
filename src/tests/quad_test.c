#include "tests/quad_test.h"

#include "engine/render/element_buffer.h"
#include "engine/render/shader.h"
#include "engine/render/vertex_array.h"
#include "engine/render/vertex_buffer.h"
#include "engine/util/log.h"
#include "platform/opengl/gl_context.h"
#include <glad/glad.h>
#include <stdbool.h>
#include <stdlib.h>
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

    VertexArray va;
    vertex_array_create(&va);
    vertex_array_bind(&va);

    VertexBuffer vb;
    vertex_buffer_create(&vb);
    vertex_buffer_bind(&vb);
    vertex_buffer_data(vertices, sizeof(vertices), false);

    ElementBuffer eb;
    element_buffer_create(&eb);
    element_buffer_bind(&eb);
    element_buffer_data(indices, sizeof(indices), false);

    vertex_array_add_attribute(0, 2, GL_FLOAT, GL_FALSE, 2*sizeof(float), NULL);

    shader_bind(&shader);
    while (!window_should_close())
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL);

        window_poll_events();
        window_swap_buffers();
    }

    shader_destroy(&shader);
    vertex_buffer_destroy(&vb);
    vertex_array_destroy(&va);
    window_destroy();
    return 0;
}