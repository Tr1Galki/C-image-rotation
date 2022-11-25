#include <stdio.h>
#include "bmp.h"
#include "file-manager.h"



int main( int argc, char** argv ) {
    (void) argc; (void) argv; // supress 'unused parameters' warning
    FILE* file = NULL;
    read_file(&file, "C:\\Users\\pogchamp\\Documents\\cProjects\\assignment-3-image-rotation\\solution\\src\\input.bmp");
    struct bmp_header my_header;
    int b = read_header(file, &my_header);
    printf("\nENUM VALUE:%d ",b);
    
    

    return 0;
}
