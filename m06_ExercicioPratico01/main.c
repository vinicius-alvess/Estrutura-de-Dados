//
//  main.c
//  Arquivos
//
//  Created by Nilton Correia da Silva on 27/02/21.
//

#include <stdio.h>
#include "BibArquivos.h"

int main()
{
    char NomeArq[30] = "";
    FILE *AR = NULL;
    FILE *Token = NULL;
    FILE *Saida = NULL;
    char popc = '0';
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
            printf("Arquivo de Saída: ");
            scanf("%s", NomeArq);
            if (Saida != NULL)
                fclose(Saida);
            Saida = Arquivo_Novo(NomeArq);
            if (Saida == NULL)
            {
                printf("Erro 3: Arquivo de Saída não pode ser criado\n");
            }
            //Faça a chamada às funções que vc criou para aplicar a Tokenização aqui.
            //Ao final: Feche o arquivo de saída. Abra-o em modo de leitura e mostre seu
            //conteúdo.

            printf("%s gerado!!!\n", NomeArq);
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
