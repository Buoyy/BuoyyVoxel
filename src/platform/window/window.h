#ifndef BV_PLATFORM_WINDOW_WINDOW_H
#define BV_PLATFORM_WINDOW_WINDOW_H

#include <GLFW/glfw3.h>
#include <stdbool.h>

extern GLFWwindow *window;

bool window_create(int width, int height, const char *title);

bool window_should_close(void);
void window_poll_events(void);
void window_swap_buffers(void);

void window_destroy(void);

#endif