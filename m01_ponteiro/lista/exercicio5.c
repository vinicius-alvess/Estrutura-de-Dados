int main()
{

    float vfat[3];
    int i, *p;
    p = &vfat;

    for (i = 0; i < 3; i++)
    {
        printf("Faturamento Empresa %d: ", i + 1);
        scanf("%f", &vfat[i]);
        printf("\n");
    }
    for (i = 2; i >= 0; i--)
    {
        printf("Faturamento Empresa %d: %lf, Endereco: %x", i + 1, vfat[i], (p + i));
        printf("\n");
    }

    return 0;
}