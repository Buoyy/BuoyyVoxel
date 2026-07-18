#ifndef BV_ENGINE_RENDER_BACKEND_ELEMENT_BUFFER_H
#define BV_ENGINE_RENDER_BACKEND_ELEMENT_BUFFER_H

#include <stdbool.h>
#include <stddef.h>

/**
 * Represents an element/index buffer object.
 */
typedef struct ElementBuffer
{
	unsigned int id;
} ElementBuffer;

/**
 * Creates an element buffer.
 *
 * @param[in] eb - Pointer to the `ElementBuffer`
 */
void element_buffer_create(ElementBuffer *eb);

/**
 * Binds the given element buffer.
 *
 * @param[in] eb - Pointer to the `ElementBuffer`
 */
void element_buffer_bind(const ElementBuffer *eb);

/**
 * Unbinds the currently bound element buffer.
 */
void element_buffer_unbind(void);

/**
 * Sends the given data to the currently bound element buffer.
 *
 * @param[in] data - Pointer to the index data for the element buffer
 * @param[in] size - Size of the data to send from the start of `data`
 * @param[in] dynamic - If the data to be sent is going to change dynamically or not
 */
void element_buffer_data(const void *data, size_t size, bool dynamic);

/**
 * Destroys the given element buffer.
 *
 * @param[in] eb - Pointer to the `ElementBuffer`
 */
void element_buffer_destroy(ElementBuffer *eb);

#endif // BV_ENGINE_RENDER_BACKEND_ELEMENT_BUFFER_H

