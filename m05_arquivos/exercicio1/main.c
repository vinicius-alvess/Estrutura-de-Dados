/*Informa quantos caracter, espacos, tabs e newlines possui o arquivo en tempo "REAL" (5s)*/

#include <stdio.h>
#include <unistd.h>

int main()
{
    FILE *fp;
    char ch;

    while (1)
    {
        fp = fopen("txtexemplo.txt", "r");

        int space = 0, tabs = 0, lf = 0, chars = 0;

        while (1)
        {

            if (fp == NULL)
            {
                printf("\n\nBanco de dados nao disponivel\n\n");
                exit(1);
            }

            ch = fgetc(fp);

            if (ch == EOF)
            {
                break;
            }

            switch (ch)
            {
            case ' ':
                space++;
                break;

            case '\t':
                tabs++;
                break;

            case '\n':
                lf++;
                break;

            default:
                chars++;
                break;
            }
        }
        printf("Space %d\n", space);
        printf("Tabs %d\n", tabs);
        printf("LF %d\n", lf);
        printf("Chars %d\n\n", chars);

        fclose(fp);
        sleep(5);
    }

    return 0;
}