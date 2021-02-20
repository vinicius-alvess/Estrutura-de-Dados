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

int total_de_cadastros = 0;
long int cep;
char nome[30], endereco[100], fone[10];

void cadastro();

void cadastro()
{
    char *pnome, *pendereco, *pfone, *pcep;

    //NOME
    printf("Nome: ");
    scanf("%s", &nome);
    printf("\n");

    pnome = &nome;

    //ENDERECO
    printf("Endereco: ");
    scanf("%s", &endereco);
    printf("\n");

    pendereco = &endereco;

    //TELEFONE
    printf("Telefone: ");
    scanf("%s", &fone);
    printf("\n");

    pfone = &fone;

    //CEP
    printf("CEP: ");
    scanf("%ld", &cep);
    printf("\n");

    pcep = &cep;

    total_de_cadastros++;
}

int main()
{
    char captura_opcao;
    printf("a. Entrar um novo nome na agenda.\n");
    printf("b. Imprimir na tela os dados de todas as pessoas cadastradas.\n");
    printf("c. Imprimir a lista de nomes cadastrados que comecem por uma letra informada pelo usuario.\n");
    printf("d. Fim\n");

    scanf("%c", &captura_opcao);

    switch (captura_opcao)
    {
    case 'a':
        cadastro();
        break;

    case 'b':
        break;

    case 'c':
        break;

    case 'd':
        printf("Tchau, espero te ver logo! :)");
        break;

    default:
        printf("Escolha uma opcao valida!");
        break;
    }
    //printf("%c", captura_opcao);

    //cadastro();

    //printf("\n\n\n\n%s", nome);

    return 0;
}