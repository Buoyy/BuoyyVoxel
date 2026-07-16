#include "engine/render/backend/element_buffer.h"

#include <glad/glad.h>

void element_buffer_create(ElementBuffer *eb)
{
	glGenBuffers(1, &eb->id);
}

void element_buffer_bind(const ElementBuffer *eb)
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eb->id);
}

void element_buffer_unbind(void)
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void element_buffer_data(const void *data, size_t size, bool dynamic)
{
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, 
        dynamic ? GL_DYNAMIC_DRAW: GL_STATIC_DRAW);
}

void element_buffer_destroy(ElementBuffer *eb)
{
    glDeleteBuffers(1, &eb->id);
}
