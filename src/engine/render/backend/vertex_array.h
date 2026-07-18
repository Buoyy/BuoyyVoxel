#ifndef BV_ENGINE_RENDER_BACKEND_VERTEX_ARRAY_H
#define BV_ENGINE_RENDER_BACKEND_VERTEX_ARRAY_H

/**
 * Represents a vertex array object (VAO).
 */
typedef struct VertexArray
{
	unsigned int id;
} VertexArray;

/**
 * Creates a vertex array.
 *
 * @param[in] va - Pointer to the `VertexArray`
 */
void vertex_array_create(VertexArray *va);

/**
 * Binds the given vertex array.
 *
 * @param[in] va - Pointer to the `VertexArray`
 */
void vertex_array_bind(const VertexArray *va);

/**
 * Unbinds the currently bound vertex array.
 */
void vertex_array_unbind(void);

/**
 * Adds an attribute to the currently bound vertex array.
 *
 * @param[in] index - Index of the attribute
 * @param[in] length - Number of elements in this attribute
 * @param[in] type - GL type of the elements of this attribute
 * @param[in] normalize - Whether or not to normalize the elements of this attribute
 * @param[in] stride - The stride of this attribute in bytes
 * @param[in] offset - Offset pointer of this attribute in the vertex array
 */
void vertex_array_add_attribute(unsigned int index, int length, 
	int type, int normalize, int stride, void *offset);

/**
 * Destroys the given vertex array.
 *
 * @param[in] va - Pointer to the `VertexArray`
 */
void vertex_array_destroy(VertexArray *va);

#endif // BV_ENGINE_RENDER_BACKEND_VERTEX_ARRAY_H

