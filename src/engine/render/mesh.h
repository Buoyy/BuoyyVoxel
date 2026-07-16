#ifndef BV_ENGINE_RENDER_MESH_H
#define BV_ENGINE_RENDER_MESH_H

#include "engine/render/element_buffer.h"
#include "engine/render/vertex_array.h"
#include "engine/render/vertex_buffer.h"
#include "engine/render/vertex.h"

typedef struct Mesh
{
    VertexArray va;
    VertexBuffer vb;
    ElementBuffer eb;

    unsigned int element_count;
} Mesh;

void mesh_create(Mesh *mesh, 
    const Vertex *vertices,          size_t vertices_count,
    const unsigned int *indices,     size_t indices_count);
void mesh_draw(const Mesh *mesh);
void mesh_destroy(Mesh *mesh);

#endif
