#include "engine/render/shader.h"
#include "engine/util/file.h"
#include "engine/util/log.h"
#include "platform/opengl/gl_context.h"
#include <glad/glad.h>
#include "platform/window/window.h"

int main()
{
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

    while (!window_should_close())
    {
        glClear(GL_COLOR_BUFFER_BIT);

        shader_bind(&shader);

        window_poll_events();
        window_swap_buffers();
    }

    shader_destroy(&shader);
    window_destroy();
    return 0;
}