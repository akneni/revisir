#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/utils.h"
#include "../include/metadata.h"



/// @brief Creates a new object
/// @param id 
/// @return 
__always_inline Object Obect_init(Sha256Checksum id) {
    Object obj = {
        .id = id,
        .num_bytes = 0,
    };

    return obj;
}
