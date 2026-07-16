#ifndef BV_ENGINE_WORLD_BLOCK_REGISTRY_H
#define BV_ENGINE_WORLD_BLOCK_REGISTRY_H

#include "engine/render/primitives.h"
#include "engine/world/block.h"

typedef struct BlockDefinition
{
    unsigned int textures[FACE_COUNT];
} BlockDefinition;

extern const BlockDefinition block_registry[BLOCK_TYPE_COUNT];

#endif // BV_ENGINE_WORLD_BLOCK_REGISTRY_H
