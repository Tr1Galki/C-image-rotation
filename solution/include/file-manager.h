#include <stdbool.h>
#include <stdio.h>
#include "bmp.h"

bool read_file(FILE** file, char* file_name);

bool write_file(char* file_name);

bool close_file(FILE* file);