#ifndef BV_ENGINE_CORE_INPUT_H
#define BV_ENGINE_CORE_INPUT_H

#include <stdbool.h>

extern bool mouse_inverted;
extern float mouse_sens;

void input_init(void);
void input_update(void);

bool input_key_down(int key);
bool input_mouse_down(int button);

float input_mouse_dx(void);
float input_mouse_dy(void);

#endif