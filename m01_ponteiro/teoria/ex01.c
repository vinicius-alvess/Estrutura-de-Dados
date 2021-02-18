#include <stdio.h>

int main(void)
{
    int n = 75;
    int *ponteiro_n;
    ponteiro_n = &n;
    printf("O valor da variavel n e %d e seu endereco e %x\n", n, &n);
    printf("O endereco apontado por ponteiro_n e %x e seu teor e %d\n", ponteiro_n, *ponteiro_n);
    *ponteiro_n = 100;
    printf("O valor da variavel n e %d e seu endereco e %x\n", n, &n);
    printf("O endereco apontado por ponteiro_n e %x e seu teor e %d\n", ponteiro_n, *ponteiro_n);

    return 0;
}