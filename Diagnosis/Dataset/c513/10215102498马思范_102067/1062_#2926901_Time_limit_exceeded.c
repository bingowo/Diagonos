#include <stdio.h>
#include <string.h>
#include <stdlib.h>
long long sum(int n)
{
    if(n==1)
        return 1;
    else if(n==2)
        return 2;
    else if(n==3)
        return 4;
    else if(n==4)
        return 8;
    else
        return sum(n-4)+ sum(n-3)+ sum(n-2)+ sum(n-1);
}
int main()
{
    int t;
    scanf("%d",&t);
    int n;
    long long result=0;
    for(int i=0;i<t;i++)
    {
        scanf("%d",&n);
        result=sum(n);
        printf("case #%d:\n",i);
        printf("%lld\n",result);
    }
    return 0;
}