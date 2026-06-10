#include "platform/opengl/gl_context.h"

#include "engine/util/log.h"
#include "gl_debug.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

bool gl_context_init(void)
{
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        LOG_ERROR("GLAD initialization failed");
        return false;
    }
    LOG_INFO("GLAD initialization succeeded");

#ifndef NDEBUG
    if (!gl_debug_init())
        LOG_WARN("OpenGL debug output initialization failed");
#endif

    glBindBuffer(GL_TEXTURE_3D, 69); GL_CHECK();

    LOG_INFO("OpenGL Version: %s",
        glGetString(GL_VERSION));

    LOG_INFO("Renderer: %s",
        glGetString(GL_RENDERER));

    LOG_INFO("Vendor: %s",
        glGetString(GL_VENDOR));

    return true;
}