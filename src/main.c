#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <memory.h>

#include <openssl/sha.h>

#define BLOCK_SIZE 8136

// Exactly (2^13) bytes: fits cleanly into 2 pages
typedef struct Block {
	uint64_t id;
	uint64_t block_num;
	uint64_t unix_timestamp;
	uint32_t length;
	uint32_t checksum;
	uint8_t data[BLOCK_SIZE]; 
} Block;

/// @brief 
/// @param b 
/// @param out_buffer Must be least SHA256_DIGEST_LENGTH bytes (32 bytes)
void Block_hash(const Block* b, uint8_t* out_buffer) {
	SHA256((const unsigned char*) &b->data[0], BLOCK_SIZE, (unsigned char*) out_buffer);
}

bool Block_equals(const Block* b1, const Block* b2) {
	if (b1->checksum != b2->checksum) {
		return false;
	}

	uint64_t* b1_data = (uint64_t*) &b1->data[0];
	uint64_t* b2_data = (uint64_t*) &b2->data[0];

	for(int i = 0; i < (BLOCK_SIZE/8); i++) {
		if (b1_data[i] != b2_data[i]) {
			return false;
		}
	}
	return true;
}

int main() {
	Block b = {
		.length = 121,
	};

	uint8_t h[SHA256_DIGEST_LENGTH];

	SHA256((const unsigned char*) &b, sizeof(b), (unsigned char*) h);

	return 0;
}
