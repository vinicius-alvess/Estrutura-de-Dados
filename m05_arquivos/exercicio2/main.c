#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file;

    file = fopen("string.txt", "a");

    if (file == NULL)
    {
        printf("O arquivo nao pode ser aberto.\n");
        exit(0);
    }

    //passar uma string para meu arquivo
    fprintf(file, "Primeira linha\n");

    //passar um vetor para um arquivo
    char frase[] = "Segunda linha\n";
    fputs(frase, file);

    // passar apenas 1 caracter
    char caractere = '3';
    fputc(caractere, file);

    fclose(file);

    return 0;
}
