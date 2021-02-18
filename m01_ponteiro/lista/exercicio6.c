int main()
{

    float vfat[3], *p;
    int i;
    p = &vfat;

    for (i = 0; i < 3; i++)
    {
        printf("Faturamento Empresa %d: ", i + 1);
        scanf("%f", &p[i]);
        printf("\n");
    }

    for (i = 2; i >= 0; i--)
    {
        printf("Faturamento Empresa %d: %lf, Endereco: %x", i + 1, *(p + i), (p + i));
        printf("\n");
    }

    return 0;
}