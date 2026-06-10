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

    while (!window_should_close())
    {
        glClear(GL_COLOR_BUFFER_BIT);

        window_poll_events();
        window_swap_buffers();
    }

    window_destroy();
    return 0;
}