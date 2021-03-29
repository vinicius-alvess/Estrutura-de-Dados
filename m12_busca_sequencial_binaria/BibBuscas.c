//  BibBuscas.c
//  EDABuscaSeqBin

#include "BibBuscas.h"
#include <stdlib.h>

void GeraAleatorioInt(int *pvetor, int pTAM)
{
    int pind, ppos, paux;
    for (pind = 0; pind < pTAM; pind++)
    {
        pvetor[pind] = pind + 1;
    }
    //Randomizando (Algoritmo de Fischer-Yates)
    for (pind = (pTAM - 1); pind > 0; pind--)
    {
        ppos = rand() % pind;
        if (ppos != pind)
        {
            paux = pvetor[pind];
            pvetor[pind] = pvetor[ppos];
            pvetor[ppos] = paux;
        }
    }
}

void GeraOrdenadoInt(int *pvetor, int pTAM)
{
    int pind;
    for (pind = 0; pind < pTAM; pind++)
    {
        pvetor[pind] = pind + 1;
    }
}

//Buscas:

int BuscaAleatoriaInt(int *pvetor, int pTAM, int pvalor)
{
    int i;
    for (i = 0; i < pTAM; i++)
    {
        if (pvetor[i] == pvalor)
        {
            return i;
        }
    }
    return -1;
}

int BuscaBinariaInt(int *pvetor, int pTAM, int pvalor)
{
    int esquerda = 0;
    int encontrado = 0;
    int meio;
    int direita = pTAM - 1;

    while (esquerda <= direita && encontrado == 0)
    {
        meio = (direita + esquerda) / 2;

        if (pvetor[meio] == pvalor)
        {
            encontrado = 1;
        }
        else if (pvalor < pvetor[meio])
        {
            direita = meio - 1;
        }
        else
        {
            esquerda = meio + 1;
        }
    }

    if (encontrado == 1)
    {
        return meio;
    }
    else
        return -1;
}

int BuscaBinaria_Recursiva(int *pvetor, int esquerda, int direita, int pvalor)
{
    int meio = (esquerda + direita) / 2;

    if (pvetor[meio] == pvalor)
    {
        return meio;
    }

    else if (esquerda == direita)
    {
        return -1;
    }

    else if (pvalor < pvetor[meio])
    {
        return BuscaBinaria_Recursiva(pvetor, esquerda, direita - 1, pvalor);
    }

    else
    {
        return BuscaBinaria_Recursiva(pvetor, esquerda + 1, direita, pvalor);
    }
}