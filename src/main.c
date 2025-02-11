#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <memory.h>
#include <openssl/sha.h>
#include "../include/utils.h"
#include "../include/blocks.h"

int main() {
	Block b = {
		.length = 121,
	};

	printf("%lu\n", sizeof(Block));

	// uint8_t h[SHA256_DIGEST_LENGTH];

	// SHA256((const unsigned char*) &b, sizeof(b), (unsigned char*) h);

	return 0;
}
