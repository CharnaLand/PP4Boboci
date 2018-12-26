#include <stdio.h>
#include <stdlib.h>
#include "Headere/Pixel3.h"
#include "Headere/PtImg.h"


int main()
{
PtImg pozaMea;

deschFisier(&pozaMea,"puppy.bmp");
prelTitlu(&pozaMea);

citireVector(&pozaMea);
imgEdit(&pozaMea,'R',150);
imgEdit(&pozaMea,'G',150);
imgEdit(&pozaMea,'B',150);
rebuildImg(&pozaMea,"zAltaPoza.bmp");

destroyElm(&pozaMea);

return 0;
}
