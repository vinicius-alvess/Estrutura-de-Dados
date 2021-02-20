#include "biblioteca.h"
#include <stdio.h>

int main()
{
    int *vet1, *vet2, taman1, taman2, teste;

    taman2 = 30;
    taman1 = 30;

    vet1 = (int *)calloc(taman1, sizeof(int));
    vet2 = (int *)calloc(taman2, sizeof(int));

    teste = EIgual(vet1, vet2, taman1, taman2);

    if (teste == 1)
    {
        printf("Sao iguais!\n");
    }
    else
    {
        printf("Nao sao iguais!\n");
    }

    free(vet1);
    free(vet2);

    return 0;
}
