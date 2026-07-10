#include "engine/world/chunk.h"

#include "engine/util/log.h"
#include "engine/world/block.h"
#include <stddef.h>

static inline size_t chunk_index(int x, int y, int z)
{
    return x + (z * CHUNK_SIZE_X) + (y * CHUNK_SIZE_X * CHUNK_SIZE_Z); 
}

static inline bool chunk_in_bounds(int x, int y, int z)
{
    return (x >= 0 && x < CHUNK_SIZE_X) &&
           (y >= 0 && y < CHUNK_SIZE_Y) &&
           (z >= 0 && z < CHUNK_SIZE_Z);
}

bool chunk_create(Chunk *chunk)
{
    for (size_t i = 0; i < CHUNK_VOLUME; ++i)
    {
        chunk->blocks[i] = (Block) { .type = BLOCK_AIR };
    }
    return true;
}

Block *chunk_get(Chunk *chunk, int x, int y, int z)
{
    if (!chunk_in_bounds(x, y, z)) 
    {
        LOG_ERROR("Chunk-space coordinates (%d, %d, %d) are out of bounds.", x, y, z);
        return NULL;
    }

    return &chunk->blocks[chunk_index(x, y, z)];
}

void chunk_set(Chunk *chunk, int x, int y, int z, Block block)
{
    if (!chunk_in_bounds(x, y, z))
    {
        LOG_ERROR("Chunk-space coordinates (%d, %d, %d) are out of bounds.", x, y, z);
        return;
    }

    chunk->blocks[chunk_index(x, y, z)] = block;
}