#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,i,j,k=1;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        int m,n;
        scanf("%d",&m);
        scanf("%d",&n);
        unsigned long long q=1;
        if(n > m - n)
            n = m - n;
        for(int j = 1, k = m; j <= n; j++, k--)
        {
            q *= k;
            q /= j;
        }
        printf("case #%d:\n",i);
        printf("%lld\n",q);
    }
    return 0;
}