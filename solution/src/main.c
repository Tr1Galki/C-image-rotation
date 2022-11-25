#include <stdio.h>
#include "bmp.h"
#include "file-manager.h"

int main( int argc, char** argv ) {
    (void) argc; (void) argv; // supress 'unused parameters' warning
    printf("123");
    printf("amogus");
    FILE* file;
    read_file(&file, "tester\\tests\\1\\input.bmp");
    struct bmp_header my_header;
    int b = (int) read_header(file, &my_header);
    printf("\nENUM VALUE:%d ",b);
    


    
    return 0;
}
