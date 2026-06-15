#include "engine/render/primitives.h"

const Vertex triangle_vertices[] = 
{
    { { 0.0f,   0.5f, 0.0f } },
    { { 0.5f,  -0.5f, 0.0f } },
    { {-0.5f,  -0.5f, 0.0f } }
};

const Vertex quad_vertices[] = 
{
    { { -0.5f,  -0.5f, 0.0f } },
    { {  0.5f,  -0.5f, 0.0f } },
    { {  0.5f,   0.5f, 0.0f } },
    { { -0.5f,   0.5f, 0.0f } },
};

const unsigned int quad_indices[] = 
{
    0, 1, 2,
    2, 3, 0
};

const Vertex cube_vertices[] = 
{
    // Front face
    { { -0.5f, -0.5f,  0.5f } },
    { {  0.5f, -0.5f,  0.5f } },
    { {  0.5f,  0.5f,  0.5f } },
    { { -0.5f,  0.5f,  0.5f } },

    // Back face
    { { -0.5f, -0.5f, -0.5f } },
    { {  0.5f, -0.5f, -0.5f } },
    { {  0.5f,  0.5f, -0.5f } },
    { { -0.5f,  0.5f, -0.5f } },

    // Left face
    { { -0.5f, -0.5f,  0.5f } },
    { { -0.5f, -0.5f, -0.5f } },
    { { -0.5f,  0.5f, -0.5f } },
    { { -0.5f,  0.5f,  0.5f } },

    // Right face
    { {  0.5f, -0.5f,  0.5f } },
    { {  0.5f, -0.5f, -0.5f } },
    { {  0.5f,  0.5f, -0.5f } },
    { {  0.5f,  0.5f,  0.5f } },

    // Top face
    { { -0.5f,  0.5f,  0.5f } },
    { {  0.5f,  0.5f,  0.5f } },
    { {  0.5f,  0.5f, -0.5f } },
    { { -0.5f,  0.5f, -0.5f } },

    // Bottom face
    { { -0.5f, -0.5f,  0.5f } },
    { {  0.5f, -0.5f,  0.5f } },
    { {  0.5f, -0.5f, -0.5f } },
    { { -0.5f, -0.5f, -0.5f } },
};

const unsigned int cube_indices[] = 
{
    // Front face
    0,  1,  2,
    2,  3,  0,

    // Back face
    4,  5,  6,
    6,  7,  4,

    // Left face
    8,  9,  10,
    10, 11,  8,

    // Right face
    12, 13, 14,
    14, 15, 12,

    // Top face
    16, 17, 18,
    18, 19, 16,

    // Bottom face
    20, 21, 22,
    22, 23, 20,
};