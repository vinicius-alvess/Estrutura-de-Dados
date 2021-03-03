#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp;
    char ch;

    fp = fopen("filePrint.txt", "r"); // r so para a leitura
    if (fp == NULL)
    {
        printf("Banco de dados de palavras nao disponivel\n\n");
        exit(1);
    }
    while (1)
    {
        ch = fgetc(fp);
        if (ch == EOF)
        {
            break;
        }
        printf("%c", ch);
    }

    fclose(fp);
    return 0;
}