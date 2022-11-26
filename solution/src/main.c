#include <stdio.h>
#include "bmp.h"
#include "file-manager.h"
#include "states.h"
#include "rotate.h"

int main( int argc, char** argv ) {
    (void) argc; (void) argv; // supress 'unused parameters' warning
    // FILE* file = NULL;
    // read_file(&file, "C:\\Users\\pogchamp\\Documents\\cProjects\\assignment-3-image-rotation\\solution\\src\\input.bmp");
    // struct bmp_header my_header;
    // int b = read_header(file, &my_header);
    // printf("\nENUM VALUE:%d ",b);
    FILE *in,*out;
    
    // if(read_file(&in, "C:\\Users\\pogchamp\\Documents\\cProjects\\assignment-3-image-rotation\\solution\\src\\input.bmp") && write_file(&out, "C:\\Users\\pogchamp\\Documents\\cProjects\\assignment-3-image-rotation\\solution\\src\\output.bmp"))
    if(read_file(&in, argv[0]) && write_file(&out, argv[1])) {
        struct image img;

        from_bmp(in, &img);

        struct image rotated_img = rotate(img);

        to_bmp(out,&rotated_img);


    }

    return 0;
}
