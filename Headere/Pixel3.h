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

void afisPixel(Pixel3* P)
{
    unsigned int* a = malloc(sizeof(unsigned int)*3);
    a[0] = a[1] = a[2] = 0;
    *((char*)a+0) = P->r ;
    *((char*)(a+1)) = P->g ;
    *((char*)(a+2)) = P->b ;
    //printf("( %u %u %u )",P->r,P->g,P->b);
    printf("( %u %u %u )",a[0],a[1],a[2]);
    free(a);
}

#endif ///PIXEL3_H
