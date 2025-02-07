#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <memory.h>
#include <openssl/sha.h>

void gen_filename(uint64_t file_num, char* out_buffer);

#endif // UTILS_H