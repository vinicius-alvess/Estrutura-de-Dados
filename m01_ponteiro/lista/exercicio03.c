int main(void)
{
    float vet[5] = {1.1, 2.2, 3.3, 4.4, 5.5}; // Vertor p/ float tamanho = 5 ocupação = 5
    float *f;                                 // Ponteiro p/ float
    int i;
    f = vet;                                          // Ponteiro f aponta para o vetor vet
    printf("contador/valor/valor/endereco/endereco"); // Imprime
    for (i = 0; i < 5; i++)
    {
        printf("\ni = %d", i);                    // i = 0
        printf(" vet[%d] = %.1f", i, vet[i]);     // vet[0] = 1.1
        printf(" *(f + %d) = %.1f", i, *(f + i)); // *(f + 0) = 1.1
        printf(" &vet[%d] = %X", i, &vet[i]);     // &vet[0] = 645460
        printf(" (f + %d) = %X", i, f + i);       // (f + 0) = 645460
    }
    return 0;
}