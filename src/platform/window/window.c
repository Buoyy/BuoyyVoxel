#include "platform/window/window.h"

#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include "engine/util/log.h"

static GLFWwindow *window;

bool window_create(int width, int height, const char *title)
{
    if (!glfwInit())
    {
        LOG_ERROR("GLFW initialization failed");
        return false;
    }
    LOG_INFO("GLFW initialization succeeded");

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);
    LOG_INFO("OpenGL 3.3 Core Profile (with Debug Context) requested");

    window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (window == NULL)
    {
        LOG_ERROR("Window creation failed");
        glfwTerminate();
        return false;
    }
    glfwMakeContextCurrent(window);
    LOG_INFO("Successfully created window of resolution %dx%d named '%s'", 
        width, height, title);

    glEnable(GL_DEPTH_TEST);

    return true;
}

bool window_should_close(void)
{
    return glfwWindowShouldClose(window);
}

void window_poll_events(void)
{
    glfwPollEvents();
}

void window_swap_buffers(void)
{
    glfwSwapBuffers(window);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void window_destroy(void)
{
    if (window == NULL) return;

    LOG_INFO("Destroying window");
    glfwDestroyWindow(window);
    window = NULL;
    LOG_INFO("Destroyed window");

    LOG_INFO("Terminating GLFW");
    glfwTerminate();
    LOG_INFO("Terminated GLFW");
}
