#include <stdio.h>
#include <stdlib.h>
long long num[51]={0,1,2,4,8};
long long f(int a)
{
    if(a==0)
        return 0;
    else if(num[a]>0)
        return num[a];
    else
    {
        num[a]=f(a-1)+f(a-2)+f(a-3)+f(a-4);
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
        printf("%lld",f(a));
    }
    return 0;
}
