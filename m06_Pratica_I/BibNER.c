//
//  BibNER.c
//  Arquivos
//
//  Created by Nilton Correia da Silva on 02/03/21.
//

#include "BibNER.h"
#include <string.h> //necessário para strcpy
#include <stdlib.h> //necessário para malloc
#include <ctype.h>  //necessário para tolower
#include "BibArquivos.h"

int ehfinalpalavra(char pcar)
{
    int pind, pehfim = 0;
    char FIMPAL[6] = {'\n', ' ', '.', ',', ';', ':'};
    int TAMFIMPAL = 6;

    for (pind = 0; pind < TAMFIMPAL; pind++)
    {
        if (pcar == FIMPAL[pind])
        {
            pehfim = 1;
            break;
        }
    }
    return pehfim;
}

int palavrasiguais(char *ppal1, char *ppal2)
{
    int ppos = 0, pehigual = 1;
    while ((!ehfinalpalavra(ppal1[ppos])) && (!ehfinalpalavra(ppal2[ppos])))
    {
        if (tolower(ppal1[ppos]) != tolower(ppal2[ppos]))
        {
            pehigual = 0;
            break;
        }
        ppos++;
    }
    return pehigual;
}

char *NER_TokenDados(FILE *pArqToken, int *pTamTermos)
{
    char ptemp[TAMPAL];
    char *ptoken = NULL;
    fseek(pArqToken, 0, SEEK_SET);
    if (fscanf(pArqToken, "%d %s", pTamTermos, ptemp) == 2)
    {
        ptoken = malloc(strlen(ptemp) + 1);
        strcpy(ptoken, ptemp);
    }
    return ptoken;
}

FILE *NER_Substitui(FILE *pArqTexto, FILE *pArqToken, char *pNomeSaida)
{
    char *ptokenID;
    int ptamtermos;
    long int piniciotermos;
    char *ptermo, ppalavra[TAMPAL];
    FILE *psaida;
    int pacheitermo;
    //Extrair especificação to token:
    ptokenID = NER_TokenDados(pArqToken, &ptamtermos);
    ptamtermos += 1;                  //Espaço para '\n'
    piniciotermos = ftell(pArqToken); //posição do arquivo onde inicia os termos
    ptermo = malloc(ptamtermos);      //Buffer para armazenar termos do arquivo de token
                                      //Aplicar substituições e gravar no arquivo de saída.
    psaida = Arquivo_Novo(pNomeSaida);
    fseek(pArqTexto, 0, SEEK_SET);

    while (1)
    {
        memset(ppalavra, '\n', TAMPAL);
        if (!Arquivo_ProximaPalavra(pArqTexto, ppalavra))
        {
            printf("\nnão leu %s", ppalavra);
            break;
        }

        fseek(pArqToken, piniciotermos, SEEK_SET);
        pacheitermo = 0;
        while (1)
        {
            memset(ptermo, '\n', ptamtermos);
            if (!Arquivo_ProximaPalavra(pArqToken, ptermo))
            {
                printf("\nnão leu %s", ppalavra);
                break;
            }
            printf("\nProcurando %s", ptermo);
            if (palavrasiguais(ppalavra, ptermo))
            {
                pacheitermo = 1;
                break;
            }
        }
        if (pacheitermo)
        {
            fputs(ptokenID, psaida);
            fputs(" ", psaida);
        }
        else
        {
            fputs(ppalavra, psaida);
            fputs(" ", psaida);
        }
    }

    fclose(psaida);
    free(ptermo);
    psaida = Arquivo_AbreLeitura(pNomeSaida);
    return psaida;
}
