#ifndef METADATA_H
#define METADATA_H

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/utils.h"


typedef struct Object {
    Sha256Checksum id;
    uint64_t num_bytes;
} Object;


__always_inline Object Obect_init(Sha256Checksum id);

#endif // METADATA_H