#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BibBuscas.c"

int main()
{

    char fileName[30] = "";
    FILE *pPainelCovid = NULL;

    char opcao;

    do
    {
        printf("\n################## Painel ##################");
        printf("\n");
        printf("\nA - Ler o arquivo de Painel de Covid");
        printf("\nS - Sair");

        printf("\nOpção: ");
        scanf("\n%c", &opcao);

        switch (opcao)
        {
        case 'A':
            printf("\nArquivo de Painel de Covid: ");
            scanf("%s", fileName);

            if (pPainelCovid != NULL)
            {
                fclose(pPainelCovid);
            }

            pPainelCovid = fopen(fileName, "r");

            if (pPainelCovid == NULL)
            {
                printf("\nNao foi possivel abrir o Painel de Covid BR\n");
            }
            else
            {
                printf("\nPainel de Covid BR aberto com sucesso!\n");
                organiza(pPainelCovid);
                break;
            }

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
