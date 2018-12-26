#include <stdio.h>
#include <stdlib.h>
#include "Headere/Pixel3.h"
#include "Headere/PtImg.h"


int main()
{
PtImg pozaMea;

deschFisier(&pozaMea,"unSteag.bmp");
prelTitlu(&pozaMea);

citireVector(&pozaMea);
rebuildImg(&pozaMea,"zAltaPoza.bmp");

destroyElm(&pozaMea);

return 0;
}
