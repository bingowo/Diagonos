#include <stdio.h>
#include <stdlib.h>

long long mmul(x)
{
    long long re=1;
    for(int i=0;i<x;i++)
        re*=2;
    return re;
}

int main()
{
    int n=0,m=0;
    while(scanf("%d%d",&n,&m)!=EOF&&n!=-1&&m!=-1)
    {
        long long re=mmul(n-m);
        for(int i=0,j=n-m-1;j>=0;j--)
        {
            if(i<m)
            {
                re+=mmul(n-m-1);
                i++;
            }
            else
            re+=mmul(j);
        }
        printf("%lld\n",re);
    }
    return 0;
}
