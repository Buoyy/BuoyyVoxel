#ifndef BV_PLATFORM_WINDOW_WINDOW_H
#define BV_PLATFORM_WINDOW_WINDOW_H

#include <GLFW/glfw3.h>
#include <stdbool.h>

extern GLFWwindow *window;

/** 
 * Initializes GLFW, creates and makes the window the OpenGL context.
 * Returns true if successful and false otherwise.
 *
 * @p width  Width of the window
 * @p height Height of the window
 * @p title  Title of the window
 */
bool window_create(int width, int height, const char *title);

/**
 * Returns true if the window has been requested to close, false otherwise.
 */
bool window_should_close(void);

/**
 * Polls all kinds events (key press, mouse movement etc) for the window.
 */
void window_poll_events(void);

/**
 * Swaps the window's framebuffers, displays what has been drawn and clears the background.
 */
void window_swap_buffers(void);

/**
 * Destroys the window and terminates GLFW.
 */
void window_destroy(void);

#endif
