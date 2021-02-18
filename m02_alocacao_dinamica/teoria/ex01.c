#include <stdlib.h>

int main()
{
    int *Vet1, *Vet2;                        //Declaração dos ponteiros
    Vet1 = (int *)malloc(100 * sizeof(int)); //Alocação de memória
    Vet2 = (int *)calloc(100, sizeof(int));  //Alocação de memória
    for (int ind = 0; ind < 100; ind++)
    {
        printf("Vet1[%d]: %d, Vet2[%d]: %d\n", ind, Vet1[ind], ind, Vet2[ind]);
    }
    free(Vet1); //Desalocação de memória
    free(Vet2); //Desalocação de memória
    return 0;
}