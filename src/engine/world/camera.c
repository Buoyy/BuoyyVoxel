#include "engine/world/camera.h"

#include "engine/util/log.h"
#include <cglm/cglm.h>

void camera_create(Camera *camera, float width, float height)
{
    glm_vec3_copy((vec3){0, 0, 3}, camera->position);
    glm_vec3_copy((vec3){0, 0, -1},camera->front);

    camera->fov = 60.0f;
    camera->yaw = -90.0f; // Could take to be 0 too if the angle was with -z axis.
    camera->pitch = 0.0f;
    camera_update(camera);

    glm_perspective(glm_rad(camera->fov), (float)width/(float)height, 
        0.1f, 100.0f, camera->projection);
    LOG_INFO("Created camera at (%.2f, %.2f, %.2f)", 
        camera->position[0], camera->position[1], camera->position[2]);
}

void camera_update(Camera *camera)
{
    // Calculate the camera's front vector: (D vector in lookAt matrix)
    vec3 front = 
    {
        cos(glm_rad(camera->yaw))*cos(glm_rad(camera->pitch)),
        sin(glm_rad(camera->pitch)),
        sin(glm_rad(camera->yaw))*cos(glm_rad(camera->pitch))
    };
    glm_normalize_to(front, camera->front);

    // Calculate the camera's right vector: (R vector in lookAt matrix)
    vec3 world_up = {0, 1, 0};
    vec3 right; glm_cross(front, world_up, right);
    glm_normalize_to(right, camera->right);

    // Calculate the camera's up vector: (U vector in lookAt matrix)
    vec3 up; glm_cross(right, front, up);
    glm_normalize_to(up, camera->up);

    // Now, the center or target vector, that is position + front
    vec3 target; glm_vec3_add(camera->position, camera->front, target);
    glm_lookat(camera->position, target, camera->up, camera->view);
}