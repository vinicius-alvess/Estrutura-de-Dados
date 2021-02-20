#ifndef analisa
#define analisa

void analisaV(int *vetor, int tamanho, float *media, int *menor, int *maior);

#endif

void analisaV(int *vetor, int tamanho, float *media, int *menor, int *maior)
{
    int i;
    float soma = 0.0;

    for (i = 0; i < tamanho; i++)
    {
        soma += vetor[i];
    }

    *media = soma / (float)tamanho;

    int testa_menor = 0, testa_maior = 9999;

    for (i = 0; i < tamanho; i++)
    {
        if (testa_menor < vetor[i])
        {
            testa_menor = vetor[i];
        }
    }

    *menor = testa_menor;

    for (i = 0; i < tamanho; i++)
    {
        if (testa_maior > vetor[i])
        {
            testa_maior = vetor[i];
        }
    }

    *maior = testa_maior;
}