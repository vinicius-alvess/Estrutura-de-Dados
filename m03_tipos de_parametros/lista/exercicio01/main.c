/*Fazer uma função que retorna a soma, a diferença e o produto entre dois números.*/
#include "operacoes.h"
#include <stdio.h>
/*
        OUTRA FORMA DE FAZER
void operacoes(float *n, float *nn)
{
    float soma, diferenca, produto;

    soma = *n + *nn;
    diferenca = *n - *nn;
    produto = (*n) * (*nn);

    printf("Soma = %.4f\n", soma);
    printf("Diferenca =%.4f\n", diferenca);
    printf("Produto = %.4f\n", produto);
}*/

int main()
{
    float n, nn;

    printf("Digite um valor:\n");
    scanf("%f", &n);

    printf("Digite outro valor:\n");
    scanf("%f", &nn);

    //esses printfs sao necesssarios apenas se estivermos usando a biblioteca
    printf("Soma = %.3f\n", soma(&n, &nn));
    printf("Diferenca = %.3f\n", diferenca(&n, &nn));
    printf("Produto = %.3f\n", produto(&n, &nn));

    return 0;
}
