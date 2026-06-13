#ifndef BV_ENGINE_RENDER_MESH_H
#define BV_ENGINE_RENDER_MESH_H

#include "engine/render/element_buffer.h"
#include "engine/render/vertex_array.h"
#include "engine/render/vertex_buffer.h"

typedef struct Mesh Mesh;
struct Mesh
{
    VertexArray va;
    VertexBuffer vb;
    ElementBuffer eb;

    unsigned int element_count;
};

void mesh_create(Mesh *mesh, 
    const void *vertices,          size_t size_vertices,
    const unsigned int  *indices,  size_t size_indices);
void mesh_draw(const Mesh *mesh);
void mesh_destroy(Mesh *mesh);

#endif