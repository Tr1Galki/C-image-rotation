#include <stdio.h>
#include "bmp.h"
#include <stdbool.h>

bool read_file(FILE** file, char* file_name) {
    *file = fopen(file_name, "rb");
    return (file != NULL);
}

bool write_file(char* file_name) {
    FILE* file = fopen(file_name, "wb");
    return (file != NULL);
}

bool close_file(FILE* file) {
    return fclose(file) == 0;
}