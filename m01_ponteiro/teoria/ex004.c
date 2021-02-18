#include <stdio.h>

int main(void)
{
    int lista[5] = {10, 20, 30, 40, 50};
    float media = 79.99;
    float *pmedia = &media;
    printf("Media: %f, Pmedia: %f", media, *pmedia);

    //Não faz sentido fazer isso, pois vai apontar para lixo
    //printf("Media: %f, Pmedia: %f", media, *(pmedia + 1));

    return 0;
}