#ifndef IMGAE_H
#define IMAGE_H
#include <stddef.h>
#include <stdint.h>
#include "states.h"


struct image {
  uint64_t width, height;
  struct pixel* data;
};

struct pixel { uint8_t b, g, r; };

enum memory_status make_image(size_t width, size_t height, struct image* img);

void free_image(struct image* image);

#endif