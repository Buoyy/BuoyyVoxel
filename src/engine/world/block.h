#ifndef BV_ENGINE_WORLD_BLOCK_H
#define BV_ENGINE_WORLD_BLOCK_H

#define FACE_VERTICES_COUNT 4
#define FACE_INDICES_COUNT  6

typedef enum BlockType
{
    BLOCK_AIR,
    BLOCK_DIRT,
    BLOCK_GRASS,
    BLOCK_STONE
} BlockType;

typedef struct Block
{
    BlockType type;
} Block;

typedef enum BlockFace
{
    BLOCK_FACE_FRONT,
    BLOCK_FACE_BACK,
    BLOCK_FACE_LEFT,
    BLOCK_FACE_RIGHT,
    BLOCK_FACE_TOP,
    BLOCK_FACE_BOTTOM,
} BlockFace;

#endif // BV_ENGINE_WORLD_BLOCK_H
