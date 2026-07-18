#ifndef BV_PLATFORM_OPENGL_GL_CONTEXT_H
#define BV_PLATFORM_OPENGL_GL_CONTEXT_H

#include <stdbool.h>

/**
 * Loads the function pointers for OpenGL functions and initializes the debug context, if needed.
 * Returns true if successful and false otherwise.
 */
bool gl_context_init(void);

#endif
