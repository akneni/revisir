#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <memory.h>

#include <openssl/sha.h>
#include "../include/utils.h"










/// @brief 
/// @param file_num 
/// @param out_buffer must be 25 bytes long (16 hex characters, 2 for the file type, 6 for the file extension, and 1 for the null terminator)
void gen_filename(uint64_t file_num, char file_type, char* out_buffer) {
    snprintf(out_buffer, 25, "%lx-%c.verdb", file_num, file_type);
}


__always_inline bool Sha256Checksum_equals(Sha256Checksum* x1, Sha256Checksum* x2) {
    return (
        x1->_1 == x2->_1 &&
        x1->_2 == x2->_2 &&
        x1->_3 == x2->_3 &&
        x1->_4 == x2->_4
    );
}
