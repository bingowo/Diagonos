#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,t,r;
    scanf("%d", t);
    int num = 0;
    while (num < t)
    {
        scanf("%d %d", m,r);
        int L[32];
        int i = 0;
        char table[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        do
        {
            int x = m % r;
            L[i] = table[x];
            m = m / r;
            i++;
        }
        while(m);
        for (;i>=0;i--)
        {
            printf("%c", L[i]);
        }
        num ++;
    }
    return 0;
}
