#include "platform/opengl/gl_context.h"
#include "engine/render/shader.h"
#include <glad/glad.h>
#include "platform/window/window.h"
// #include <cglm/cglm.h> // uncomment to test cglm

int main()
{
    if (!window_create(1280, 720, "BuoyyVoxel"))
        return 1;

    if (!gl_context_init())
    {
        window_destroy();
        return 1;
    }

    const char *vert_src = 
    "#version 330 core\n"
    "layout (location = 0) in vec2 _pos;\n"
    "void main()\n"
    "{\n"
    "    gl_Position = vec4(_pos, 0.0, 1.0);\n"
    "}\n";

    const char *frag_src = 
    "#version 330 core\n"
    "out vec4 final_color;\n"
    "void main()\n"
    "{\n"
    "    final_color = vec4(0.5, 0.2, 0.7, 1.0);\n"
    "}\n";

    Shader shader;
    if (!shader_create(&shader, vert_src, frag_src))
    {
        return 1;
    }

    while (!window_should_close())
    {
        glClear(GL_COLOR_BUFFER_BIT);

        window_poll_events();
        window_swap_buffers();
    }

    // cglm test
    // glm_vec3_print((vec3){1, 1, 0}, stdout);

    shader_destroy(&shader);
    window_destroy();
    return 0;
}