#include "engine/render/backend/vertex_array.h"


#include <glad/glad.h>

void vertex_array_create(VertexArray *va)
{
	glGenVertexArrays(1, &va->id);
}

void vertex_array_bind(const VertexArray *va)
{
	glBindVertexArray(va->id);
}

void vertex_array_unbind(void)
{
	glBindVertexArray(0);
}

void vertex_array_add_attribute(unsigned int index, int length, int type, int normalize, int stride, void *offset)
{
	glVertexAttribPointer(index, length, type, normalize, stride, offset);
	glEnableVertexAttribArray(index);
}

void vertex_array_destroy(VertexArray *va)
{
	glDeleteVertexArrays(1, &va->id);
}
