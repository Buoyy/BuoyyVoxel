#include "engine/render/vertex_buffer.h"

#include <glad/glad.h>

void vertex_buffer_create(VertexBuffer *vb, const void *data, size_t size, bool dynamic)
{
	glGenBuffers(1, &vb->id);
	vertex_buffer_bind(vb);

	glBufferData(GL_ARRAY_BUFFER, size, data, dynamic ? GL_STATIC_DRAW : GL_DYNAMIC_DRAW);
}

void vertex_buffer_bind(const VertexBuffer *vb)
{
	glBindBuffer(GL_ARRAY_BUFFER, vb->id);
}

void vertex_buffer_unbind(void)
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void vertex_buffer_destroy(VertexBuffer *vb)
{
	glDeleteBuffers(1, &vb->id);
}