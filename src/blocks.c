#include <stdint.h>
#include <openssl/sha.h>
#include "../include/utils.h"
#include "../include/blocks.h"





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
