#ifndef BV_ENGINE_RENDER_PRIMITIVES_H
#define BV_ENGINE_RENDER_PRIMITIVES_H

// Simple triangle
extern const float triangle_vertices[9];

// Simple quad/rectangle
extern const float quad_vertices[12];
extern const unsigned int quad_indices[6];

// Simple cube (Foundation of BuoyyVoxel)
extern const float cube_vertices[24*3];
extern const unsigned int cube_indices[36];

#endif