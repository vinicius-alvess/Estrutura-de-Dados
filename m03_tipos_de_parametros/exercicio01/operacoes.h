#ifndef operacoes
#define operacoes
#include <stdio.h>

float soma(float *, float *);
float diferenca(float *, float *);
float produto(float *, float *);

#endif

float soma(float *n, float *nn)
{
    float soma;

    soma = *n + *nn;

    return soma;
}

float diferenca(float *n, float *nn)
{
    float diferenca;

    diferenca = *n - *nn;

    return diferenca;
}

float produto(float *n, float *nn)
{
    float produto;

    produto = (*n) * (*nn);

    return produto;
}
