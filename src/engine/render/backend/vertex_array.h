#ifndef BV_ENGINE_RENDER_BACKEND_VERTEX_ARRAY_H
#define BV_ENGINE_RENDER_BACKEND_VERTEX_ARRAY_H

typedef struct VertexArray
{
	unsigned int id;
} VertexArray;

void vertex_array_create(VertexArray *va);
void vertex_array_bind(const VertexArray *va);
void vertex_array_unbind(void);
void vertex_array_add_attribute(unsigned int index, int length, 
	int type, int normalize, int stride, void *offset);
void vertex_array_destroy(VertexArray *va);

#endif
