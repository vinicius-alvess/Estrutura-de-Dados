#ifndef biblioteca_EIgual
#define biblioteca_EIgual
#include <stdio.h>

int EIgual(int *, int *, int, int);

#endif

int EIgual(int *vet1, int *vet2, int tamanhovet1, int tamanhovet2)
{
    if (tamanhovet1 != tamanhovet2)
    {
        return 0; // vetores sao diferentes! --> '0'
    }

    int i, igual = 1;
    for (i = 0; i < tamanhovet1; i++)
    {
        if ((vet1[i]) != (vet2[i]))
        {
            igual = 0;
            break;
        }
    }
    return igual;
}
