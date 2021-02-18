#include <stdio.h>

int main(void)
{
    int *ptr, lista[5] = {10, 20, 30, 40, 50};

    ptr = lista;
    printf("O valor do conteudo de ptr e %d\n", *ptr);
    ptr = ptr + 1;
    printf("O valor do conteudo de ptr e %d\n", *ptr);
    ptr = ptr + 3;
    printf("O valor do conteudo de ptr e %d\n", *ptr);
    ptr = ptr - 1;
    printf("O valor do conteudo de ptr e %d\n", *ptr);
    ptr = ptr - 1;
    printf("O valor do conteudo de ptr e %d\n", *ptr);

    return 0;
}