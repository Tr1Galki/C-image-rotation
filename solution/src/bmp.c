#include "bmp.h"


enum read_status create_bmp_header() {
    return READ_OK;
}

enum read_status from_bmp(FILE* const in, struct image* const img) 
{
    struct bmp_header header;
    if (!read_header(in, &header)) 
        return READ_INVALID_HEADER; 

    size_t padding = get_padding(header.biWidth);

    if (make_image(header.biWidth, header.biHeight, img) != 0) 
        return READ_INVALID_BITS;
    
    for (size_t i = 0; i < img->height; ++i){
        if (fread(img->data + (i * img->width), sizeof(struct pixel), img->width, in) != img->width) {
            free_image(img);
            return READ_INVALID_SIGNATURE;
        }
        if (fseek(in, (long) padding, SEEK_CUR) != 0) {
            free_image(img);
            return READ_INVALID_BITS;
        }

    }

    return READ_OK;
}

enum write_status to_bmp(FILE* const out, const struct image* const img) 
{
    return WRITE_ERROR;
}

enum read_status read_header(FILE* file, struct bmp_header* header) {
    if (fread(header, sizeof(struct bmp_header), 1, file) != 1) {
        return READ_INVALID_HEADER;
    }
    return READ_OK;
    
}


enum write_status write_header(FILE* file, const struct bmp_header* header) {
    if (fwrite(header, sizeof(struct bmp_header), 1, file) != 1) {
        return WRITE_ERROR;
    }
    return WRITE_OK;
}

size_t get_padding(size_t width) {
    return (4 - (sizeof(struct pixel) * width)) % 4;
}
