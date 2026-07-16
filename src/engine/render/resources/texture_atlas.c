#include "engine/render/resources/texture_atlas.h"

#include "engine/render/backend/texture.h"
#include <glad/glad.h>

void texture_atlas_create(TextureAtlas *atlas, const char *filepath, unsigned int rows, unsigned int cols)
{
    texture_create_default(&atlas->texture, 0, filepath, GL_RGBA); // Assuming no other textures have been loaded yet
    atlas->rows = rows;
    atlas->cols = cols;
}

void texture_atlas_bind(const TextureAtlas *atlas)
{
    texture_bind(&atlas->texture);
}

void texture_atlas_unbind(void)
{
    texture_unbind();
}

void texture_atlas_set_sampler(const TextureAtlas *atlas, const Shader *shader, const char *sampler_identifier)
{
    shader_set_int(shader, sampler_identifier, atlas->texture.index);
}

void texture_atlas_destroy(TextureAtlas *atlas)
{
    texture_destroy(&atlas->texture);
    atlas->rows = 0;
    atlas->cols = 0;
}
