#include "engine/render/mesh.h"

#include "engine/render/element_buffer.h"
#include "engine/render/vertex_array.h"
#include "engine/render/vertex_buffer.h"
#include "engine/util/assert.h"
#include <glad/glad.h>

void mesh_create(Mesh *mesh, 
    const void *vertices,          size_t size_vertices,
    const unsigned int  *indices,  size_t size_indices)
{
    ASSERT(size_vertices != 0);
    ASSERT(size_indices != 0);

    vertex_array_create(&mesh->va);
    vertex_array_bind(&mesh->va);

    vertex_buffer_create(&mesh->vb);
    vertex_buffer_bind(&mesh->vb);
    vertex_buffer_data(vertices, size_vertices, false);

    element_buffer_create(&mesh->eb);
    element_buffer_bind(&mesh->eb);
    element_buffer_data(indices, size_indices, false);
    mesh->element_count = size_indices/sizeof(unsigned int);

    vertex_array_add_attribute(0, 2, GL_FLOAT, GL_FALSE, 2*sizeof(float), 0);
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