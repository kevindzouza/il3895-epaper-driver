#include "bitmap.h"
#include "babydriver.h"
#include <stdio.h>

int main(void)
{
    Print_Frame_Buffer(0, 0, TEST_IMAGE_WIDTH, TEST_IMAGE_HEIGHT, test_image);

    for(int y = 0; y < TEST_IMAGE_HEIGHT; y++)
    {
        for(int x = 0; x < TEST_IMAGE_WIDTH; x++)
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