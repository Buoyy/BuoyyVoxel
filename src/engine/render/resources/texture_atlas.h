#ifndef BV_ENGINE_RENDER_RESOURCES_TEXTURE_ATLAS_H
#define BV_ENGINE_RENDER_RESOURCES_TEXTURE_ATLAS_H

#include "engine/render/backend/shader.h"
#include "engine/render/backend/texture.h"

/**
 * Represents a texture atlas.
 */
typedef struct TextureAtlas 
{
    Texture texture;

    unsigned int rows;
    unsigned int cols;

    float tile_width;
    float tile_height;
} TextureAtlas;

/**
 * Creates a texture atlas from the given image and its rows and columns.
 *
 * @param[in] atlas - Pointer to the `TextureAtlas`
 * @param[in] filepath - Path to the image file
 * @param[in] rows - Number of rows in the texture atlas
 * @param[in] cols - Number of columns in the texture atlas
 */
void texture_atlas_create(TextureAtlas *atlas, const char *filepath, unsigned int rows, unsigned int cols);

/**
 * Binds the given texture atlas as the current GPU texture.
 *
 * @param[in] atlas - Pointer to the `TextureAtlas`
 */
void texture_atlas_bind(const TextureAtlas *atlas);

/**
 * Unbinds the given texture atlas' texture.
 */
void texture_atlas_unbind(void);

/**
 * Sets the texture atlas' texture's sampler as the value of the specified uniform sampler.
 *
 * @param[in] atlas - Pointer to the `TextureAtlas`
 * @param[out] shader - Pointer to the `Shader` with the uniform sampler
 * @param[out] sampler_identifier - Name of the uniform sampler in the shader source code.
 */
void texture_atlas_set_sampler(const TextureAtlas *atlas, const Shader *shader, const char *sampler_identifier);

/**
 * Destroys the given texture atlas.
 *
 * @param[in] atlas - Pointer to the `TextureAtlas`
 */
void texture_atlas_destroy(TextureAtlas *atlas);

#endif // BV_ENGINE_RENDER_RESOURCES_TEXTURE_ATLAS_H

