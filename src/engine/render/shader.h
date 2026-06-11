#ifndef BV_ENGINE_RENDER_SHADER_H
#define BV_ENGINE_RENDER_SHADER_H

#include <stdbool.h>

typedef struct Shader Shader;
struct Shader
{
    unsigned int id;  
};

bool shader_create(Shader *shader, const char *vertSrc, const char *fragSrc);
void shader_bind(const Shader *shader);
void shader_destroy(Shader *shader);

#endif