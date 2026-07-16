#include "tests/cube_test.h"

#include <GLFW/glfw3.h>
#include "engine/core/input.h"
#include "engine/core/time.h"
#include "platform/window/window.h"
#include "engine/util/log.h"
#include "engine/util/common.h"
#include "engine/render/backend/shader.h"
#include "engine/render/backend/mesh.h"
#include "engine/render/backend/texture.h"
#include "engine/render/backend/primitives.h"
#include "engine/world/camera.h"
#include "engine/world/transform.h"
#include "platform/opengl/gl_context.h"
#include <cglm/cglm.h>

#define SCR_WIDTH 1280
#define SCR_HEIGHT 720

static void camera_handle_input(Camera *camera);
static float camera_speed = 3.0f;

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

    input_init();

    Camera camera;
    camera_create(&camera, SCR_WIDTH, SCR_HEIGHT);

    Shader shader;
    if (!shader_create_from_file(&shader, 
        "res/shaders/textured_cube.vert", "res/shaders/textured_cube.frag"))
    {
        LOG_ERROR("Couldn't create shader 'simple'");
        return 1;
    }
    shader_bind(&shader);
    shader_set_mat4(&shader, "projection", camera.projection);

    Texture dirt;
    texture_create_default(&dirt, 0, "res/images/dirt.png", GL_RGBA);
    shader_set_int(&shader, "tex", 0);

    Mesh cube;
    mesh_create(&cube, cube_vertices, ARR_LEN(cube_vertices), 
        cube_indices, ARR_LEN(cube_indices));
    Transform cube_transform;
    transform_create(&cube_transform);

    // float orbit_radius = 3.0f;

    while (!window_should_close())
    {
        window_poll_events();
        input_update();
        time_update();

        if (input_key_down(GLFW_KEY_ESCAPE))
            glfwSetWindowShouldClose(window, true);

        // vec3 cam_pos = 
        // {
        //     orbit_radius*cos(glfwGetTime()),
        //     1.0f,
        //     orbit_radius*sin(glfwGetTime())
        // };
        // glm_vec3_copy(cam_pos, camera.position);

        camera_handle_input(&camera);
        camera_update(&camera);
        // glm_lookat(camera.position, GLM_VEC3_ZERO, camera.up, camera.view);
        shader_set_mat4(&shader, "view", camera.view);

        // Rotate cube (like crazy)
        glm_vec3_copy((vec3){0, 0, 0.3*fabs(sin(glfwGetTime()))}, cube_transform.rotation);
        transform_update(&cube_transform);
        shader_set_mat4(&shader, "model", cube_transform.model);

        mesh_draw(&cube);
        window_swap_buffers();
    }

    shader_destroy(&shader);
    mesh_destroy(&cube);
    window_destroy();
    return 0;
}

static void camera_handle_input(Camera *camera)
{
    camera_rotate(camera, 
            mouse_sens*input_mouse_dy(), mouse_sens*input_mouse_dx());
    if (input_key_down(GLFW_KEY_W))
        camera_move(camera, CAMERA_FRONT, camera_speed*delta_time);
    if (input_key_down(GLFW_KEY_S))
        camera_move(camera, CAMERA_FRONT, -camera_speed*delta_time);
    if (input_key_down(GLFW_KEY_D))
        camera_move(camera, CAMERA_RIGHT, camera_speed*delta_time);
    if (input_key_down(GLFW_KEY_A))
        camera_move(camera, CAMERA_RIGHT, -camera_speed*delta_time);
    if (input_key_down(GLFW_KEY_SPACE))
        camera_move(camera, CAMERA_WORLD_UP, camera_speed*delta_time);
    if (input_key_down(GLFW_KEY_LEFT_SHIFT))
        camera_move(camera, CAMERA_WORLD_UP, -camera_speed*delta_time);
}
