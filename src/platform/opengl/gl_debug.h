#ifndef BV_PLATFORM_OPENGL_GL_DEBUG_H
#define BV_PLATFORM_OPENGL_GL_DEBUG_H

#include <glad/glad.h>

const char *gl_error_string(GLenum error);
void        gl_check_error(const char *file, int line);

#ifndef NDEBUG
#define GL_CHECK() gl_check_error(__FILE__, __LINE__)

#else
#define GL_CHECK()
#endif

#endif