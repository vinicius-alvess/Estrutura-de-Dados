#include <stdlib.h>
#include "vetoresC.h"

int main()
{
    int i = 0;
    int *p;
    p = CriarVetorInt(10);

    for (i = 0; i < 10; i++)
    {
        printf("Valor: %d\nEndereco %d\n", *(p + i), p + i);
    }


    return 0;
}