#include <stdio.h>
#include <stdbool.h>
#include "bmp.h"


bool read_file(FILE** file, char* file_name) {
    *file = fopen(file_name, "rb");
    return (file != NULL);
}

bool write_file(FILE** file, char* file_name) {
    *file = fopen(file_name, "wb");
    return (file != NULL);
}

bool close_file(FILE* file) {
    return fclose(file) == 0;
}
