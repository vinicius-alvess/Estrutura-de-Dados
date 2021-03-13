#include <stdio.h>

void Limpar_Buffer(void);

void Limpar_Buffer(void)
{
    char c;

    while (1)
    {
        c = getchar();

        if (c != '\n')
        {
            break;
        }
        else if (c != EOF)
        {
            break;
        }
    }
}

int main()
{
    char a, b, c;

    a = getchar();
    Limpar_Buffer();

    b = getchar();
    Limpar_Buffer();

    c = getchar();
    Limpar_Buffer();

    printf("%c", a);
    printf("%c", b);
    printf("%c", c);

    return 0;
}
