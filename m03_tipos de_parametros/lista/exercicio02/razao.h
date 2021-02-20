#ifndef razao
#define razao

int fun(float *, float *, float *);

#endif

int fun(float *n, float *nn, float *resposta)
{
    float res;
    if (*nn == 0)
    {
        return 0;
    }
    else
    {
        res = *n / *nn;
        *resposta = res;
        return 1;
    }
}