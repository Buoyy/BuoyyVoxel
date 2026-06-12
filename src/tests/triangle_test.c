#include "tests/triangle_test.h"

#include "engine/render/shader.h"
#include "engine/render/vertex_buffer.h"
#include "engine/util/log.h"
#include "platform/opengl/gl_context.h"
#include <glad/glad.h>
#include <stdbool.h>
#include <stdlib.h>
#include "platform/window/window.h"

int triangle_test_run(void)
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
         0.0f,   0.5f, 
         0.5f,  -0.5f,
        -0.5f,  -0.5f
    };

    unsigned int vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    VertexBuffer vb;
    vertex_buffer_create(&vb, vertices, sizeof(vertices), false);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2*sizeof(float), NULL);
    glEnableVertexAttribArray(0);

    shader_bind(&shader);
    while (!window_should_close())
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawArrays(GL_TRIANGLES, 0, 3);

        window_poll_events();
        window_swap_buffers();
    }

    shader_destroy(&shader);
    vertex_buffer_destroy(&vb);
    window_destroy();
    return 0;
}