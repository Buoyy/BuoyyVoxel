#ifndef BV_ENGINE_RENDER_SHADER_H
#define BV_ENGINE_RENDER_SHADER_H

#include <cglm/types.h>
#include <stdbool.h>

typedef struct Shader
{
    unsigned int id;  
} Shader;

bool shader_create(Shader *shader, const char *vert_src, const char *frag_src);
bool shader_create_from_file(Shader *shader, const char *vert_path, const char *frag_path);
void shader_bind(const Shader *shader);
void shader_destroy(Shader *shader);

void shader_set_int(const Shader *shader, const char *identifier, const int value);
void shader_set_float(const Shader *shader, const char *identifier, const float value);
void shader_set_vec3(const Shader *shader, const char *identifier, const vec3 value);
void shader_set_mat4(const Shader *shader, const char *identifier, const mat4 value);

#endif
