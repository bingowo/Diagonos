#include <stdio.h>
#include <stdlib.h>
#include<math.h>

long long int putout(int m,int n)
{
    long long int t;
    if(m==n) t=1;
    else if(m<n) t=0;
    else t=2*putout(m-1,n)-putout(m-n-1,n)+pow(2,m-n-1);
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
    return 0;
}
