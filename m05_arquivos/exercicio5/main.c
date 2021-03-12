#include <stdio.h>

int main()
{
    char x[] = "Coxinha";

    putc('a', stdout);

    FILE *file;

    file = fopen("arquivo.txt", "r");

    int i = 0;

    while ((x[i] = fgetc(stdin)) != '\n')
    {
        ++i;
    }

    x[i] = '\0';

    printf("%s", x);

    return 0;
}