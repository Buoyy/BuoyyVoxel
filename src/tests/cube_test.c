#include "tests/cube_test.h"

#include <GLFW/glfw3.h>
#include "platform/window/window.h"
#include "engine/util/log.h"
#include "engine/util/common.h"
#include "engine/render/shader.h"
#include "engine/render/mesh.h"
#include "engine/render/primitives.h"
#include "engine/render/camera.h"
#include "platform/opengl/gl_context.h"
#include <cglm/cglm.h>

#define SCR_WIDTH 1280
#define SCR_HEIGHT 720

int cube_test_run(void)
{
    LOG_INFO("RUNNING TEST: cube_test.c");
    if (!window_create(SCR_WIDTH, SCR_HEIGHT, "BuoyyVoxel"))
        return 1;

    if (!gl_context_init())
    {
        window_destroy();
        return 1;
    }

    Camera camera;
    camera_create(&camera, SCR_WIDTH, SCR_HEIGHT);

    Shader shader;
    if (!shader_create_from_file(&shader, "res/shaders/simple.vert", "res/shaders/simple.frag"))
    {
        LOG_ERROR("Couldn't create shader 'simple'");
        return 1;
    }
    shader_bind(&shader);
    shader_set_mat4(&shader, "projection", camera.projection);

    Mesh cube;
    mesh_create(&cube, cube_vertices, ARR_LEN(cube_vertices), 
        cube_indices, ARR_LEN(cube_indices));

    float orbit_radius = 3.0f;

    while (!window_should_close())
    {
        window_poll_events();

        vec3 cam_pos = 
        {
            orbit_radius*cos(glfwGetTime()),
            1.0f,
            orbit_radius*sin(glfwGetTime())
        };
        glm_vec3_copy(cam_pos, camera.position);

        // camera_update(&camera);
        glm_lookat(camera.position, GLM_VEC3_ZERO, camera.up, camera.view);
        shader_set_mat4(&shader, "view", camera.view);

        mesh_draw(&cube);
        window_swap_buffers();
    }

    shader_destroy(&shader);
    mesh_destroy(&cube);
    window_destroy();
    return 0;
}