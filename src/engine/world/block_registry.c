#include "engine/world/block_registry.h"

#include "engine/world/block.h"

const BlockDefinition block_registry[] =
{
    [BLOCK_AIR] =
    {
        {
            BLOCK_TEXTURE_AIR,
            BLOCK_TEXTURE_AIR,
            BLOCK_TEXTURE_AIR,
            BLOCK_TEXTURE_AIR,
            BLOCK_TEXTURE_AIR,
            BLOCK_TEXTURE_AIR
        }
    },
    [BLOCK_DIRT] =
    {
        {
            BLOCK_TEXTURE_DIRT,
            BLOCK_TEXTURE_DIRT,
            BLOCK_TEXTURE_DIRT,
            BLOCK_TEXTURE_DIRT,
            BLOCK_TEXTURE_DIRT,
            BLOCK_TEXTURE_DIRT
        }
    },
    [BLOCK_GRASS] =
    {
        {
            BLOCK_TEXTURE_GRASS_SIDE,
            BLOCK_TEXTURE_GRASS_SIDE,
            BLOCK_TEXTURE_GRASS_SIDE,
            BLOCK_TEXTURE_GRASS_SIDE,
            BLOCK_TEXTURE_GRASS_TOP,
            BLOCK_TEXTURE_DIRT
        }
    },
    [BLOCK_STONE] =
    {
        {
            BLOCK_TEXTURE_STONE,
            BLOCK_TEXTURE_STONE,
            BLOCK_TEXTURE_STONE,
            BLOCK_TEXTURE_STONE,
            BLOCK_TEXTURE_STONE,
            BLOCK_TEXTURE_STONE
        }
    },
};
