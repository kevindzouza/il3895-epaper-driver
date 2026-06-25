#include "bitmap.h"
#include "babydriver.h"
#include "fonts.h"
#include <stdio.h>

int main(void)
{
    //Print_Frame_Buffer(10, 10, TEST_IMAGE_WIDTH, TEST_IMAGE_HEIGHT, test_image);

    draw_text(10, 10, 16, "Hello, World!");


    for(int y = 0; y < 100; y++)
    {
        for(int x = 0; x < 100; x++)
        {
            if (gt_bit_val(x, y))
            {
                printf("1");
            }
            else
            {
                printf("0");
            }
        }
        printf("\n");
    }
    return 0;
}