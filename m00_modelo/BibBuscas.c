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

// Funções
