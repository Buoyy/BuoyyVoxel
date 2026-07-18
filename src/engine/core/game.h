#ifndef BV_ENGINE_CORE_GAME_H
#define BV_ENGINE_CORE_GAME_H

#include <stdbool.h>

/**
 * Initializes the game's internal systems like time, input, rendering and world.
 */
bool game_init(void);

/**
 * Tells if the game is requested to shut down.
 *
 * @return True if the game is not requested to shut down and false otherwise.
 */
bool game_running(void);

/**
 * Updates the game's internal systems and the game's world.
 */
void game_update(void);

/**
 * Renders the game world to the screen.
 */
void game_render(void);

/**
 * Requests the game window to close and cleans up all internal systems.
 */
void game_shutdown(void);

#endif // BV_ENGINE_CORE_GAME_H

