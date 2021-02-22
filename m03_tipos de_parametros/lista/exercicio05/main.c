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
#define limite 100 // limite de cadastros

int n_cadastros = 0;
long int cep[limite];
char nome[limite][30], endereco[limite][100], fone[limite][10];

void cadastro();

void cadastro()
{
    char *pnome, *pendereco, *pfone, *pcep;
    static int n_cadastro = 0;

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
    scanf("%s", &fone[n_cadastro]);
    printf("\n");

    pfone = &fone[n_cadastro];

    //CEP
    printf("CEP: ");
    scanf("%ld", &cep[n_cadastro]);
    printf("\n");

    pcep = &cep[n_cadastro];

    n_cadastro++;
}

int main()
{
    char opcao;

    printf("a. Entrar um novo nome na agenda.\n");
    printf("b. Imprimir na tela os dados de todas as pessoas cadastradas.\n");
    printf("c. Imprimir a lista de nomes cadastrados que comecem por uma letra informada pelo usuario.\n");
    printf("d. Fim\n");

    scanf("%c", &opcao);

    switch (opcao)
    {
    case 'a':
        cadastro();
        break;

    case 'b':
        break;

    case 'c':
        break;

    case 'd':
        printf("Tchau, espero te ver logo!\n");
        break;

    default:
        printf("Escolha uma opcao valida!\n");
        break;
    }

    printf("\n\n\n\n%s", nome[0]);

    return 0;
}