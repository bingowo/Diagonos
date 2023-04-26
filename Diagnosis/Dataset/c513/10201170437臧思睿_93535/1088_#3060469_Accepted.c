#include <stdio.h>
#include <stdlib.h>
//const int M=10007;
typedef long long int ll;

int main()
{
    int t=0,T;
    scanf("%d",&T);
    while(t++<T)
    {
        printf("case #%d:\n",t-1);
        int m = 1, n = 1, large = 1, small = 1, i = 1;
        unsigned long long P = 1;
        scanf("%d%d", &m, &n);
        if (m > 2 * n)
        {
            small = n;
            large = m - n;
        }
        else
        {
            small = m - n;
            large = n;
        }
        for (i = m; i > large; i--)
        {
            if (i == 2 * small)
            {
                P = P * 2;
                small--;
            }
             else
                 P = P * i;
        }
        while (small > 1)
        {
            P = P / small;
            small--;
        }
        printf("%lld\n", P);
    }
    return 0;
}
