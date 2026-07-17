#include "engine/world/chunk.h"

#include "engine/render/backend/element_buffer.h"
#include "engine/render/resources/mesh.h"
#include "engine/render/backend/primitives.h"
#include "engine/render/backend/vertex.h"
#include "engine/render/resources/texture_atlas.h"
#include "engine/util/dyn_array.h"
#include "engine/util/log.h"
#include "engine/world/block.h"
#include "engine/world/block_registry.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

static void vertex_adjust_uv(Vertex *vertex, BlockTexture texture, TextureAtlas *atlas)
{
    unsigned int texture_x = texture % atlas->cols;
    unsigned int texture_y = (atlas->rows - 1) - (texture / atlas->cols);

    float texture_width  = 1.0f / atlas->cols;
    float texture_height = 1.0f / atlas->rows;

    vertex->uv[0] = (vertex->uv[0] + texture_x) * texture_width;
    vertex->uv[1] = (vertex->uv[1] + texture_y) * texture_height;
}

static void mesh_emit_face(DynArray *vertices, DynArray *indices,
        int x, int y, int z,
        const Block *block, FaceDirection face, TextureAtlas *atlas)
{
    const FaceGeometry *geom = &block_faces[face];
    unsigned int vertex_index_offset = (unsigned int)vertices->length;

    const BlockDefinition *def = &block_registry[block->type];
    BlockTexture texture = def->textures[face];

    for (size_t i = 0; i < FACE_VERTICES_COUNT; ++i)
    {
        Vertex v = geom->vertices[i];
        v.position[0] += x;
        v.position[1] += y;
        v.position[2] += z;

        vertex_adjust_uv(&v, texture, atlas);

        da_append(vertices, &v);
    }

    for (size_t i = 0; i < FACE_INDICES_COUNT; ++i)
    {
        unsigned int face_index = quad_indices[i] + vertex_index_offset;
        da_append(indices, &face_index);
    }
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
    Block dirt  = { .type = BLOCK_DIRT  };
    Block grass = { .type = BLOCK_GRASS };
    Block stone = { .type = BLOCK_STONE };
    Block air   = { .type = BLOCK_AIR   };

    srand(time(NULL));

    for (int x = 0; x < CHUNK_SIZE_X; ++x) 
    {
        for (int y = 0; y < CHUNK_SIZE_Y; ++y)
        { 
            for (int z = 0; z < CHUNK_SIZE_Z; ++z) 
            {
                int grass_height =
                    (rand() % 4 +
                     rand() % 4 +
                     rand() % 4) / 3 + 6;
                if (y < 3)
                    chunk_set(chunk, x, y, z, stone);
                else if (y < 7)
                    chunk_set(chunk, x, y, z, dirt);
                else if (y < grass_height)
                    chunk_set(chunk, x, y, z, grass);
                else
                    chunk_set(chunk, x, y, z, air);
            }
        }
    }
    return true;
}

void chunk_build_mesh(Chunk *chunk, TextureAtlas *atlas)
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
                    mesh_emit_face(&vertices, &indices, x, y, z, block, FACE_FRONT, atlas);
                if (is_air(chunk, x, y, z - 1))
                    mesh_emit_face(&vertices, &indices, x, y, z, block, FACE_BACK, atlas);

                // Left / Right faces
                if (is_air(chunk, x - 1, y, z))
                    mesh_emit_face(&vertices, &indices, x, y, z, block, FACE_LEFT, atlas);
                if (is_air(chunk, x + 1, y, z))
                    mesh_emit_face(&vertices, &indices, x, y, z, block, FACE_RIGHT, atlas);

                // Top / bottom faces
                if (is_air(chunk, x, y + 1, z))
                    mesh_emit_face(&vertices, &indices, x, y, z, block, FACE_TOP, atlas);
                if (is_air(chunk, x, y - 1, z))
                    mesh_emit_face(&vertices, &indices, x, y, z, block, FACE_BOTTOM, atlas);
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
