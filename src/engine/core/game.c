#include "engine/core/game.h"

#include "engine/core/input.h"
#include "engine/core/time.h"
#include "engine/render/mesh.h"
#include "engine/render/primitives.h"
#include "engine/render/shader.h"
#include "engine/render/texture.h"
#include "engine/util/common.h"
#include "engine/util/log.h"
#include "engine/world/camera.h"
#include "platform/opengl/gl_context.h"
#include "platform/window/window.h"
#include <cglm/mat4.h>
#include <stdbool.h>

#define SCR_WIDTH 1280
#define SCR_HEIGHT 720

static Camera camera;
static float camera_speed = 3.0f;

static Shader shader;
static Texture texture;
static Mesh mesh;

static void camera_handle_input(Camera *camera);

bool game_init(void)
{
    LOG_INFO("Initializing game...");

    if (!window_create(SCR_WIDTH, SCR_HEIGHT, "BuoyyVoxel"))
        return false;

    if (!gl_context_init())
    {
        window_destroy();
        return false;
    }

    input_init();

    camera_create(&camera, SCR_WIDTH, SCR_HEIGHT);

    if (!shader_create_from_file(&shader, 
        "res/shaders/textured_cube.vert", "res/shaders/textured_cube.frag"))
    {
        LOG_ERROR("Couldn't create shader 'simple'");
        return 1;
    }
    shader_bind(&shader);
    shader_set_mat4(&shader, "projection", camera.projection);

    texture_create_default(&texture, 0, "res/images/dirt.png", GL_RGBA);
    shader_set_int(&shader, "tex", 0);

    mesh_create(&mesh, cube_vertices, ARR_LEN(cube_vertices), 
        cube_indices, ARR_LEN(cube_indices));

    return true;
}

bool game_running(void)
{
    return !window_should_close();
}

void game_update(void)
{
    window_poll_events();
    input_update();
    time_update();

    if (input_key_down(GLFW_KEY_ESCAPE))
        glfwSetWindowShouldClose(window, true);
    camera_handle_input(&camera);
    camera_update(&camera);
}

void game_render(void)
{
    shader_set_mat4(&shader, "model", GLM_MAT4_IDENTITY);
    shader_set_mat4(&shader, "view", camera.view);
    mesh_draw(&mesh);
    window_swap_buffers();
}

void game_shutdown(void)
{
    LOG_INFO("Shutting down game...");
    shader_destroy(&shader);
    texture_destroy(&texture);
    mesh_destroy(&mesh);
    window_destroy();
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