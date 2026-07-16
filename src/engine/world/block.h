#ifndef BV_ENGINE_WORLD_BLOCK_H
#define BV_ENGINE_WORLD_BLOCK_H

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

#endif // BV_ENGINE_WORLD_BLOCK_H
