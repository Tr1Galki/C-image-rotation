#include "file-manager.h"


enum read_status read_file(FILE** file, char* file_name) {
    *file = fopen(file_name, "rb");
    if (file != NULL) {
        return READ_OK;
    } 
    else {
        return READ_ERROR;
    }
}

enum write_status write_file(FILE** file, char* file_name) {
    *file = fopen(file_name, "wb");
    if (file != NULL) {
        return WRITE_OK;
    } else {
        return WRITE_ERROR;
    }
}

enum close_status close_file(FILE* file) {
    return fclose(file) == 0;
}
