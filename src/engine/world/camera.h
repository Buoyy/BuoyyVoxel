#ifndef BV_ENGINE_WORLD_CAMERA_H
#define BV_ENGINE_WORLD_CAMERA_H

#include <cglm/types.h>

// Remember, +x axis -> right, +y -> up, +z -> out of the screen

/**
 * Represents a simple free-look/fly camera.
 */
typedef struct Camera
{
    float fov, yaw, pitch;

    vec3 position;
    vec3 front, right, up;

    mat4 projection, view;
} Camera;

/**
 * Represents the relative unit vectors for the camera's movement.
*/
typedef enum CameraMovement
{
    CAMERA_FRONT,
    CAMERA_RIGHT,
    CAMERA_WORLD_UP
} CameraMovement;

/**
 * Initializes a camera at (0, 0, 3), looking in the -Z direction with FOV=90 degrees.
 * Also creates its projection and view matrices.
 */
void camera_init(Camera *camera, float width, float height);

/**
 * Updates the camera's front, right and up vectors and recalculates the view (lookat) matrix.
 */
void camera_update(Camera *camera);

/**
 * Rotates the camera on its pitch and yaw axis by the given amounts.
 */
void camera_rotate(Camera *camera, float pitch_delta, float yaw_delta);

/**
 * Moves the camera in the given direction by the given amount.
 */
void camera_move(Camera *camera, CameraMovement direction, float amount);

#endif // BV_ENGINE_WORLD_CAMERA_H

