#include <stdio.h>
#include <stdlib.h>
#include<math.h>

long long int putout(int m,int n)
{
    long long int t=0;
    int i;
    if(m==n) t=1;
    else
    {
        for(i=0;i<=m-n;i++)
            t+=pow(2,i);
    }
    return t;
}

int main()
{
    int m,n;
    for(m=0,n=0;;)
    {
        scanf("%d %d",&m,&n);
        if(m==-1&&n==-1) break;
        printf("%lld\n",putout(m,n));
    }
}
