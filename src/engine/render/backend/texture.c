#include "engine/render/backend/texture.h"

#include "engine/util/log.h"
#include <glad/glad.h>
#include <stb_image.h>
#include <stdarg.h>

static unsigned int next_texture_index = 0;

void texture_create(Texture *texture)
{
    glGenTextures(1, &texture->id);
    texture->index = next_texture_index++;
}

void texture_set_param(unsigned int param, unsigned int value)
{
    glTexParameteri(GL_TEXTURE_2D, param, value);
}

void texture_set_params(unsigned int param_count, ...)
{
    va_list args;
    va_start(args, param_count);

    for (unsigned int i = 0; i < param_count; ++i)
    {
        unsigned int param = va_arg(args, unsigned int);
        unsigned int value = va_arg(args, unsigned int);
        texture_set_param(param, value);
    }

    va_end(args);
}

void texture_bind(const Texture *texture)
{
    glActiveTexture(GL_TEXTURE0 + texture->index);
    glBindTexture(GL_TEXTURE_2D, texture->id);  
}

void texture_load_image(const char *path, const int format)
{
    int x, y, channels;
    void *pixels = stbi_load(path, &x, &y, &channels, 0);
    if (!pixels)
    {
        LOG_ERROR("Couldn't load image at '%s'", path);
        return;
    }
    glTexImage2D(GL_TEXTURE_2D, 0, format, x, y, 0, format, GL_UNSIGNED_BYTE, pixels);
    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free(pixels);
}

void texture_unbind(void)
{
    glBindTexture(GL_TEXTURE_2D, 0);
}

void texture_destroy(Texture *texture)
{
    glDeleteTextures(1, &texture->id);
    texture->id = 0;
    texture->index = 0;
}

void texture_create_default(Texture *texture, const char *path, const int format)
{
    texture_create(texture);
    texture_bind(texture);
    texture_set_params(4, 
            GL_TEXTURE_WRAP_S, GL_REPEAT,
            GL_TEXTURE_WRAP_T, GL_REPEAT,
            GL_TEXTURE_MIN_FILTER, GL_NEAREST,
            GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    texture_load_image(path, format);
}

