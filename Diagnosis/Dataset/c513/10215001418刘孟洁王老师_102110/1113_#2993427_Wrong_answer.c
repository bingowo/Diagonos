#include <stdio.h>
#include <stdlib.h>

int main()
{
    int k,n,i,j;
    long long s[1007];
    s[0] = 0;s[1] = 1;
    scanf("%d%d",&k,&n);
    for(i = 2; i < n; i++)
    {
        for(j = i-k; j < i; j++)
        {
            if(j < 0)continue;
            else s[i] += s[j];
        }
    }
    printf("%lld",s[n-1]);
    return 0;
}
