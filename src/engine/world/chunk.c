#include "engine/world/chunk.h"

#include "engine/render/mesh.h"
#include "engine/render/primitives.h"
#include "engine/render/vertex.h"
#include "engine/util/common.h"
#include "engine/util/dyn_array.h"
#include "engine/util/log.h"
#include "engine/world/block.h"
#include <stdbool.h>
#include <stddef.h>
#include <string.h>

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
    // Temporarily, the chunk is just a shell of dirt.
    Block dirt = { .type = BLOCK_DIRT };
    for (int x = 0; x < CHUNK_SIZE_X; ++x) 
    {
        for (int y = 0; y < CHUNK_SIZE_Y; ++y)
        {
            for (int z = 0; z < CHUNK_SIZE_Z; ++z)
            {
                if ((x > 1 && x < CHUNK_SIZE_X - 1)
                    && (y > 1 && y < CHUNK_SIZE_Y - 1)
                    && (z > 1 && z < CHUNK_SIZE_Z - 1)) continue;
                chunk_set(chunk, x, y, z, dirt);
            }
        }
    }
    return true;
}

void chunk_create_mesh(Chunk *chunk)
{
    // Create dynamic arrays for vertices and indices
    DynArray vertices, indices;
    if (!da_init(&vertices, sizeof(Vertex)))
    {
        LOG_ERROR("Couldn't initialise dynamic array of Vertices");
        return;
    }
    if (!da_init(&indices, sizeof(unsigned int)))
    {
        LOG_ERROR("Couldn't initialise dynamic array of Indices (unsigned ints)");
        da_deinit(&vertices);
        return;
    }

    // Used for keeping tracking of the vertex indices which are incrementing as we want a single draw call
    unsigned int index_offset = 0;

    // Loop through the blocks to get their positions
    for (int x = 0; x < CHUNK_SIZE_X; ++x)
    {
        for (int y = 0; y < CHUNK_SIZE_Y; ++y)
        {
            for (int z = 0; z < CHUNK_SIZE_Z; ++z)
            {
                // Skip air blocks
                Block *block = &chunk->blocks[chunk_index(x, y, z)];
                if (block == NULL)
                {
                    LOG_ERROR("Null block found! Exiting mesh generation...");
                    da_deinit(&vertices);
                    da_deinit(&indices);
                    return;
                };
                if (block->type == BLOCK_AIR) continue;

                // Add the vertex to the dyn_array, offset them by their world positions
                for (size_t i = 0; i < ARR_LEN(cube_vertices); ++i)
                {
                    Vertex v = cube_vertices[i];
                    v.position[0] += x;
                    v.position[1] += y;
                    v.position[2] += z;

                    da_append(&vertices, &v);
                }

                // Add the index to the dyn_array, offset them by their world positions
                for (size_t i = 0; i < ARR_LEN(cube_indices); ++i) 
                {
                    unsigned int index = index_offset + cube_indices[i];
                    da_append(&indices, &index);
                }
                // Make sure that the offset also increases for the next loop iteration
                index_offset += ARR_LEN(cube_vertices);
            }
        }
    }

    // Send the acquired vertex and index data to the mesh
    mesh_create(&chunk->mesh, vertices.data, vertices.length, indices.data, indices.length);
    // da_deinit(&vertices);
    // da_deinit(&indices);
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

void chunk_destroy(Chunk *chunk)
{
    memset(chunk->blocks, 0, sizeof(chunk->blocks));
    mesh_destroy(&chunk->mesh);
}
