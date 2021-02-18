int main(void)
{
    int i = 10, j = 20;
    int temp;
    int *p1, *p2;
    p1 = &i;                           // Ponteiro p1 aponta para endereço de i
    p2 = &j;                           // Ponteiro p2 aponta para endereço de j
    temp = *p1;                        // temp = 10
    *p1 = *p2;                         //*p1 = 20 i = 20
    *p2 = temp;                        //*p2 = 10  j = 10
    printf(" %d %d %d\n", i, j, temp); // Imprime 20 10 10
    return 0;
}