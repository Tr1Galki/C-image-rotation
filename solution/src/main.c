#include "bmp.h"
#include "file-manager.h"
#include "rotate.h"

int main( int argc, char** argv ) {
    (void) argc; (void) argv; // supress 'unused parameters' warning
    
    
    FILE *in,*out;
    
    if(read_file(&in, argv[1]) && write_file(&out, argv[2])) 
    {
        
        struct image img;

        enum read_status status_r = from_bmp(in, &img);
        
        switch(status_r) {
            case READ_INVALID_HEADER:
                printf("%s\n","invalid header");
            case READ_INVALID_BITS:
                printf("%s\n", "invalid bits error");
                break;
            case READ_ERROR:
                printf("%s\n", "read error");
                break;
            default:
                break;

        }
             

        struct image rotated_img = rotate(img);

        enum write_status status_w = to_bmp(out,&rotated_img);

        if (status_w == WRITE_ERROR) 
            printf("%s\n", "write error");

        close_file(in);
        close_file(out);
        free_image(&img);
        free_image(&rotated_img);
        

    } else {
        return 1;
    }

    return 0;
}
