#ifndef BV_ENGINE_RENDER_SHADER_H
#define BV_ENGINE_RENDER_SHADER_H

#include <stdbool.h>

typedef struct Shader Shader;
struct Shader
{
    unsigned int id;  
};

bool shader_create(Shader *shader, const char *vert_src, const char *frag_src);
bool shader_create_from_file(Shader *shader, const char *vert_path, const char *frag_path);
void shader_bind(const Shader *shader);
void shader_destroy(Shader *shader);

#endif