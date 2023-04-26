#include <stdio.h>
#include <stdlib.h>


long long  F[1000000]={0};


int main()
{
    int n;
    scanf("%d",&n);
    F[0]=0; F[1]=1; F[2]=2; F[3]=3; F[4]=6;
    for (int i=5;i<=n;i++)
        F[i]=F[i-1]+F[i-2]+F[i-4];
    printf("%lld",F[n]);

    return 0;
}
