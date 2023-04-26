#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[100]={0};
    int n,num;
    a[0]=1;
    a[1]=2;
    a[2]=4;
    int i;
    for(i=3;i<=20;i++)
        a[i]=2*a[i-1]+a[i-3]-a[i-2];
    while(scanf("%d ",&n))
    {
        num=0;
        if(n==-1)
            break;
        if(n==1)
            num=2;
        if(n==2)
            num=4;
        if(n>=3)
            num=a[n];
        printf("%d\n",num);
    }
}