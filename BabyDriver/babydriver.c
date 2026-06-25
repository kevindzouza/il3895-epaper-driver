#include "babydriver.h"
#include <stdbool.h>
#include "bitmap.h"
#include <stdint.h>


int FRAME_BUFFER[FRAME_TOTAL] = {0};

void bit_set_reset( int x , int y, bool state)
{
    int pos = (FRAME_WIDTH*y + x) >> 3;

    if(state)
    {
        FRAME_BUFFER[pos] |= (0x80 >> (x & 0x07) );
    }
    else 
    {
         FRAME_BUFFER[pos] &= ~(0x80 >> (x & 0x07) );

    }
}

bool gt_bit_val(int x, int y)
{
    int pos = (FRAME_WIDTH*y + x) >> 3;
    return FRAME_BUFFER[pos] & (0x80 >> (x & 0x07));
}

void Print_Frame_Buffer(int x, int y, int width, int height, const uint8_t *frame_buffer)
{

    uint8_t Mask = 0;
    int i, j;
    int size = width * height >> 3;

    int OrignalX = x;
    int OrignalY = y;

    for(i = 0; i < size; i++)
    {
        for(j = 0; j < 8; j++)
        {
            Mask = 0x80 >> j;

            bit_set_reset(x, y, frame_buffer[i] & Mask);
            x++;

            if((x - OrignalX) == width)
            {
                x = OrignalX;
                y++;
            }

            if ((y - OrignalY) == height)
            {
                return;
            }
        }
    }

}