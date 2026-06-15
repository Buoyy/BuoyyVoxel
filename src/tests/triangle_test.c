#include "tests/triangle_test.h"

#include "engine/render/shader.h"
#include "engine/render/vertex_array.h"
#include "engine/render/vertex_buffer.h"
#include "engine/util/log.h"
#include "platform/opengl/gl_context.h"
#include "engine/render/primitives.h"
#include <glad/glad.h>
#include <stdbool.h>
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

    VertexArray va;
    vertex_array_create(&va);
    vertex_array_bind(&va);

    VertexBuffer vb;
    vertex_buffer_create(&vb);
    vertex_buffer_bind(&vb);
    vertex_buffer_data(triangle_vertices, sizeof(triangle_vertices), false);

    vertex_array_add_attribute(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), NULL);

    shader_bind(&shader);
    while (!window_should_close())
    {
        glDrawArrays(GL_TRIANGLES, 0, 3);

        window_poll_events();
        window_swap_buffers();
    }

    shader_destroy(&shader);
    vertex_buffer_destroy(&vb);
    vertex_array_destroy(&va);
    window_destroy();
    return 0;
}