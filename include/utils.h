#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <memory.h>
#include <openssl/sha.h>

#define UTILS_H
#define UNIX_TIMESTAMP uint64_t
#define UNIX_TIMESTAMP uint64_t
#define UNIX_TIMESTAMP uint64_t

typedef struct Sha256Checksum {

uint64_t _1;

uint64_t _2;

uint64_t _3;

uint64_t _4;

} Sha256Checksum;

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

typedef struct Sha256Checksum {

uint64_t _1;

uint64_t _2;

uint64_t _3;

uint64_t _4;

} Sha256Checksum;

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

void gen_filename(uint64_t file_num, char file_type, char* out_buffer);
__always_inline bool Sha256Checksum_equals(Sha256Checksum* x1, Sha256Checksum* x2);

#endif // UTILS_H