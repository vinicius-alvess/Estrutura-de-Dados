#include <stdio.h>

int main(void)
{
    int *ptr, lista[5] = {10, 20, 30, 40, 50};
    ptr = lista;
    for (int ind = 0; ind < 5; ind++)
    {
        printf("Indice: %d Lista: %d, PTR: %d\n", ind, lista[ind], ptr[ind]);
    }

    return 0;
}