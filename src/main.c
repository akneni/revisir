#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <memory.h>
#include <openssl/sha.h>
#include "../include/utils.h"
#include "../include/blocks.h"
#include "../include/metadata.h"



int main() {
	Block b = {
		.length = 121,
	};

	printf("%lu\n", sizeof(Block));

	return 0;
}
