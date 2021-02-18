int main()
{
    int y, *p, x; // 2 inteiros e ponteiro p/ inteiro
    y = 0;
    p = &y;                // Aponta para o enderço de y e *p = 0
    x = *p;                // x = valor do ponteiro, x = 0
    x = 4;                 // x = 4
    (*p)++;                // *p = *p + 1 = 0 + 1, *p = 1
    x--;                   // x = 3
    (*p) += x;             // *p = *p + x = 1 + 3, *p = 4
    printf("y = %d\n", y); // y = 4

    return (0);
}