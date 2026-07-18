#ifndef BV_ENGINE_RENDER_BACKEND_VERTEX_BUFFER_H
#define BV_ENGINE_RENDER_BACKEND_VERTEX_BUFFER_H

#include <stdbool.h>
#include <stddef.h>

/**
 * Represents a vertex buffer object (VBO).
 */
typedef struct VertexBuffer
{
	unsigned int id;
} VertexBuffer;

/**
 * Creates a vertex buffer.
 *
 * @param[in] vb - Pointer to the `VertexBuffer`
 */
void vertex_buffer_create(VertexBuffer *vb);

/**
 * Binds the given vertex buffer.
 *
 * @param[in] va - Pointer to the `VertexArray`
 */
void vertex_buffer_bind(const VertexBuffer *vb);

/**
 * Sends the given data to the currently bound vertex buffer.
 *
 * @param[in] data - Pointer to the vertex data for the vertex buffer
 * @param[in] size - Size of the data to send from the start of `data`
 * @param[in] dynamic - If the data to be sent is going to change dynamically or not
 */
void vertex_buffer_data(const void *data, size_t size, bool dynamic);

/**
 * Unbinds the currently bound vertex buffer.
 */
void vertex_buffer_unbind(void);

/**
 * Destroys the given vertex buffer.
 *
 * @param[in] va - Pointer to the `VertexArray`
 */
void vertex_buffer_destroy(VertexBuffer *vb);

#endif // BV_ENGINE_RENDER_BACKEND_VERTEX_BUFFER_H

