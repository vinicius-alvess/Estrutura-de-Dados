#include <stdio.h>
#include <stdlib.h>

FILE *Arquivo_AbreLeitura(char *PNomeArquivo)
{
    return fopen(PNomeArquivo, "r");
}

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

int main()
{
    char NomeArq[30] = "";
    FILE *ArqDici = NULL;
    FILE *TRA = NULL;
    FILE *TRB = NULL;
    FILE *Saida = NULL;
    char opcao;

    do
    {
        printf("\n################## BAG-OF-WORDS ##################");
        printf("\n");
        printf("\nD - Ler o arquivo de dicionário");
        printf("\nA - Ler arquivo contendo texto de referência A");
        printf("\nB - Ler um arquivo contendo texto de referência B");
        printf("\nT - Exibir BOWs de TRA e TRB");
        printf("\nt - Mostrar similaridade entre os dois textos");
        printf("\nS - Sair");

        printf("\nOpção: ");
        scanf("\n%c", &opcao);

        switch (opcao)
        {
        case 'D':
            printf("\nArquivo de dicionário: ");
            scanf("%s", NomeArq);

            if (ArqDici != NULL)
                fclose(ArqDici);

            ArqDici = Arquivo_AbreLeitura(NomeArq);
            if (ArqDici == NULL)
            {
                printf("\nErro 1: Arquivo de dicionario não pode ser aberto\n");
                break;
            }
            printf("%s aberto!!!\n", NomeArq);
            break;

        case 'A':
            printf("\nArquivo de referência A: ");
            scanf("%s", NomeArq);

            if (TRA != NULL)
                fclose(TRA);

            TRA = Arquivo_AbreLeitura(NomeArq);
            if (TRA == NULL)
            {
                printf("\nErro 1: Arquivo de dicionario não pode ser aberto\n");
                break;
            }
            printf("%s aberto!!!\n", NomeArq);
            break;

        case 'B':
            printf("\nArquivo de referência B: ");
            scanf("%s", NomeArq);

            if (TRB != NULL)
                fclose(TRB);

            TRB = Arquivo_AbreLeitura(NomeArq);
            if (TRB == NULL)
            {
                printf("\nErro 1: Arquivo de dicionario não pode ser aberto\n");
                break;
            }
            printf("%s aberto!!!\n", NomeArq);
            break;

        case 'T':
            //Exibir BOWs de TRA e TRB
            break;

        case 't':
            printf("\nSimilaridade:");
            break;

        case 'S':
            break;

        default:
            printf("\nOpção inválida!\n");
            break;
        }
    } while (opcao != 'S');

    printf("\n\n ----- Sistema Encerrado ----- \n\n");

    return 0;
}