#ifndef BV_PLATFORM_OPENGL_GL_DEBUG_H
#define BV_PLATFORM_OPENGL_GL_DEBUG_H

#include <glad/glad.h>

const char *gl_error_string(GLenum error);
void        gl_check_error(const char *file, int line);

#ifndef NDEBUG
#define GL(EXPR)                            \
    do {                                    \
        gl_check_error(__FILE__, __LINE__); \
        EXPR;                               \
        gl_check_error(__FILE__, __LINE__); \
    } while (0)

#else
#define GL(EXPR) \
    do {         \
        EXPR;    \
    } while (0)
#endif

#endif