#include "bmp.h"
#include <stdio.h>

enum read_status create_bmp_header() {
    return READ_OK;
}

enum read_status from_bmp(FILE* const in, struct image* const img) 
{
    
    uint32_t height;
    struct bmp_header header;
    enum read_status status = read_header(in, &header);
    if (status == READ_INVALID_HEADER) {
        return status;   
    }
    
    height = header.biHeight;
    for (uint32_t i = 0; i < height; i++) {
        
    }
    return READ_OK;
}

enum write_status to_bmp(FILE* const out, const struct image* const img) 
{
    return WRITE_ERROR;
}

enum read_status read_header(FILE* file, struct bmp_header* header) {
    size_t data = fread(header, sizeof(struct bmp_header), 1, file);
    if (data == 1) {
        return READ_OK;
    } else {
        return READ_INVALID_HEADER;
    }
}


enum write_status write_header(FILE* file, const struct bmp_header* header) {
    size_t data = fwrite(header, sizeof(struct bmp_header), 1, file);
    if (data == 1) {
        return WRITE_OK;
    } else {
        return WRITE_ERROR;
    } 
}