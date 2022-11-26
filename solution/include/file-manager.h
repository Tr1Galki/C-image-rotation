#ifndef FILE_MANAGER
#define FILE_MANAGER

#include <stdio.h>
#include <stdbool.h>

#include "bmp.h"

bool read_file(FILE** file, char* file_name);

bool write_file(FILE** file, char* file_name);

bool close_file(FILE* file);

#endif