#include "engine/render/backend/primitives.h"

const float triangle_vertices[] = 
{
     0.0f,   0.5f,  0.0f,
     0.5f,  -0.5f,  0.0f,
    -0.5f,  -0.5f,  0.0f
};

const Vertex quad_vertices[] = 
{
    { { -0.5f,  -0.5f, 0.0f }, { 0.0f, 0.0f }, },
    { {  0.5f,  -0.5f, 0.0f }, { 1.0f, 0.0f }, },
    { {  0.5f,   0.5f, 0.0f }, { 1.0f, 1.0f }, },
    { { -0.5f,   0.5f, 0.0f }, { 0.0f, 1.0f }, },
};

const unsigned int quad_indices[] = 
{
    0, 1, 2,
    2, 3, 0
};

const FaceGeometry block_faces[FACE_COUNT] =
{
    [FACE_FRONT] =
    {
        .vertices =
        {
            { { -0.5f, -0.5f,  0.5f }, { 0.0f, 0.0f } },
            { {  0.5f, -0.5f,  0.5f }, { 1.0f, 0.0f } },
            { {  0.5f,  0.5f,  0.5f }, { 1.0f, 1.0f } },
            { { -0.5f,  0.5f,  0.5f }, { 0.0f, 1.0f } },
        }
    },

    [FACE_BACK] =
    {
        .vertices =
        {
            { { -0.5f, -0.5f, -0.5f }, { 0.0f, 0.0f } },
            { {  0.5f, -0.5f, -0.5f }, { 1.0f, 0.0f } },
            { {  0.5f,  0.5f, -0.5f }, { 1.0f, 1.0f } },
            { { -0.5f,  0.5f, -0.5f }, { 0.0f, 1.0f } },
        }
    },

    [FACE_LEFT] =
    {
        .vertices =
        {
            { { -0.5f, -0.5f,  0.5f }, { 0.0f, 0.0f } },
            { { -0.5f, -0.5f, -0.5f }, { 1.0f, 0.0f } },
            { { -0.5f,  0.5f, -0.5f }, { 1.0f, 1.0f } },
            { { -0.5f,  0.5f,  0.5f }, { 0.0f, 1.0f } },
        }
    },

    [FACE_RIGHT] =
    {
        .vertices =
        {
            { {  0.5f, -0.5f,  0.5f }, { 0.0f, 0.0f } },
            { {  0.5f, -0.5f, -0.5f }, { 1.0f, 0.0f } },
            { {  0.5f,  0.5f, -0.5f }, { 1.0f, 1.0f } },
            { {  0.5f,  0.5f,  0.5f }, { 0.0f, 1.0f } },
        }
    },

    [FACE_TOP] =
    {
        .vertices =
        {
            { { -0.5f,  0.5f,  0.5f }, { 0.0f, 0.0f } },
            { {  0.5f,  0.5f,  0.5f }, { 1.0f, 0.0f } },
            { {  0.5f,  0.5f, -0.5f }, { 1.0f, 1.0f } },
            { { -0.5f,  0.5f, -0.5f }, { 0.0f, 1.0f } },
        }
    },

    [FACE_BOTTOM] =
    {
        .vertices =
        {
            { { -0.5f, -0.5f,  0.5f }, { 0.0f, 0.0f } },
            { {  0.5f, -0.5f,  0.5f }, { 1.0f, 0.0f } },
            { {  0.5f, -0.5f, -0.5f }, { 1.0f, 1.0f } },
            { { -0.5f, -0.5f, -0.5f }, { 0.0f, 1.0f } },
        }
    },
};
