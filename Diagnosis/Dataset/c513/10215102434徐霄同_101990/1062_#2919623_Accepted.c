#include <stdio.h>

int main()
{
    long long t,i,n;
    long long num[50];
    num[0]=1;
    num[1]=2;
    num[2]=4;
    num[3]=8;
    for(i=4;i<50;i++)
        num[i]=num[i-1]+num[i-2]+num[i-3]+num[i-4];
    scanf("%lld",&t);
    for(i=0;i<t;i++){
        scanf("%lld",&n);
        printf("case #%lld:\n",i);
        printf("%lld\n",num[n-1]);
    }
    return 0;
}
