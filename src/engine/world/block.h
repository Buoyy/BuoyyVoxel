#ifndef BV_ENGINE_WORLD_BLOCK_H
#define BV_ENGINE_WORLD_BLOCK_H

/**
 * Represents all the block types currently in the game.
 */
typedef enum BlockType
{
    BLOCK_DIRT,
    BLOCK_STONE,
    BLOCK_GRASS,
    BLOCK_AIR,

    BLOCK_TYPE_COUNT
} BlockType;

/**
 * Represents the blueprint for a block. Pretty barebones for now.
 */
typedef struct Block
{
    BlockType type;
} Block;

#endif // BV_ENGINE_WORLD_BLOCK_H

