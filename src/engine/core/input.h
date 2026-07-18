#ifndef BV_ENGINE_CORE_INPUT_H
#define BV_ENGINE_CORE_INPUT_H

#include <stdbool.h>

/**
 * If true, upward movement of mouse is reported to be a downward movement.
 * If false, no changes to raw input.
 * Defaults to false.
 */
extern bool mouse_inverted;

/**
 * Represents how sensitive the mouse is.
 * Defaults to 0.1.
 */
extern float mouse_sens;

/**
 * Initializes the `input` module and disables the cursor.
 */
void input_init(void);

/**
 * Updates the mouse related variables.
 * Ideally should be called every frame.
 */
void input_update(void);

/**
 * Returns true if the given key is pressed down and false otherwise.
 */
bool input_key_down(int key);

/**
 * Returns true if the given mouse button is pressed down and false otherwise.
 */
bool input_mouse_down(int button);

/**
 * Returns the mouse delta on the horizontal axis since last frame.
 */
float input_mouse_dx(void);

/**
 * Returns the mouse delta on the vertical axis since last frame.
 */
float input_mouse_dy(void);

#endif // BV_ENGINE_CORE_INPUT_H

