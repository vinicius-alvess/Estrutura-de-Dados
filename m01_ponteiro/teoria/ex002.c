#include <stdio.h>

int main(void)
{
    int lista[5] = {10, 20, 30, 40};

    //Mostra o endereço do primeiro elemento da lista e seu valor
    printf("O endereco apontado por lista e %x e seu valor e %d\n", lista, *lista);
    //Mostra o endereço do segundo elemento da lista e seu valor
    printf("O endereco apontado por lista e %x e seu valor e %d\n", lista + 1, *(lista + 1));
    //Mostra o endereço do terceiro elemento da lista e seu valor
    printf("O endereco apontado por lista e %x e seu valor e %d\n", lista + 2, *(lista + 2));
    //Mostra o endereço do quarto elemento da lista e seu valor
    printf("O endereco apontado por lista e %x e seu valor e %d\n", lista + 3, *(lista + 3));

    return 0;
}