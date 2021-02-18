#include <stdio.h>

char add_caracter_final(int, int, char *, char);

char add_caracter_final(int ptammax, int pqtde, char *pvetcar, char add)
{
    if (pqtde < ptammax)
    {
        *(pvetcar + pqtde) = add;
         printf("\nVerdadeiro\n");

    } else
    {
        printf("\nFalso\n");
    }

    return pvetcar;
}


int main(void)
{
    int i, ptammax = 10, pqtde = 10;
    char pvetcar[ptammax];

    add_caracter_final(ptammax, pqtde, &pvetcar, 'v');

    printf("\n***************Adiciona***************\n\n");

    for (i = 0; i < ptammax; i++)
    {
        printf("elemento %d = %c\n", i, pvetcar[i]);
    }

    return 0;
}
