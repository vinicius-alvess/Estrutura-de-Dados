/*
Fazer uma função que retorna a razão entre dois números. A função deve retornar pelo comando return o
valor 1 se a operação foi possível e o valor 0 se a operação não foi possível (divisão por zero, por exemplo).
O resultado da divisão deve ser retonado por um parâmetro por referência.
*/

#include "razao.h"
#include <stdio.h>

int main()
{
    float n, nn, resposta;
    int retorno;

    printf("Digite um valor:\n");
    scanf("%f", &n);

    printf("Digite outro valor:\n");
    scanf("%f", &nn);

    retorno = fun(&n, &nn, &resposta);

    if (retorno == 0)
    {
        printf("Nao foi possivel fazer a razao!\n");
    }
    else if (retorno == 1)
    {
        printf("Foi possivel fazer a razao!\n");
        printf("o valor e: %.3f\n", resposta);
    }
    else
    {
        printf("Ocorreu um erro!\n");
    }

    return 0;
}
