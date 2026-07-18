#ifndef BV_ENGINE_WORLD_BLOCK_REGISTRY_H
#define BV_ENGINE_WORLD_BLOCK_REGISTRY_H

#include "engine/render/backend/primitives.h"
#include "engine/world/block.h"

/**
 * Represents all textures in a block by face.
 */
typedef struct BlockDefinition
{
    unsigned int textures[FACE_COUNT];
} BlockDefinition;

/**
 * Represents all textures currently available in terrain atlas.
 */
typedef enum BlockTexture
{
    BLOCK_TEXTURE_DIRT,
    BLOCK_TEXTURE_STONE,
    BLOCK_TEXTURE_GRASS_SIDE,
    BLOCK_TEXTURE_GRASS_TOP,

    BLOCK_TEXTURE_AIR,

    BLOCK_TEXTURE_COUNT
} BlockTexture;

/** The main block registry. */
extern const BlockDefinition block_registry[BLOCK_TYPE_COUNT];

#endif // BV_ENGINE_WORLD_BLOCK_REGISTRY_H

