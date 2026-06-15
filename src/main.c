#include "engine/core/game.h"

int main()
{
    if (!game_init())
        return 1;
    while (game_running())
    {
        game_update();
        game_render();
    }
    game_shutdown();
}