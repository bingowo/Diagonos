#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int f[21],g[21];
    //f[i]表示长度为i的以0结尾的字串， g[i]表示长度为i的以1结尾的子串
    f[0] = 0;g[0] = 0;f[1] = 1;g[1] = 1;
    for (int i = 2; i <= 20;i++)
    {
        f[i] = f[i - 1] + g[i - 1];
        g[i] = f[i] - g[i - 2];
    }
    while (scanf("%d",&n) != EOF && n != -1)
    {
        printf("%d\n",f[n] + g[n]);
    }
    return 0;
}
