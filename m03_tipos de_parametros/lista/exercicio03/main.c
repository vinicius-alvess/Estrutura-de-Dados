/*
Fazer uma funcao que receba um vetor de números inteiros positivos como parâmetro e devolva:
a. A média dos valores do vetor;
b. O menor valor do vetor (sem considerar o último)
c. O maior valor do vetor
*/

#include "analisa.h"
#include <stdio.h>

int main()
{
    int i, j, *vetor, menor, maior;
    float media;

    vetor = (int *)calloc(100, sizeof(int));

    for (i = 0; i < 100; i++)
    {
        scanf("%d", &vetor[i]);
        if (vetor[i] == 0)
        {
            j = i;
            i = 100;
        }
    }

    for (i = 0; i < j; i++)
    {
        printf("%d ", vetor[i]);
    }

    printf("\n\n");

    analisaV(vetor, j, &media, &menor, &maior);

    printf("Media = %.2f\n", media);
    printf("Menor valor = %d\n", menor);
    printf("Maior valor = %d\n", maior);

    free(vetor);

    return 0;
}
