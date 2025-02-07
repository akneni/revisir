#include <stdint.h>
#include <openssl/sha.h>

#include "utils.c"


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

/// @brief 
/// @param b 
/// @param out_buffer Must be least SHA256_DIGEST_LENGTH bytes (32 bytes)
__always_inline void Block_hash(const Block* b, uint8_t* out_buffer) {
	SHA256((const unsigned char*) &b->data[0], BLOCK_SIZE, (unsigned char*) out_buffer);
}

/// @brief 
/// @param b1 
/// @param b2 
/// @return  
__always_inline bool Block_equals(const Block* b1, const Block* b2) {
	return Sha256Checksum_equals(&b1->checksum, &b2->checksum);
}