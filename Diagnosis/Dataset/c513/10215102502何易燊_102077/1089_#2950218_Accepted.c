#include <stdio.h>

long long qmod(int a,int n,int p)
{
    if (n==0) return 1;
    else if (n%2==1) return qmod(a,n-1,p)*a%p;
    else
    {
        long long temp = qmod(a,n/2,p)%p;
        return temp*temp%p;
    }
}

int main()
{
    int T; scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        int a,b,n; scanf("%d %d %d",&a,&b,&n);
        int get = 1, m = n;
        while (m--) get *= 10;
        printf("case #%d:\n%0*d\n",i,n,qmod(a,b,get));
    }
    return 0;
}