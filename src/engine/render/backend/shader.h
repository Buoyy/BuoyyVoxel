#ifndef BV_ENGINE_RENDER_BACKEND_SHADER_H
#define BV_ENGINE_RENDER_BACKEND_SHADER_H

#include "engine/render/backend/texture.h"
#include <cglm/types.h>
#include <stdbool.h>

/**
 * Represents a shader program.
 */
typedef struct Shader
{
    unsigned int id;  
} Shader;

/**
 * Creates a shader from the given source code strings.
 *
 * @param[in] shader - Pointer to the `Shader`
 * @param vert_src - The vertex shader source code as a string.
 * @param frag_src - The fragment shader source code as a string.
 */
bool shader_create(Shader *shader, const char *vert_src, const char *frag_src);

/**
 * Creates a shader from the files at the given paths by reading them as source code strings.
 *
 * @param[in] shader - Pointer to the `Shader`
 * @param vert_path - Path to the file where the vertex shader source code lives
 * @param frag_path - Path to the file where the fragment shader source code lives
 */
bool shader_create_from_file(Shader *shader, const char *vert_path, const char *frag_path);

/**
 * Binds the given shader for rendering.
 *
 * @param[in] shader - Pointer to the `Shader`
 */
void shader_bind(const Shader *shader);

/**
 * Destroys the given shader.
 *
 * @param[in] shader - Pointer to the `Shader`
 */
void shader_destroy(Shader *shader);

/**
 * Sets a uniform integer variable in the shader.
 *
 * @param[in] shader - Pointer to the `Shader`
 * @param identifier - Name of the target uniform variable in the shader source code
 * @param value - The value for the target uniform variable
 */
void shader_set_int(const Shader *shader, const char *identifier, const int value);

/**
 * Sets a uniform floating point variable in the shader.
 *
 * @param[in] shader - Pointer to the `Shader`
 * @param identifier - Name of the target uniform variable in the shader source code
 * @param value - The value for the target uniform variable
 */
void shader_set_float(const Shader *shader, const char *identifier, const float value);

/**
 * Sets a uniform `vec3` variable in the shader.
 *
 * @param[in] shader - Pointer to the `Shader`
 * @param identifier - Name of the target uniform variable in the shader source code
 * @param value - The value for the target uniform variable
 */
void shader_set_vec3(const Shader *shader, const char *identifier, const vec3 value);

/**
 * Sets a uniform `mat4` variable in the shader.
 *
 * @param[in] shader - Pointer to the `Shader`
 * @param identifier - Name of the target uniform variable in the shader source code
 * @param value - The value for the target uniform variable
 */
void shader_set_mat4(const Shader *shader, const char *identifier, const mat4 value);

/**
 * Sets a uniform sampler in the shader from the specified `Texture`.
 *
 * @param[in] shader - Pointer to the `Shader`
 * @param[in] identifier - Name of the target uniform variable in the shader source code
 * @param[in] texture - Pointer to the `Texture` to use the sampler from
 */
void shader_set_sampler(const Shader *shader, const char *identifier, const Texture *texture);

#endif // BV_ENGINE_RENDER_BACKEND_SHADER_H

