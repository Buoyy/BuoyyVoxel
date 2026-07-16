#ifndef BV_ENGINE_RENDER_VERTEX_BUFFER_H
#define BV_ENGINE_RENDER_VERTEX_BUFFER_H

#include <stdbool.h>
#include <stddef.h>

typedef struct VertexBuffer
{
	unsigned int id;
} VertexBuffer;

void vertex_buffer_create(VertexBuffer *vb);
void vertex_buffer_bind(const VertexBuffer *vb);
void vertex_buffer_data(const void *data, size_t size, bool dynamic);
void vertex_buffer_unbind(void);
void vertex_buffer_destroy(VertexBuffer *vb);

#endif
