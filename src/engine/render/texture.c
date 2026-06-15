#include "engine/render/texture.h"

#include "engine/util/log.h"
#include <glad/glad.h>
#include <stb_image.h>
#include <stdarg.h>

void texture_create(Texture *texture, const unsigned int index)
{
    glGenTextures(1, &texture->id);
    texture->index = GL_TEXTURE0+index;
}

void texture_param(unsigned int param, unsigned int value)
{
    glTexParameteri(GL_TEXTURE_2D, param, value);
}

void texture_params(unsigned int param_count, ...)
{
    va_list args;
    va_start(args, param_count);

    for (unsigned int i = 0; i < param_count; ++i)
    {
        unsigned int param = va_arg(args, unsigned int);
        unsigned int value = va_arg(args, unsigned int);
        texture_param(param, value);
    }

    va_end(args);
}

void texture_activate(const Texture *texture)
{
    glActiveTexture(texture->index);
    texture_bind(texture);
}

void texture_bind(const Texture *texture)
{
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
}

void texture_create_default(Texture *texture, const unsigned int index, 
    const char *path, const int format)
{
    texture_create(texture, index);
    texture_activate(texture);
    texture_params(4, 
            GL_TEXTURE_WRAP_S, GL_REPEAT,
            GL_TEXTURE_WRAP_T, GL_REPEAT,
            GL_TEXTURE_MIN_FILTER, GL_NEAREST,
            GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    texture_load_image(path, format);
}