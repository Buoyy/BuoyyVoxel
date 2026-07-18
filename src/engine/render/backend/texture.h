#ifndef BV_ENGINE_RENDER_BACKEND_TEXTURE_H
#define BV_ENGINE_RENDER_BACKEND_TEXTURE_H

#include <stdbool.h>

/**
 * Represents a GPU texture handle.
 */
typedef struct Texture
{
    unsigned int id;
    unsigned int index;
} Texture;

/**
 * Creates an empty texture.
 *
 * @param[in] texture - Pointer to the `Texture`
 */
void texture_create(Texture *texture);

/**
 * Sets a texture parameter as given.
 *
 * @param[in] param - The GL parameter to set
 * @param[in] value - The value for `param`
 */
void texture_set_param(unsigned int param, unsigned int value);

/**
 * Sets texture parameters as given. Must be in the format - param_name, param_value
 *
 * @param[in] param_count - Number of parameters to set 
 * @param[in] ... - Pairs of param_name, param_value (`unsigned int`s)
 */
void texture_set_params(unsigned int param_count, ...);

/**
 * Binds the given `Texture`.
 *
 * @param[in] texture - Pointer to the `Texture`
 */
void texture_bind(const Texture *texture);

/**
 * Loads the image at the given path for the currently bound `Texture`.
 *
 * @param[in] path - The path to the image to load 
 * @param[in] format - The format of the image (GL_RGB, GL_RGBA etc)
 */
void texture_load_image(const char *path, const int format);

/**
 * Unbinds the currently bound texture.
 */
void texture_unbind(void);

/**
 * Destroys the given `Texture`.
 *
 * @param[in] texture - Pointer to the `Texture`
 */
void texture_destroy(Texture *texture);

/**
 * Creates a `Texture`, uses default hints (see function implementation) and loads the image for it.
 *
 * @param[in] texture - Pointer to the `Texture`
 * @param[in] path - The path to the image to load 
 * @param[in] format - The format of the image (GL_RGB, GL_RGBA etc)
 */
void texture_create_default(Texture *texture, const char *path, const int format);

#endif // BV_ENGINE_RENDER_BACKEND_TEXTURE_H

