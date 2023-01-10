#ifndef FILE_MANAGER
#define FILE_MANAGER

#include <stdbool.h>
#include <stdio.h>


#include "bmp.h"

enum read_status read_file(FILE** file, char* file_name);

enum write_status write_file(FILE** file, char* file_name);

enum close_status close_file(FILE* file);

#endif
