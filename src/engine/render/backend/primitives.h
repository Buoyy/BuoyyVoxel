#ifndef BV_ENGINE_RENDER_BACKEND_PRIMITIVES_H
#define BV_ENGINE_RENDER_BACKEND_PRIMITIVES_H

#include "engine/render/backend/vertex.h"

#define FACE_VERTICES_COUNT 4
#define FACE_INDICES_COUNT  6

typedef enum FaceDirection
{
    FACE_FRONT,
    FACE_BACK,
    FACE_LEFT,
    FACE_RIGHT,
    FACE_TOP,
    FACE_BOTTOM,

    FACE_COUNT
} FaceDirection;

typedef struct FaceGeometry
{
    Vertex vertices[FACE_VERTICES_COUNT];
} FaceGeometry;

// Simple triangle
extern const float triangle_vertices[9];

// Simple quad/rectangle
extern const Vertex quad_vertices[FACE_VERTICES_COUNT];
extern const unsigned int quad_indices[FACE_INDICES_COUNT];

// Legacy primitives used by old rendering tests.
// TODO: remove when test suite is migrated
extern const Vertex cube_vertices[24];
extern const unsigned int cube_indices[36];

extern const FaceGeometry block_faces[FACE_COUNT];

#endif
