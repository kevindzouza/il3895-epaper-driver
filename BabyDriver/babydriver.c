#include "babydriver.h"
#include <stdbool.h>
#include "bitmap.h"
#include <stdint.h>
#include "fonts.h"
#include <string.h>


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

            if (y >= FRAME_HEIGHT || x >= FRAME_WIDTH)
            {
                return;
            }
        }
    }

}

void draw_text (int x , int y , int size , char *text)
{
    const uint8_t *font = FONT;
    const uint8_t *drawChar ;

    int runningX = x;
    int runningY = y;

    int target;

    for( int i =0;  i < strlen(text); i++)
    {
        if (runningX >= FRAME_WIDTH)
        {
            runningX = x;
            runningY += size;
        }

        if (runningY >= FRAME_HEIGHT)
        {
            return;
        }

        target = (size * size ) * (text[i] - 32);
        drawChar = font + target;

        Print_Frame_Buffer(runningX, runningY, size, size, drawChar);

        runningX += size;
    }

}