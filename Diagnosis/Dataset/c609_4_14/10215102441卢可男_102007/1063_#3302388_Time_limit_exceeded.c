#include <stdio.h>
#include <stdlib.h>
long long f(int n)
{
    if(n==1)
        return 1;
    if(n==2)
        return 2;
    if(n==3)
        return 4;
    if(n==4)
        return 8;
    return f(n-4)+f(n-3)+f(n-2)+f(n-1);
}
int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        int n;
        long long res;
        scanf("%d",&n);
        res=f(n);
        printf("%lld\n",res);
    }
    return 0;
}
