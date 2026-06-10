#include "platform/opengl/gl_debug.h"

#include "engine/util/log.h"
#include "engine/util/path.h"

const char *gl_error_string(GLenum error)
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