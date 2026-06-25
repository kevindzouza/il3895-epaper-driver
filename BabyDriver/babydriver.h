#ifndef BABYDRIVER_H
#define BABYDRIVER_H

#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>

#define FRAME_WIDTH 255
#define FRAME_HEIGHT 128 

#define FRAME_TOTAL FRAME_HEIGHT*FRAME_WIDTH /8

void bit_set_reset( int x , int y, bool state);
void Print_Frame_Buffer(int x, int y, int width, int height, const uint8_t *frame_buffer);
bool gt_bit_val(int x, int y);
void draw_text (int x , int y , int size , char *text);


#endif