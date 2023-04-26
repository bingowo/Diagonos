#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i < T;i++)
    {
        int n,solve = 0;
        int j,k,l;
        int a,b,c;
        scanf("%d",&n);
        for(j = 0;j <= n / 4;j++)
        {
            a = n - j * 4;
            for(k = 0;k <= a / 3;k++)
            {
                b = a - k * 3;
                for(l = 0;l <= b / 2;l++)
                {
                    c = b - l * 2;
                    {
                        solve++;
                    }
                }
            }
        }
        printf("%d\n",solve);
    }
    return 0;
}