#include "engine/render/mesh.h"

#include "engine/render/element_buffer.h"
#include "engine/render/vertex.h"
#include "engine/render/vertex_array.h"
#include "engine/render/vertex_buffer.h"
#include "engine/util/assert.h"
#include <glad/glad.h>
#include <stddef.h>

void mesh_create(Mesh *mesh, 
    const Vertex *vertices,          size_t vertices_count,
    const unsigned int *indices,     size_t indices_count)
{
    ASSERT(vertices_count != 0);
    ASSERT(indices_count != 0);

    vertex_array_create(&mesh->va);
    vertex_array_bind(&mesh->va);

    vertex_buffer_create(&mesh->vb);
    vertex_buffer_bind(&mesh->vb);
    vertex_buffer_data(vertices, vertices_count*sizeof(Vertex), false);

    element_buffer_create(&mesh->eb);
    element_buffer_bind(&mesh->eb);
    element_buffer_data(indices, indices_count*sizeof(unsigned int), false);
    mesh->element_count = indices_count;

    vertex_array_add_attribute(0, 3, GL_FLOAT, GL_FALSE, 
        sizeof(Vertex), (void *)offsetof(Vertex, position));
}

void mesh_draw(const Mesh *mesh)
{
    glDrawElements(GL_TRIANGLES, mesh->element_count, GL_UNSIGNED_INT, 0);
}

void mesh_destroy(Mesh *mesh)
{
    element_buffer_destroy(&mesh->eb);
    vertex_buffer_destroy(&mesh->vb);
    vertex_array_destroy(&mesh->va);
    mesh->element_count = 0;
}