#ifndef BV_ENGINE_WORLD_CHUNK_H
#define BV_ENGINE_WORLD_CHUNK_H

#include "engine/render/resources/texture_atlas.h"
#define CHUNK_SIZE_X 16
#define CHUNK_SIZE_Y 16
#define CHUNK_SIZE_Z 16
#define CHUNK_VOLUME (CHUNK_SIZE_X * CHUNK_SIZE_Y * CHUNK_SIZE_Z)

#include "engine/world/block.h"
#include "engine/render/resources/mesh.h"
#include <stdbool.h>

/**
 * Represents a chunk.
 */
typedef struct Chunk
{
    Block blocks[CHUNK_VOLUME];
    Mesh mesh;
} Chunk;

/**
 * Creates a chunk. Currently makes a random grass top on the chunk.
 *
 * @param[in] chunk - Pointer to the `Chunk`
 * 
 * @return True if the chunk was successfully created.
 */
bool chunk_create(Chunk *chunk);

/**
 * Builds the mesh for this chunk according to the given texture atlas.
 * Call after making any changes to the mesh.
 *
 * @param[in] chunk - Pointer to the `Chunk`
 * @param[in] atlas - Pointer to the `TextureAtlas`
 */
void chunk_build_mesh(Chunk *chunk, TextureAtlas *atlas);

/**
 * Returns a pointer to the block at the specified chunk space coordinates.
 *
 * @param[in] chunk - Pointer to the `Chunk`
 * @param[in] x - x coordinate of the block in chunk space
 * @param[in] y - y coordinate of the block in chunk space
 * @param[in] z - z coordinate of the block in chunk space
 * 
 * @return Pointer to the specified `Block` if it exists and `NULL` otherwise.
 */
Block *chunk_get(Chunk *chunk, int x, int y, int z);

/**
 * Sets the block at the specified chunk space coordinates to the given block.
 *
 * @param[in] chunk - Pointer to the `Chunk`
 * @param[in] x - x coordinate of the block in chunk space
 * @param[in] y - y coordinate of the block in chunk space
 * @param[in] z - z coordinate of the block in chunk space
 * @param[in] block - The `Block` to set to 
 */
void chunk_set(Chunk *chunk, int x, int y, int z, Block block);

/**
 * Destroys the chunk. Currently only destroys the mesh.
 *
 * @param[in] chunk - Pointer to the `Chunk`
 */
void chunk_destroy(Chunk *chunk);

#endif // BV_ENGINE_WORLD_CHUNK_H

