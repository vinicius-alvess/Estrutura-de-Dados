//  BibBuscas.h
//  EDABuscaSeqBin

#ifndef BibBuscas_h
#define BibBuscas_h

#include <stdio.h>

//Geração de conjunto de dados
void GeraAleatorioInt(int *pvetor, int pTAM);
void GeraOrdenadoInt(int *pvetor, int pTAM);

//Ordenação
void InsertSort_Crescente(int *v, int n);
void InsertSort_Decrescente(int *v, int n);

#endif /* BibBuscas_h */
