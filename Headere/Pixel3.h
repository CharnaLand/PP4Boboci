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

void scrPixel (Pixel3* P, FILE* f)
{
    fwrite( P, sizeof(Pixel3), 1, f);
}

void colorSwift (Pixel3* P, char wichOne, char howMuch)
{
    switch(wichOne)
    {
    case('R'):
        P->r = (P->r + howMuch)%256;
    break;
    case('G'):
        P->g = (P->g + howMuch)%256;
    break;
    case('B'):
        P->b = (P->b + howMuch)%256;
    break;
    }
}


#endif ///PIXEL3_H
