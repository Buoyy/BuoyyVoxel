#ifndef BV_PLATFORM_OPENGL_GL_DEBUG_H
#define BV_PLATFORM_OPENGL_GL_DEBUG_H

#include <glad/glad.h>
#include <stdbool.h>

/**
 * Logs all errors accumulated in the GL context.
 *
 * @p file The source code file where the error occured
 * @p line The line in the source code where the error occured
 */
void gl_check_error(const char *file, int line);

/**
 * Sets up the GL_ARB_debug_output extension.
 * Returns true if successful and false otherwise.
 */
bool gl_debug_init(void);

#ifndef NDEBUG
#define GL_CHECK() gl_check_error(__FILE__, __LINE__)

#else
#define GL_CHECK()
#endif

#endif
