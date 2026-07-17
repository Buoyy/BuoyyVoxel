#ifndef BV_ENGINE_RENDER_BACKEND_TEXTURE_H
#define BV_ENGINE_RENDER_BACKEND_TEXTURE_H

#include <stdbool.h>

typedef struct Texture
{
    unsigned int id;
    unsigned int index;
} Texture;

void texture_create(Texture *texture);
void texture_set_param(unsigned int param, unsigned int value);
void texture_set_params(unsigned int param_count, ...);
void texture_bind(const Texture *texture);
void texture_load_image(const char *path, const int format);
void texture_unbind(void);
void texture_destroy(Texture *texture);

void texture_create_default(Texture *texture, const char *path, const int format);

// TODO: Manage multiple textures' indices by themselves.

#endif
