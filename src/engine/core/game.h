#ifndef BV_ENGINE_CORE_GAME_H
#define BV_ENGINE_CORE_GAME_H

#include <stdbool.h>

bool game_init(void);

bool game_running(void);
void game_update(void);
void game_render(void);

void game_shutdown(void);

#endif