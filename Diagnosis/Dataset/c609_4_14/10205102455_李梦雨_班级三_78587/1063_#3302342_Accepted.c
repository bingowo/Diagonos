#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    scanf("%d\n",&t);
    long long int num[50];
    num[0]=1;
    num[1]=2;
    num[2]=4;
    num[3]=8;
    for(int i=4;i<50;i++)
        num[i]=num[i-1]+num[i-2]+num[i-3]+num[i-4];
    for(int k=0;k<t;k++)
    {
        printf("case #%d:\n",k);
        int n;
        scanf("%d\n",&n);
        printf("%lld\n",num[n-1]);
    }
    return 0;
}