#ifndef BLOCKS_H
#define BLOCKS_H

#include <stdint.h>
#include <openssl/sha.h>
#include "../include/utils.h"

#define BLOCK_SIZE 8100

typedef enum BlockType {
    BlockTypeCreate,
    BlockTypeUpdate,
    BlockTypeDelete,
} BlockType;

// Exactly (2^13) bytes: fits cleanly into 2 pages
typedef struct Block {
    Sha256Checksum id;
    Sha256Checksum checksum;
    uint32_t length;
    BlockType block_type;
    uint64_t unix_timestamp;
    uint64_t block_num;
    uint8_t data[BLOCK_SIZE];
} Block;


__always_inline void Block_hash(const Block* b, uint8_t* out_buffer);
__always_inline bool Block_equals(const Block* b1, const Block* b2);

#endif // BLOCKS_H