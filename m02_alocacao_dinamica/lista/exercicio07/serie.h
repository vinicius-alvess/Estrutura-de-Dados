#ifndef serie
#define serie
#include <stdio.h>

float calcular_serie(float *, int);
int denominador_maior(float *valores, int n); //Calcula quantos termos da série têm o numerador inferior ao denominador.

#endif

float calcular_serie(float *valores, int n)
{
    int i;
    float soma = 0.0;

    for (i = 0; i < n; i++)
    {
        soma += (i + 1.0) / valores[i];
    }

    return soma;
}

int denominador_maior(float *valores, int n)
{
    int i, soma = 0;

    for (i = 0; i < n; i++)
    {
        if ((i + 1) < valores[i])
        {
            soma++;
        }
    }

    return soma;
}