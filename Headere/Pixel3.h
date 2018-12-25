#ifndef PIXEL3_H

#define PIXEL3_H

#include <stdio.h>

typedef struct
{
    char b,g,r;
} Pixel3;

void citPixel (Pixel3* P, FILE* f)
{
    fread (P, sizeof(Pixel3), 1, f);
}

#endif ///PIXEL3_H
