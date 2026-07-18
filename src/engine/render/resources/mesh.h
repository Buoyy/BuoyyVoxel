#ifndef BV_ENGINE_RENDER_RESOURCES_MESH_H
#define BV_ENGINE_RENDER_RESOURCES_MESH_H

#include "engine/render/backend/element_buffer.h"
#include "engine/render/backend/vertex_array.h"
#include "engine/render/backend/vertex_buffer.h"
#include "engine/render/backend/vertex.h"

/**
 * Represents a basic drawable mesh.
 */
typedef struct Mesh
{
    VertexArray va;
    VertexBuffer vb;
    ElementBuffer eb;

    unsigned int element_count;
} Mesh;

/**
 * Creates a mesh with the specified vertex and element data.
 * 
 * @param[in] mesh - Pointer to the `Mesh`
 * @param[in] vertices - Pointer to the vertex data
 * @param[in] vertices_count - Number of vertices
 * @param[in] indices - Pointer to the index/element data
 * @param[in] indices_count - Number of indices/elements
 */
void mesh_create(Mesh *mesh, 
    const Vertex *vertices,          size_t vertices_count,
    const unsigned int *indices,     size_t indices_count);

/**
 * Draws the given mesh.
 *
 * @param[in] mesh - Pointer to the `Mesh`
 */
void mesh_draw(const Mesh *mesh);

/**
 * Destroys the given mesh.
 *
 * @param[in] mesh - Pointer to the `Mesh`
 */
void mesh_destroy(Mesh *mesh);

#endif // BV_ENGINE_RENDER_RESOURCES_MESH_H

