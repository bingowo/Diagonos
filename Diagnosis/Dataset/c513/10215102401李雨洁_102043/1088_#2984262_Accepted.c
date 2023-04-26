#include<stdio.h>
#include<string.h>

int main()
{
    int t;
    scanf("%d",&t);
    for(int i = 0; i < t; i++)
    {
        int m,n;
        scanf("%d %d",&m,&n);
        if(n > m - n) n = m - n;
        long long end = 1;
        for(int j = 1, k = m; j <= n; j++, k--)
        {
            end *= k;
            end /= j;//j不能等于0
        }
        printf("case #%d:\n",i);
        printf("%lld\n",end);
    }
    return 0;
}



