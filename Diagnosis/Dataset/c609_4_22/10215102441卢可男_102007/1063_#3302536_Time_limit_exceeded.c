#include <stdio.h>
#include <stdlib.h>
long long f(int n,long long *counter)
{
    if(n<3)
    {
        return counter[n]=n;
    }

    else if(n==3)
    {
        return counter[n]=4;
    }
    else if(n==4)
    {
        return counter[n]=8;
    }
    else
    {
       counter[n]=f(n-4,counter)+f(n-3,counter)+f(n-2,counter)+f(n-1,counter);
        return counter[n];
    }



}
int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        int n;
        long long counter[51]={0};
        long long res;
        scanf("%d",&n);
        res=f(n,counter);
        printf("case #:%d\n%lld\n",i,res);
    }
    return 0;
}
