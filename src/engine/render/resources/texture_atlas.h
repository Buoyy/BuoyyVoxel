#ifndef BV_ENGINE_RENDER_RESOURCES_TEXTURE_ATLAS_H
#define BV_ENGINE_RENDER_RESOURCES_TEXTURE_ATLAS_H

#include "engine/render/backend/shader.h"
#include "engine/render/backend/texture.h"

typedef struct TextureAtlas 
{
    Texture texture;

    unsigned int rows;
    unsigned int cols;
} TextureAtlas;

void texture_atlas_create(TextureAtlas *atlas, const char *filepath, unsigned int rows, unsigned int cols);
void texture_atlas_bind(const TextureAtlas *atlas);
void texture_atlas_unbind(void);
void texture_atlas_set_sampler(const TextureAtlas *atlas, const Shader *shader, const char *sampler_identifier);
void texture_atlas_destroy(TextureAtlas *atlas);

#endif // BV_ENGINE_RENDER_RESOURCES_TEXTURE_ATLAS_H
