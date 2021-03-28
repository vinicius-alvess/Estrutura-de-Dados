//  BibBuscas.h
//  EDABuscaSeqBin

#ifndef BibBuscas_h
#define BibBuscas_h

#include <stdio.h>

//Geração de conjunto de dados
void GeraAleatorioInt(int *pvetor, int pTAM);
void GeraOrdenadoInt(int *pvetor, int pTAM);

//Buscas
int BuscaAleatoriaInt(int *pvetor, int pTAM, int pvalor);
int BuscaBinariaInt(int *pvetor, int pTAM, int pvalor);
int BuscaBinaria_Recursiva(int *pvetor, int esquerda, int direita, int pvalor);

#endif /* BibBuscas_h */
