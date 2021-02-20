#ifndef vetoresC
#define vetoresC
#include <stdio.h>

int CriarVetorInt(int);
float CriarVetorIFloat(int tamanho);

#endif // vetoresC

int CriarVetorInt(int tamanho)
{

    int *vetor;
    vetor = (int *)calloc(tamanho, sizeof(int));

    return vetor;
}