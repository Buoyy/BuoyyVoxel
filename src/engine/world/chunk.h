#ifndef BV_ENGINE_WORLD_CHUNK_H
#define BV_ENGINE_WORLD_CHUNK_H

#define CHUNK_SIZE_X 16
#define CHUNK_SIZE_Y 16
#define CHUNK_SIZE_Z 16
#define CHUNK_VOLUME (CHUNK_SIZE_X * CHUNK_SIZE_Y * CHUNK_SIZE_Z)

#include "engine/world/block.h"
#include "engine/render/mesh.h"
#include <stdbool.h>

typedef struct Chunk
{
    Block blocks[CHUNK_VOLUME];
    Mesh mesh;
} Chunk;

bool chunk_create(Chunk *chunk);

void chunk_create_mesh(Chunk *chunk);

Block *chunk_get(Chunk *chunk, int x, int y, int z);

void chunk_set(Chunk *chunk, int x, int y, int z, Block block);

void chunk_destroy(Chunk *chunk);

#endif // BV_ENGINE_WORLD_CHUNK_H
