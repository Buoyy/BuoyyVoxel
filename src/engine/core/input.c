#include "engine/core/input.h"

#include "platform/window/window.h"
#include <GLFW/glfw3.h>

bool mouse_inverted = false;
float mouse_sens = 0.1f;

static double last_mouse_x;
static double last_mouse_y;
static double mouse_x;
static double mouse_y;

void input_init(void)
{
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwGetCursorPos(window, &mouse_x, &mouse_y);

    last_mouse_x = mouse_x;
    last_mouse_y = mouse_y;
}

void input_update(void)
{
    last_mouse_x = mouse_x;
    last_mouse_y = mouse_y;
    glfwGetCursorPos(window, &mouse_x, &mouse_y);
}

bool input_key_down(int key)
{
    return glfwGetKey(window, key) == GLFW_PRESS;
}

bool input_mouse_down(int button)
{
    return glfwGetMouseButton(window, button) == GLFW_PRESS;
}

float input_mouse_dx(void)
{
    return (mouse_x-last_mouse_x);
}

float input_mouse_dy(void)
{
    return mouse_inverted ? (mouse_y-last_mouse_y) : (last_mouse_y-mouse_y);
}

