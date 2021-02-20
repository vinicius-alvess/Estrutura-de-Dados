/*

Fazer um algoritmo que:

a. Leia n valores numéricos e os armazene num arranjo unidimensional v. O valor de n também deve ser lido.
b. Calcule e exiba o valor da série:
𝑆 = somatorio (i/𝑣i) de i=1 ate n
Onde 𝑣i é o i-ésimo valor armazenado na variável v.
c. Calcule e exiba quantos termos da série têm o numerador inferior ao denominador.

*/

#include "serie.h"
#include <stdio.h>

int main()
{

    int i, n, qtde;

    printf("Quantos valores voce quer armazenar?\n");
    scanf("%d", &n);

    float *valores, soma;
    valores = (float *)calloc(n, sizeof(float));

    printf("Digite os valores\n");
    for (i = 0; i < n; i++)
    {
        scanf("%f", &valores[i]);
    }

    soma = calcular_serie(valores, n);
    qtde = denominador_maior(valores, n);

    printf("Serie = %.2f\n", soma);
    printf("Quantidade de termos da serie com numerador inferior ao denominador = %d\n", qtde);

    return 0;
}
