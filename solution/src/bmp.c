#include  <stdint.h>
#include "bmp.h"


struct bmp_header create_bmp_header(const struct image* img) {

    size_t size = (img->width + get_padding(img->width)) * img->height * sizeof(struct pixel);

    return (struct bmp_header){
            .bfType = 19778,
            .bfileSize = size + sizeof(struct bmp_header),
            .bfReserved = 0,
            .bOffBits = sizeof(struct bmp_header),
            .biSize = 40,
            .biWidth = img->width,
            .biHeight = img->height,
            .biPlanes = 1,
            .biBitCount = 24,
            .biCompression = 0,
            .biSizeImage = size,
            .biXPelsPerMeter = 0,
            .biYPelsPerMeter = 0,
            .biClrUsed = 0,
            .biClrImportant = 0,
    };
}

enum read_status from_bmp(FILE* const in, struct image* img) 
{
    struct bmp_header header;
    if (read_header(in, &header)) 
        return READ_INVALID_HEADER; 

    if (make_image(header.biWidth, header.biHeight, img) != 0) 
        return READ_INVALID_BITS;

    size_t padding = get_padding(header.biWidth);
    
    for (size_t y = 0; y < img->height; y++){
            size_t ret = fread(img->data + img->width * y, sizeof (struct pixel), img->width, in);
            if (ret != img->width){
                if (feof(in)){
                    return READ_ERROR;
                }
                return READ_ERROR;
            }
            if (fseek(in, padding, SEEK_CUR)){
                return READ_ERROR;
            }
        }

    return READ_OK;

}

enum write_status to_bmp(FILE* const out,  struct image const* img) 
{
    struct bmp_header header = create_bmp_header(img);

    if (!fwrite(&header, sizeof(struct bmp_header), 1, out)){
        return WRITE_ERROR;
    }

    size_t padding = get_padding(img->width);
    uint8_t zero_padding = 0;

    for (size_t i = 0; i < img->height; i++){
        if (fwrite(img->data + (i * img->width), sizeof(struct pixel), img->width, out) != img->width){
            return WRITE_ERROR;
        }

        for (size_t j = 0; j < padding; j++){
            if (!fwrite(&zero_padding, sizeof(uint8_t), 1, out)){
                return WRITE_ERROR;
            }
        }
    }

    return WRITE_OK;

}

size_t get_padding(size_t width) {
    return (4 - (sizeof(struct pixel) * width)) % 4;
}

enum write_status write_header(FILE* file, const struct bmp_header* header) {
    if (fwrite(header, sizeof(struct bmp_header), 1, file) != 1) {
        return WRITE_ERROR;
    }
    return WRITE_OK;
}

enum read_status read_header(FILE* file, struct bmp_header* header) {
    if (fread(header, sizeof(struct bmp_header), 1, file) != 1) {
        return READ_INVALID_HEADER;
    }
    return READ_OK;
    
}