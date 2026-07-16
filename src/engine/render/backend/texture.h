#ifndef BV_ENGINE_RENDER_BACKEND_TEXTURE_H
#define BV_ENGINE_RENDER_BACKEND_TEXTURE_H

#include <stdbool.h>

typedef struct Texture
{
    unsigned int id;
    unsigned int index;
} Texture;

void texture_create(Texture *texture, const unsigned int index);
void texture_param(unsigned int param, unsigned int value);
void texture_params(unsigned int param_count, ...);
void texture_activate(const Texture *texture);
void texture_bind(const Texture *texture);
void texture_load_image(const char *path, const int format);
void texture_unbind(void);
void texture_destroy(Texture *texture);

void texture_create_default(Texture *texture, const unsigned int index, 
    const char *path, const int format);

#endif
