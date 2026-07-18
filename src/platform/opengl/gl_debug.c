#include "platform/opengl/gl_debug.h"

#include "engine/util/log.h"
#include "engine/util/path.h"

static const char *gl_error_string(GLenum error)
{
    switch (error)
    {
        case GL_INVALID_ENUM:
            return "GL_INVALID_ENUM";
        case GL_INVALID_VALUE:
            return "GL_INVALID_VALUE";
        case GL_INVALID_OPERATION:
            return "GL_INVALID_OPERATION";
        case GL_INVALID_FRAMEBUFFER_OPERATION:
            return "GL_INVALID_FRAMEBUFFER_OPERATION";
        case GL_OUT_OF_MEMORY:
            return "GL_OUT_OF_MEMORY";
        default:
            return "UNKNOWN";
    }
}

void gl_check_error(const char *file, int line)
{
    GLenum error;
    while ((error = glGetError()) != GL_NO_ERROR)
    {
        LOG_ERROR("[OpenGL] %s (%s:%d)", 
            gl_error_string(error), 
            path_filename(file),
            line);    
    }
}

static void APIENTRY gl_debug_callback(
    GLenum source,
    GLenum type,
    GLuint id,
    GLenum severity,
    GLsizei length,
    const GLchar *message,
    const void *user_param)
{
    (void)source;
    (void)type;
    (void)id;
    (void)severity;
    (void)length;
    (void)user_param;

    LOG_ERROR("[OpenGL] %s", message);
}

bool gl_debug_init(void)
{
    if (!GLAD_GL_ARB_debug_output)
    {
        LOG_WARN("GL_ARB_debug_output unavailable");
        return false;
    }

    glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS_ARB);

    glDebugMessageCallbackARB(gl_debug_callback, NULL);
    LOG_INFO("GL_ARB_debug_output initialization succeeded");

    return true;
}
