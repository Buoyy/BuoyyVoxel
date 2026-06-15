#ifndef BV_ENGINE_WORLD_CAMERA_H
#define BV_ENGINE_WORLD_CAMERA_H

#include <cglm/types.h>

// Remember, +x axis -> right, +y -> up, +z -> out of the screen

typedef struct Camera Camera;
struct Camera
{
    float fov, yaw, pitch;

    vec3 position;
    vec3 front, right, up;

    mat4 projection, view;
};

void camera_create(Camera *camera, float width, float height);
void camera_update(Camera *camera);

void camera_rotate(Camera *camera, float dx, float dy);

#endif