#ifndef BV_ENGINE_RENDER_PRIMITIVES_H
#define BV_ENGINE_RENDER_PRIMITIVES_H

#include "engine/render/vertex.h"

// Simple triangle
extern const Vertex triangle_vertices[9];

// Simple quad/rectangle
extern const Vertex quad_vertices[12];
extern const unsigned int quad_indices[6];

// Simple cube (Foundation of BuoyyVoxel)
extern const Vertex cube_vertices[24*3];
extern const unsigned int cube_indices[36];

#endif