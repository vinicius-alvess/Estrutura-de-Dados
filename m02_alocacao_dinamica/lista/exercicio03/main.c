#include <stdio.h>

char add_caracter_final(int, int, char *, char);
char exclui_caracter(int, int, char *, char);

char add_caracter_final(int ptammax, int pqtde, char *pvetcar, char add)
{
    *(pvetcar + pqtde) = add;

    return pvetcar;
}

char exclui_caracter(int ptammax, int pqtde, char *pvetcar, char exclui)
{
    int i, endereco;

    for (i = 0; i < ptammax; i++)
    {
        if (*(pvetcar + i) == exclui)
        {
            endereco = i;
            i = ptammax;
        }
    }

    for (i = endereco; i < ptammax; i++)
    {
        *(pvetcar + i) = *(pvetcar + i + 1);
    }

    return pvetcar;
}

int main(void)
{
    int i, ptammax = 10, pqtde = 5;
    char pvetcar[ptammax];

    add_caracter_final(ptammax, pqtde, &pvetcar, 'v');

    printf("\n***************Adiciona***************\n\n");

    for (i = 0; i < ptammax; i++)
    {
        printf("elemento %d = %c\n", i, pvetcar[i]);
    }

    printf("\n\n***************Exclui***************\n\n");

    exclui_caracter(ptammax, pqtde, &pvetcar, 'v');

    for (i = 0; i < ptammax; i++)
    {
        printf("elemento %d = %c\n", i, pvetcar[i]);
    }

    return 0;
}
