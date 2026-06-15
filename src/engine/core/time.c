#include "engine/core/time.h"

#include <GLFW/glfw3.h>
#include <cglm/cglm.h>

float delta_time = 0.0f;
float elapsed_time = 0.0f;

static float last_time = 0.0f;

void time_update(void)
{
    float current_time = (float)glfwGetTime();

    delta_time = current_time - last_time;
    delta_time = glm_clamp(delta_time, 0.0f, 0.1f);
    elapsed_time = current_time;

    last_time = current_time;
}