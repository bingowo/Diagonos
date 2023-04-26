#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned long long int cc(int a,int k)
{
    int i;
    unsigned long long int x1=1,x2=1,x3=1;
    for(i=a+1;i<=k;i++)
        x1=x1*i;
    for(i=1;i<=k-a;i++)
        x2=x2*i;
    x3=x1/x2;
    return x3%10007;
}
long long int po(int a,int b)
{
    int i;
    long long int c=1;
    for(i=0;i<b;i++)
    {
        c=c*a%10007;
    }
    return c;
}
int main()
{
    int t,T;
    scanf("%d\n",&T);
    for(t=0;t<T;t++)
    {
        printf("case #%d:\n",t);
        int a,b,k,n,m;
        scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
        long long int all=1;
        all*=po(a,n);
        all*=po(b,m);
        all*=cc(n,k);
        while(all>=10007)
            all%=10007;
        printf("%lld\n",all);
    }
    return 0;
}
