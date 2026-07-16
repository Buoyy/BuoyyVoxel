#include "tests/quad_test.h"

#include "engine/render/backend/mesh.h"
#include "engine/render/backend/shader.h"
#include "engine/render/backend/texture.h"
#include "engine/util/log.h"
#include "engine/util/common.h"
#include "engine/render/backend/primitives.h"
#include "platform/opengl/gl_context.h"
#include <glad/glad.h>
#include <stdbool.h>
#include <stb_image.h>
#include "platform/window/window.h"

int quad_test_run(void)
{
    LOG_INFO("RUNNING TEST: quad_test.c");
    if (!window_create(1280, 720, "BuoyyVoxel"))
        return 1;

    if (!gl_context_init())
    {
        window_destroy();
        return 1;
    }

    Shader shader;
    if (!shader_create_from_file(&shader, 
        "res/shaders/textured_quad.vert", "res/shaders/textured_quad.frag"))
    {
        LOG_ERROR("Couldn't create shader 'simple'");
        return 1;
    }
    shader_bind(&shader);

    stbi_set_flip_vertically_on_load(true);
    Texture dirt;
    texture_create_default(&dirt, 0, "res/images/dirt.png", GL_RGBA);
    shader_set_int(&shader, "tex", 0);

    Mesh quad;
    mesh_create(&quad, quad_vertices, ARR_LEN(quad_vertices), 
        quad_indices, ARR_LEN(quad_indices));

    while (!window_should_close())
    {
        mesh_draw(&quad);

        window_poll_events();
        window_swap_buffers();
    }

    shader_destroy(&shader);
    mesh_destroy(&quad);
    window_destroy();
    return 0;
}
