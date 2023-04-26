#include <stdio.h>
#include <stdlib.h>

long long int putout(int m,int n)
{
    long long int t;
    if(m==n) t=1;
    else t=m-n+1+putout(m,n+1);
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
