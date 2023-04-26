#include <stdio.h>
#include <math.h>

long long f(int n)
{
    long long m=1;
    int i;
    for (i=1;i<=n;i++){
        m = m*i;
    }
    orintf("%lld",m);
    return m;
}

int main()
{
    int T;scanf("%d",&T);
    int a,b,k,n,m;
    long long x;
    int i;
    for (i=0;i<T;i++){
        scanf("%d %d %d %d %d",&a,&b,&k,&n,&m);
        x = pow(a,n)*pow(b,m)*f(k)/(f(m)*f(n));
        printf("case #%d:\n%d\n",i,x%10007);
    }
}