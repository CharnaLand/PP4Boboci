#ifndef PT_IMG_H

#define PT_IMG_H

#include <stdio.h>
#include "Pixel3.h"
#define S_CHAR sizeof(char)

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0')

typedef struct
{
    unsigned int H, W, dimImg;
    int dimPadding;
    char* titlu;
    Pixel3* mareVector;
    FILE* f;

} PtImg;

void deschFisier (PtImg* img, char* numeFis)
{
    img->f = fopen(numeFis,"rb");
}

void citPadding(PtImg* img)
{
    int dp = img->dimPadding;
    if(dp == 0) return;
    char* deCitit = malloc(dp);
    fread(deCitit,S_CHAR,dp, img->f);
    free(deCitit);
}


void prelTitlu(PtImg* img)
{
    fseek(img->f,0,SEEK_SET);
    img->titlu = malloc(54*S_CHAR);
    fread(img->titlu,S_CHAR,54,img->f);

    unsigned int* dim = img->titlu+2;
    img->dimImg = *dim;
    dim = img->titlu+18;
    img->W = *dim;
    dim = img->titlu+22;
    img->H = *dim;

    img->dimPadding = (4 - img->W%4) %4;

    char padHead[2];
    fread(padHead,S_CHAR,2,img->f);
}



void citireVector (PtImg* img)
{
    img->mareVector = (Pixel3*)malloc(sizeof(Pixel3) * img->dimImg);
    int i,j;
    for(j =0; j< img->H; j++)
    {
        for(i = 0; i< img->W; i++)
            citPixel(img->mareVector + img->W * j + i, img->f);

        citPadding(img);
    }
}

void afisDetalii(PtImg *img)
{
        printf("\nIntaltimea : %d\nLungimea : %d\nMarimea : %d\n",img->H,img->W,img->dimImg);
}

void imgEdit(PtImg* img, char wichColor, char howMuch)
{
    int i;
    for(i=0; i<img->dimImg; i++)
        colorSwift(img->mareVector+i, wichColor, howMuch);
}

void rebuildImg (PtImg* img, char* newImg)
{
    FILE* g = fopen(newImg,"wb+");
    Pixel3 gol;
    gol.r = 0;
    gol.g = 0;
    gol.b = 0;

    fwrite(img->titlu,54,1,g);
    fwrite(&gol.r,S_CHAR,2,g);
    int i,j;
    for(j=0; j<img->H; j++)
    {
        for (i=0; i< img->W; i++)
            scrPixel(img->mareVector + img->W * j + i, g);

        for(i=0; i<img->dimPadding; i++)
            scrPixel(&gol,g);
    }
    fclose(g);
}


void destroyElm(PtImg* img)
{
    fclose (img->f);
    free ( img->mareVector );
    free ( img->titlu );
    ///AM DISTRUS VARIABILELE GLOBALE
}



#endif ///PT_IMG_H
