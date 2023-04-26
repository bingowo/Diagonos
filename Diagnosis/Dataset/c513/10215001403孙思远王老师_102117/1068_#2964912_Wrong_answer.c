#include <stdio.h>
#include <stdlib.h>

long long int cc(int n,int m)
{
    long long int all,a=1,b=1,c=1;
    int i;
    for(i=1;i<=n;i++)
        a*=i;
    for(i=1;i<=m;i++)
        b*=i;
    for(i=1;i<=n-m;i++)
        c*=i;
    all=a/(b*c);
    return all;
}
int main()
{
    int n=1,m=1;
    while(1)
    {
        scanf("%d%d",&n,&m);
        if(n==-1)
            break;
        int i;
        long long int all=0;
        for(i=1;i<=n-m+1;i++)
        {
            all+=cc(n-m+1,i);
        }
        printf("%lld\n",all);
    }
    return 0;
}
