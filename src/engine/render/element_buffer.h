#ifndef BV_ENGINE_RENDER_ELEMENT_BUFFER_H
#define BV_ENGINE_RENDER_ELEMENT_BUFFER_H

#include <stdbool.h>
#include <stddef.h>

typedef struct ElementBuffer ElementBuffer;
struct ElementBuffer
{
	unsigned int id;
};

void element_buffer_create(ElementBuffer *eb);
void element_buffer_bind(const ElementBuffer *eb);
void element_buffer_unbind(void);
void element_buffer_data(const void *data, size_t size, bool dynamic);
void element_buffer_destroy(ElementBuffer *eb);

#endif