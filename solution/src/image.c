#include <stdint.h>
#include <stdlib.h>
#include "image.h"



enum memory_status make_image(size_t width, size_t height, struct image* img) {
    struct pixel* px = malloc(sizeof(struct pixel) * width * height);
    if (px == 0) {
        return ALLOCATE_MEMORY_ERROR;
    }
    img->data = px;
    img->width = width;
    img->height = height;
    return ALLOCATE_MEMORY_OK;
}

void free_image(struct image* image) {
    free(image->data);
}


