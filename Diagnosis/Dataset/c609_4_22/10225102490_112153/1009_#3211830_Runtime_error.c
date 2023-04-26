#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int GCD(int m,int n)//最大公约数
{
    if (n == 0) return m;
    else return GCD(n,m%n);
}

int main()
{
    int T;
    scanf("%d",&T);
    char c[256];
    while (T--)
    {
        gets(c);
        int n = strlen(c);
        int den = n * 8;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (c[i] & (1<<j)) sum++;
            }
        }
        int x = GCD (sum, den);
        sum /= x;
        den /= x;
        printf("%d/%d\n",sum,den);
    }
}