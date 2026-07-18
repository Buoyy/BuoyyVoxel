#ifndef BV_ENGINE_RENDER_BACKEND_VERTEX_H
#define BV_ENGINE_RENDER_BACKEND_VERTEX_H

#include <cglm/types.h>

/**
 * Represents a vertex, the foundation of the graphics pipeline.
 */
typedef struct Vertex
{
    vec3 position;
    vec2 uv;
} Vertex;

#endif // BV_ENGINE_RENDER_BACKEND_VERTEX_H

