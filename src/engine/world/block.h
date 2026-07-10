#ifndef BV_ENGINE_WORLD_BLOCK_H
#define BV_ENGINE_WORLD_BLOCK_H

typedef enum BlockType BlockType;
enum BlockType
{
    BLOCK_AIR,
    BLOCK_DIRT,
    BLOCK_GRASS,
    BLOCK_STONE
};

typedef struct Block Block;
struct Block
{
    BlockType type;
};

#endif // BV_ENGINE_WORLD_BLOCK_H