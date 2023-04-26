#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i < T;i++)
    {
        int n,solve = 0;
        int j,k,l,m;
        int a,b,c,d;
        scanf("%d",&n);
        for(j = 0;j <= n;j++)
        {
            //for(k = 0;k <= n / 2 + 1;k++)
            //{
            //    for(l = 0;l <= n / 3 + 1;l++)
            //    {
            //        for(m = 0;m <= n / 4 + 1;m++)
            //        {
            //            if(4 * m + 3 * l + 2 * k + j == n)
            //                solve++;
            //        }
            //    }
            //}
            for(j = 0;j <= n / 4;j++)
            {
                a = n - j * 4;
                for(k = 0;k < a / 3;k++)
                {
                    b = a - k * 3;
                    for(l = 0;l < b / 2;l++)
                    {
                        c = b - l * 2;
                        {
                            //for(m = 0;m < c;m++)
                            //{
                            //    d = c - m;
                            //    solve += d;
                            //}
                            solve++;
                        }
                    }
                }
            }
        }
        printf("%d\n",solve);
    }
    return 0;
}