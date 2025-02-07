#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <memory.h>

#include <openssl/sha.h>

#define UNIX_TIMESTAMP  uint64_t

/// @brief 
/// @param file_num 
/// @param out_buffer must be 23 bytes long (16 hex characters, 6 for the file extension, and 1 for the null terminator)
void gen_filename(uint64_t file_num, char* out_buffer) {
    sprintf(out_buffer, "%x.verdb", file_num);
}

typedef struct Metadata {
    uint64_t num_blocks;
    uint64_t num_bytes_stored;
    uint64_t num_bytes_total;
    UNIX_TIMESTAMP earliest_version;
};