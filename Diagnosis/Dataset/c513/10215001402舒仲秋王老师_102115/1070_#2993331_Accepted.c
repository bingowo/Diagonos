#include <stdio.h>
#include <stdlib.h>
#include<math.h>

long long int putout(int n)
{
    long long int t;
    if(n<3) t=pow(2,n);
    else if(n==3) t=7;
    else t=2*putout(n-1)+putout(n-3)-putout(n-2);
    return t;
}

int main()
{
    int n;
    for(n=0;;)
    {
        scanf("%d",&n);
        if(n==-1) break;
        printf("%lld\n",putout(n));
    }
    return 0;
}
