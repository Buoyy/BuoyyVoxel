#include "engine/world/chunk.h"

#include "engine/render/element_buffer.h"
#include "engine/render/mesh.h"
#include "engine/render/primitives.h"
#include "engine/render/vertex.h"
#include "engine/util/dyn_array.h"
#include "engine/util/log.h"
#include "engine/world/block.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
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

static void emit_block_face(DynArray *vertices, DynArray *indices, 
        int x, int y, int z, BlockFace face, size_t *index_offset)
{
    size_t local_vertex_offset = (size_t)face * FACE_VERTICES_COUNT;
    for (size_t i = 0; i < FACE_VERTICES_COUNT; ++i)
    {
        Vertex vertex = cube_vertices[local_vertex_offset + i];
        vertex.position[0] += x;
        vertex.position[1] += y;
        vertex.position[2] += z;
        da_append(vertices, &vertex); 
    }

    size_t local_index_offset = (size_t)face * FACE_INDICES_COUNT;
    for (size_t i = 0; i < FACE_INDICES_COUNT; ++i)
    {
        size_t index = cube_indices[local_index_offset + i] - local_vertex_offset + *index_offset; 
        da_append(indices, &index);
    }
    *index_offset += FACE_VERTICES_COUNT;
}

static bool is_air(const Chunk *chunk, int x, int y, int z)
{
    if (!chunk_in_bounds(x,y,z))
        return true;

    const Block *b = &chunk->blocks[chunk_index(x,y,z)];

    return b->type == BLOCK_AIR;
}

bool chunk_create(Chunk *chunk)
{
    // Temporarily, the chunk is full of dirt.
    Block dirt = { .type = BLOCK_DIRT };
    for (int x = 0; x < CHUNK_SIZE_X; ++x) 
    {
        for (int y = 0; y < CHUNK_SIZE_Y; ++y)
        { 
            for (int z = 0; z < CHUNK_SIZE_Z; ++z) 
            { 
                // if ((x > 0 && x < CHUNK_SIZE_X - 1) &&
                // (y > 0 && y < CHUNK_SIZE_Y - 1) &&
                // (z > 0 && z < CHUNK_SIZE_Z - 1)) continue;
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
    size_t index_offset = 0;

    // Loop through the blocks to get their positions
    for (int x = 0; x < CHUNK_SIZE_X; ++x)
    {
        for (int y = 0; y < CHUNK_SIZE_Y; ++y)
        {
            for (int z = 0; z < CHUNK_SIZE_Z; ++z)
            {
                 // Skip air blocks
                size_t index = chunk_index(x, y, z);
                Block *block = &chunk->blocks[index];
                if (block->type == BLOCK_AIR) continue;

                // Emit face if face is visible
                // Front / Back faces
                if (is_air(chunk, x, y, z + 1))
                    emit_block_face(&vertices, &indices, x, y, z, BLOCK_FACE_FRONT, &index_offset);
                if (is_air(chunk, x, y, z - 1))
                    emit_block_face(&vertices, &indices, x, y, z, BLOCK_FACE_BACK, &index_offset);

                // Left / Right faces
                if (is_air(chunk, x - 1, y, z))
                    emit_block_face(&vertices, &indices, x, y, z, BLOCK_FACE_LEFT, &index_offset);
                if (is_air(chunk, x + 1, y, z))
                    emit_block_face(&vertices, &indices, x, y, z, BLOCK_FACE_RIGHT, &index_offset);

                // Top / bottom faces
                if (is_air(chunk, x, y + 1, z))
                    emit_block_face(&vertices, &indices, x, y, z, BLOCK_FACE_TOP, &index_offset);
                if (is_air(chunk, x, y - 1, z))
                    emit_block_face(&vertices, &indices, x, y, z, BLOCK_FACE_BOTTOM, &index_offset);
            }
        }
    }

    // Send the acquired vertex and index data to the mesh
    mesh_create(&chunk->mesh, vertices.data, vertices.length, indices.data, indices.length);
    LOG_INFO("Vertices: %zu", vertices.length);
    LOG_INFO("Indices:  %zu", indices.length);
    da_deinit(&vertices);
    da_deinit(&indices);
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
    mesh_destroy(&chunk->mesh);
}
