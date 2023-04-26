#include<stdio.h>
int main()
{
    char table[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int a = 0, b, i, k, d = 0;
    char n[50], out[50], c;
    while ((c = getchar()) != ' ')
        a = a*10 + c - '0';
    for ( i = 0; (c=getchar()) != ' '; i++) n[i] = c;
    n[i] = '\0';
    scanf("%d", &b);
    for ( i = 0; n[i] ; i++)
    {
        if ( (n[i] - 32) <= 'Z' && (n[i] - 32) >= 'A')
        {
            n[i] -= 32;
        }
        for (int j = 0; table[j]; j++)
        {
            if (table[j] == n[i]){d = d * a + j; break; }
        }
    }
    for (k = 0; d / b; k++, d /=b)out[k] = table[ d % b];
        out[k] = d + '0';
    for (; out[k]; k--)printf("%c", out[k]);
}
