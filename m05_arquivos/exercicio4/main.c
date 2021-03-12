#include <stdio.h>

int main()
{
    FILE *file;

    file = fopen("arquivo.txt", "r");

    char x[100];

    fgets(x, 100, file);
    printf("%s\n", x);

    freopen("arquivo1.txt", "r", file);

    fgets(x, 100, file);
    printf("%s\n", x);

    return 0;
}
