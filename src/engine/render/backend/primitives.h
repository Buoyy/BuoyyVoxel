#ifndef BV_ENGINE_RENDER_BACKEND_PRIMITIVES_H
#define BV_ENGINE_RENDER_BACKEND_PRIMITIVES_H

#include "engine/render/backend/vertex.h"

#define FACE_VERTICES_COUNT 4
#define FACE_INDICES_COUNT  6

/**
 * Represents the different directions a block's face can point in.
 */
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

/**
 * Represents the geometry of a quad representing a face of a block.
 */
typedef struct FaceGeometry
{
    Vertex vertices[FACE_VERTICES_COUNT];
} FaceGeometry;

/**
 * Represents a simple triangle without textures.
 */
extern const float triangle_vertices[9];

/**
 * Represents a quad (square) with texture UVs.
 */
extern const Vertex quad_vertices[FACE_VERTICES_COUNT];

/**
 * Represents the drawing indices of the vertices of `quad_vertices`.
 */
extern const unsigned int quad_indices[FACE_INDICES_COUNT];

/**
 * Represents all the Vertices of a block separated as Vertices of its respective faces.
 * The foundation of all Voxels.
 */
extern const FaceGeometry block_faces[FACE_COUNT];

#endif // BV_ENGINE_RENDER_BACKEND_PRIMITIVES_H

