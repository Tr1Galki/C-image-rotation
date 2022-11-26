#ifndef BMP_H
#define BMP_H
#include "image.h"
#include <stdio.h>
#include <stdint.h>





struct __attribute__((packed)) bmp_header {
        uint16_t bfType;
        uint32_t bfileSize;
        uint32_t bfReserved;
        uint32_t bOffBits;
        uint32_t biSize;
        uint32_t biWidth;
        uint32_t biHeight;
        uint16_t biPlanes;
        uint16_t biBitCount;
        uint32_t biCompression;
        uint32_t biSizeImage;
        uint32_t biXPelsPerMeter;
        uint32_t biYPelsPerMeter;
        uint32_t biClrUsed;
        uint32_t biClrImportant;
};




size_t get_padding(size_t width);

enum read_status from_bmp( FILE* const in, struct image* img );

enum write_status to_bmp( FILE* const out,  struct image const* img );

struct bmp_header create_bmp_header(const struct image* img);

enum read_status read_header(FILE* file, struct bmp_header* header);

enum write_status write_header(FILE* file, const struct bmp_header* header);

#endif

