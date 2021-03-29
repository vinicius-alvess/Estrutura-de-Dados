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

// Ordenação

void InsertSort_Crescente(int *v, int n) //n é tamanho do vetor
{
    int deslocamentos = 0;
    int i = 0;
    int j = 1;
    int aux = 0;

    while (j < n)
    {
        aux = v[j];
        i = j - 1;

        while ((i >= 0) && (v[i] > aux))
        {
            v[i + 1] = v[i];
            deslocamentos++;
            i = i - 1;
        }

        v[i + 1] = aux;
        j = j + 1;
    }

    printf("\nForam realizados %d deslocamentos\n", deslocamentos);
}

void InsertSort_Decrescente(int *v, int n) //n é tamanho do vetor
{
    int deslocamentos = 0;
    int i = 0;
    int j = 1;
    int aux = 0;

    while (j < n)
    {
        aux = v[j];
        i = j - 1;

        while ((i >= 0) && (v[i] < aux))
        {
            v[i + 1] = v[i];
            deslocamentos++;
            i = i - 1;
        }

        v[i + 1] = aux;
        j = j + 1;
    }

    printf("\nForam realizados %d deslocamentos\n", deslocamentos);
}