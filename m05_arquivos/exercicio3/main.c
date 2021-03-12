#include <stdio.h>

void copiar_conteudo(FILE *file1, FILE *file2)
{
    char ch;

    while (1)
    {
        ch = fgetc(file1);

        if (ch == EOF)
        {
            break;
        }

        fputc(ch, file2);
    }
}

int main()
{
    void copiar_conteudo(FILE * file1, FILE * file2);

    FILE *file1 = fopen("arquivo.txt", "r");

    if (file1 == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        exit(0);
    }

    FILE *file2 = fopen("arquivo2.txt", "w");

    copiar_conteudo(file1, file2);

    fclose(file1);
    fclose(file2);

    return 0;
}
