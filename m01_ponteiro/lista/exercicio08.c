void main()
{
    int x, *p;
    x = 100;
    p = &x;
    printf("Valor de p: %d.\n", *p);
}
void troca(int *i, int *j)
{
    int *temp;
    *temp = *i; //temp = i
    *i = *j;    //i = j
    *j = *temp; // j = temp, j = i
                // j = i, i = j
}