//  main.c
//  EDABuscaSeqBin

#include <stdio.h>
#include <stdlib.h>
#include "BibBuscas.c"

int main()
{
    int pind, Valor;
    int *Aleatorio = NULL, pTamAleatorio = 0;
    int *Ordenado = NULL, pTamOrdenado = 0;

    char popc = '0';

    while (popc != 'S')
    {
        printf("\n################## BUSCA SEQUENCIAL E BINÁRIA ##################");
        printf("\n");
        printf("\nA - Gerar Valores Aleatórios");
        printf("\nB - Gerar Valores Ordenados");

        printf("\nS - Sair");
        printf("\nOpção: ");
        scanf("\n%c", &popc);

        switch (popc)
        {
        case 'A':
            if (pTamAleatorio > 0)
                free(Aleatorio);

            printf("Tamanho do Vetor: ");
            scanf("%d", &pTamAleatorio);

            Aleatorio = (int *)malloc(pTamAleatorio * sizeof(int));

            if (Aleatorio != NULL)
            {
                GeraAleatorioInt(Aleatorio, pTamAleatorio);

                for (pind = 0; pind < pTamAleatorio; pind++)
                    printf("\nValor %d: %d", pind, Aleatorio[pind]);
            }
            else
                printf("\nErro 1: Não foi possível alocar o vetor!!!\n");
            break;

        case 'B':
            if (pTamOrdenado > 0)
                free(Ordenado);

            printf("Tamanho do Vetor: ");
            scanf("%d", &pTamOrdenado);

            Ordenado = (int *)malloc(pTamOrdenado * sizeof(int));

            if (Ordenado != NULL)
            {
                GeraOrdenadoInt(Ordenado, pTamOrdenado);
                for (pind = 0; pind < pTamOrdenado; pind++)
                    printf("\nValor %d: %d", pind, Ordenado[pind]);
            }
            else
                printf("\nErro 1: Não foi possível alocar o vetor!!!\n");
            break;

        case 'S':
            break;
        }
        if (popc == 'S')
            break;
    }

    //Liberar memória
    if (pTamAleatorio > 0)
        free(Aleatorio);

    printf("\n\n ----- Sistema Encerrado ----- \n\n");

    return 0;
}