//  BibBuscas.c
//  EDABuscaSeqBin

#include "BibBuscas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long int ContaLinhas(FILE *arquivo)
{
    char ch;
    long int linhas = 0;

    while (1)
    {
        ch = fgetc(arquivo);

        if (ch == EOF)
        {
            break;
        }
        else if (ch == '\n')
        {
            linhas++;
            // A soma vai da exatamente o numero de linhas de dados, pois esse if vai contar a primeira linha que é a linha com o nome das colunas (QUE NAO DEVERIA SER CONTADA), porem nao vai contar a ultima linha de dados, pois esta não possui um '\n' no final e sim um EOF.
        }
    }

    return linhas;
}

void organiza(FILE *arquivo)
{
    long int linhas = ContaLinhas(arquivo);

    char codg[linhas][10];
    int contCodg = 0;

    char regiao[linhas][10];
    int contRegiao = 0;

    char uf[linhas][10];
    int contUf = 0;

    char data[linhas][10];
    int contData = 0;

    int dados[linhas][6][10];

    int ponto = 0;
    int i = 0;

    char ch;

    while (1)
    {
        ch = fgetc(arquivo);

        if (ch == EOF)
        {
            break;
        }
        else if (ch == ';')
        {
            i = 0;
            ponto++;
        }
        printf("bo");

        switch (ponto)
        {
        case 0:

            codg[contCodg][i] = ch;
            contCodg++;
            i++;
            break;

        case 1:
            regiao[contRegiao][i] = ch;
            contRegiao++;
            i++;
            break;

        case 2:
            uf[contUf][i] = ch;
            contUf++;
            i++;
            break;

        case 3:
            data[contData][i] = ch;
            contData++;
            i++;
            break;

        default:

            break;
        }
    }

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%c", codg[i][j]);
        }
        printf("\n\n");
    }
}