//
//  BibNER.h
//  Arquivos
//
//  Created by Nilton Correia da Silva on 02/03/21.
//

#ifndef BibNER_h
#define BibNER_h

#include <stdio.h>
#define TAMPAL 35 //Tamanho máximo de uma palavra

/*
 Parâmetros de entrada:
 pTexto: Ponteiro para o início de um arquivo texto
 pTermo: Termo a ser substituído pelo Token (pToken)
 
 Parâmetros de saída:
 Retorna a quantidade de substituições realizadas.
 */
int ehfinalpalavra(char pcar);
char *NER_TokenDados(FILE *pArqToken, int *pTamTermos);
FILE *NER_Substitui(FILE *pArqTexto, FILE *pArqToken, char *pNomeSaida);

#endif /* BibNER_h */
