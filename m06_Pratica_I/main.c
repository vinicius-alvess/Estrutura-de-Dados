
#include <stdio.h>
#include "BibArquivos.h"
#include "BibNER.h"
#include <stdlib.h> //Necessário para free()

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

FILE *Arquivo_AbreLeitura(char *PNomeArquivo)
{
    return fopen(PNomeArquivo, "r");
}

FILE *Arquivo_Novo(char *PNomeArquivo)
{
    return fopen(PNomeArquivo, "w");
}

int Arquivo_MostraConteudo(FILE *parq)
{
    int c;
    if (parq == NULL)
        return 0; //Erro: ponteiro não apontado.
    while (1)
    {
        c = fgetc(parq);
        if (feof(parq))
        {
            break;
        }
        printf("%c", c);
    }
    return 1;
}

int Arquivo_ProximaPalavra(FILE *parq, char *ppalavra)
{
    if (fscanf(parq, "%s", ppalavra) < 1)
    {
        return 0;
    }
    return 1;
}

int main(int argc, const char *argv[])
{
    char NomeArq[30] = "";

    FILE *AR = NULL;    //Arquivo de texto de referência
    FILE *Token = NULL; //Arquivo com informações dos tokens
    FILE *Saida = NULL; //Arquivo contendo resultado
    char popc = '0';
    //Informações contidas no arquivo de Token:
    char *TokenID = NULL;
    int TamanhoTermos;

    while (popc != 'S')
    {
        printf("\n################## ENTIDADES NOMEADAS ##################");
        printf("\n");
        printf("\nR - Abrir Arquivo de Referência");
        printf("\nT - Abrir Arquivo de Especificação de Token");
        printf("\nA - Aplicar Tokenização");
        printf("\nr - Exibir Arquivo de Referência");
        printf("\nt - Exibir Arquivo de Especificação de Token");
        printf("\nS - Sair");
        printf("\nOpção: ");
        scanf("\n%c", &popc);
        switch (popc)
        {
        case 'R':
            printf("Arquivo de Referência: ");
            scanf("%s", NomeArq);
            if (AR != NULL)
                fclose(AR);
            AR = Arquivo_AbreLeitura(NomeArq);
            if (AR == NULL)
            {
                printf("Erro 1: Arquivo de Referência não pode ser aberto\n");
            }
            else
                printf("%s aberto!!!\n", NomeArq);
            break;
        case 'T':
            printf("Arquivo de Especificação de Token: ");
            scanf("%s", NomeArq);
            if (Token != NULL)
                fclose(Token);
            Token = Arquivo_AbreLeitura(NomeArq);
            if (Token == NULL)
            {
                printf("Erro 2: Arquivo de Especificação de Token não pode ser aberto\n");
                TamanhoTermos = 0;
                if (TokenID != NULL)
                    free(TokenID);
            }
            else
            {
                TokenID = NER_TokenDados(Token, &TamanhoTermos);
                printf("%d %s %lu\n", TamanhoTermos, TokenID, sizeof(TokenID));
            }
            break;
        case 'r':
            if (!Arquivo_MostraConteudo(AR))
            {
                printf("Arquivo de Referência não está carregado\n");
            }
            break;
        case 't':
            if (!Arquivo_MostraConteudo(Token))
            {
                printf("Arquivo de Especificação de Token não está carregado\n");
            }
            break;
        case 'A':
            if ((AR == NULL) || (Token == NULL))
            {
                printf("Carregue os arquivo de Texto de Referência e de Especificação de Token!!!\n");
                break;
            }

            printf("Arquivo de Saída: ");
            scanf("%s", NomeArq);
            if (Saida != NULL)
                fclose(Saida);

            //Faça a chamada às funções que vc criou para aplicar a Tokenização aqui.
            //Ao final: Feche o arquivo de saída. Abra-o em modo de leitura e mostre seu
            //conteúdo.

            Saida = NER_Substitui(AR, Token, NomeArq);
            if (!Arquivo_MostraConteudo(Saida))
            {
                printf("Erro 3: Arquivo de Saída não pode ser criado\n");
            }
            else
                printf("\n%s gerado!!!\n", NomeArq);

            break;

        case 'S':
            break;
        }
        if (popc == 'S')
            break;
    }

    fclose(AR);
    fclose(Token);
    fclose(Saida);
    printf("\n\n ----- Sistema Encerrado ----- \n\n");

    return 0;
}
