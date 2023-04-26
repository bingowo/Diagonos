#include <stdio.h>
#include <stdlib.h>
long long num[75]={0,1,1,2,4,7,13,24,44,81,149};
long long f(int a)
{
    if(a==0)
        return 0;
    else if(num[a]!=0)
        return num[a];
    else
    {
        long long x=f(a-1)+f(a-2)+f(a-3);
        num[a]=x;
        return num[a];
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        int a;
        scanf("%d",&a);
        printf("%lld\n",f(a));
    }
    return 0;
}
