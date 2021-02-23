/*
Construir um programa que implemente uma agenda eletrônica. O programa deve ter um menu com as
seguintes opções:
a. Entrar um novo nome na agenda.
b. Imprimir na tela os dados de todas as pessoas cadastradas.
c. Imprimir a lista de nomes cadastrados que comecem por uma letra informada pelo usuário.
d. Fim
Cada entrada da agenda deve ter os seguintes campos:
- char nome[30];
- char endereco[100];
- char fone[10];
- long int CEP;
Obs: a agenda deve ter capacidade para 100 entradas.
*/

#include <stdio.h>
#define limite 100 // constante limite de cadastros

//VARIAVEIS GLOBAIS
char nome[limite][30], endereco[limite][100];
long int cep[limite], fone[limite];
static int n_cadastro = 0;

//FUNCOES
void cadastro();
void imprime_dados_cadastrados();
void pesquisa_imprime();

void cadastro()
{
    char *pnome, *pendereco, *pfone, *pcep;

    //NOME
    printf("Nome: ");
    scanf("%s", &nome[n_cadastro]);
    printf("\n");

    pnome = &nome[n_cadastro];

    //ENDERECO
    printf("Endereco: ");
    scanf("%s", &endereco[n_cadastro]);
    printf("\n");

    pendereco = &endereco[n_cadastro];

    //TELEFONE
    printf("Telefone: ");
    scanf("%ld", &fone[n_cadastro]);
    printf("\n");

    pfone = &fone[n_cadastro];

    //CEP
    printf("CEP: ");
    scanf("%ld", &cep[n_cadastro]);
    printf("\n");

    pcep = &cep[n_cadastro];

    n_cadastro++;
}

void imprime_dados_cadastrados()
{
    int i;

    printf("Cadastros:\n\n");
    printf("------------------------------\n");

    for (i = 0; i < n_cadastro; i++)
    {
        printf("Nome: %s\n", nome[i]);
        printf("Endereco: %s\n", endereco[i]);
        printf("Telefone: %ld\n", fone[i]);
        printf("CEP: %ld\n", cep[i]);
        printf("------------------------------\n\n");
    }
}

void pesquisa_imprime()
{
    int i, j = 0;
    char pesquisa;

    printf("Pesquisar pela letra: \n");
    scanf("%s", &pesquisa);
    printf("\n");

    for (i = 0; i < n_cadastro; i++)
    {
        if (pesquisa == nome[i][0])
        {
            printf("Nome: %s\n", nome[i]);
            printf("Endereco: %s\n", endereco[i]);
            printf("Telefone: %ld\n", fone[i]);
            printf("CEP: %ld\n", cep[i]);
            printf("------------------------------\n\n");
            j = 1;
        }
    }
    printf("\n");
    if (j == 0)
    {
        printf("Nao existe um nome cadastrado que comeca com essa letra\n\n");
    }
}

int main()
{
    int opcao;
    do
    {
        printf("1. Entrar um novo nome na agenda.\n");
        printf("2. Imprimir na tela os dados de todas as pessoas cadastradas.\n");
        printf("3. Imprimir a lista de nomes cadastrados que comecem por uma letra informada pelo usuario.\n");
        printf("4. Fim\n");
        printf("\n");
        printf("Escolha uma opcao: \n");
        scanf("%d", &opcao);
        printf("\n");

        switch (opcao)
        {
        case 1:
            cadastro();
            break;

        case 2:
            imprime_dados_cadastrados();
            break;

        case 3:
            pesquisa_imprime();
            break;

        case 4:
            printf("\nEspero te ver logo!\n\n");
            break;

        default:
            printf("\nEscolha uma opcao valida!\n\n");
            break;
        }
    } while (opcao != 4);

    return 0;
}