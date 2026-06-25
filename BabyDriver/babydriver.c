#include "babydriver.h"

int FRAME_BUFFER[FRAME_TOTAL] = {0};

void bit_set_rest( int x , int y, bool state)
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