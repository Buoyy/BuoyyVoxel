#ifndef BV_ENGINE_WORLD_TRANSFORM_H
#define BV_ENGINE_WORLD_TRANSFORM_H

#include <cglm/types.h>

typedef struct Transform Transform;
struct Transform
{
    vec3 position;
    vec3 rotation; // Store as degrees
    vec3 scale;

    mat4 model;
};

void transform_create(Transform *transform);
void transform_update(Transform *transform);

#endif