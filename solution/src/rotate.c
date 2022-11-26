#include <stdlib.h>
#include "rotate.h"


struct image rotate(struct image source) {
    struct image rotated = {
        .height = source.width,
        .width = source.height,
        .data = malloc(sizeof(struct pixel) * source.height * source.width)
    };

    for (size_t i = 0; i < rotated.height; i++) {
        for (size_t j = 0; j < rotated.width; j++) {
            rotated.data[j + i * rotated.width] = source.data[(source.height - j - 1) * source.width + i];
        }
    }
    return rotated;
}


