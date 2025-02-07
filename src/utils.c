#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <memory.h>

#include <openssl/sha.h>

#define UNIX_TIMESTAMP  uint64_t

/// @brief 
/// @param file_num 
/// @param out_buffer must be 25 bytes long (16 hex characters, 2 for the file type, 6 for the file extension, and 1 for the null terminator)
void gen_filename(uint64_t file_num, char file_type, char* out_buffer) {
    snprintf(out_buffer, 25, "%lx-%c.verdb", file_num, file_type);
}

typedef struct Sha256Checksum {
    uint64_t _1;
    uint64_t _2;
    uint64_t _3;
    uint64_t _4;
} Sha256Checksum;

__always_inline bool Sha256Checksum_equals(Sha256Checksum* x1, Sha256Checksum* x2) {
    return (
        x1->_1 == x2->_1 &&
        x1->_2 == x2->_2 &&
        x1->_3 == x2->_3 &&
        x1->_4 == x2->_4
    );
}

typedef struct Metadata {
    uint64_t num_blocks;
    uint64_t num_bytes_stored;
    uint64_t num_bytes_total;
    UNIX_TIMESTAMP earliest_version;
} Metadata;

typedef struct ObjectMetadata {
    uint64_t num_bytes;
    Sha256Checksum global_checksum;
} Metadata;
