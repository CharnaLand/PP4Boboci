#include <stdio.h>
#include <stdlib.h>
#include "Headere/Pixel3.h"
#include "Headere/PtImg.h"



void cevaAfisari (PtImg pozaMea)
{

printf("D:\tW:\tH:\n%u\t%u\t%u\n",pozaMea.dimImg,pozaMea.W,pozaMea.H);
/*
citireVector(&pozaMea);
afisDetalii(&pozaMea);
*/

for(int i=0;i<54;i++)
{
    printf("%d: ",i);
    printf(BYTE_TO_BINARY_PATTERN,BYTE_TO_BINARY(pozaMea.titlu[i]));
    printf("\t");
    if( (i+1)%4 == 0) printf("\n");
}

printf("\n\n");
}

int main()
{
PtImg pozaMea, puppy, steag, hardei;

deschFisier(&pozaMea,"waterfall.bmp");
prelTitlu(&pozaMea);
deschFisier(&puppy,"puppy.bmp");
prelTitlu(&puppy);
deschFisier(&steag,"unSteag.bmp");
prelTitlu(&steag);
deschFisier(&hardei,"peppers.bmp");
prelTitlu(&hardei);

printf("Waterfall\n");
cevaAfisari(pozaMea);
printf("Catelus\n");
cevaAfisari(puppy);
printf("Steag\n");
cevaAfisari(steag);
printf("Ardei\n");
cevaAfisari(hardei);

destroyElm(&pozaMea);
destroyElm(&puppy);
destroyElm(&steag);
destroyElm(&hardei);

return 0;
}
