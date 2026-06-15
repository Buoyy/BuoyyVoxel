#include "engine/world/transform.h"

#include <cglm/cglm.h>

void transform_create(Transform *transform)
{
    glm_vec3_copy(GLM_VEC3_ZERO, transform->position);
    glm_vec3_copy(GLM_VEC3_ZERO, transform->rotation);
    glm_vec3_copy((vec3){1,1,1}, transform->scale);
    glm_mat4_copy(GLM_MAT4_IDENTITY, transform->model);
}

void transform_update(Transform *transform)
{
    glm_translate(transform->model, transform->position);

    glm_rotate(transform->model, glm_rad(transform->rotation[0]), (vec3){1,0,0});
    glm_rotate(transform->model, glm_rad(transform->rotation[1]), (vec3){0,1,0});
    glm_rotate(transform->model, glm_rad(transform->rotation[2]), (vec3){0,0,1});

    glm_scale(transform->model, transform->scale);
}