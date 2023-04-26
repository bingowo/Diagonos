#include <stdio.h>
#include <math.h>

int f(int n)
{
    int m=1,i;
    for (i=1;i<=n;i++){
        m = m*i;
    }
    return m;
}

int main()
{
    int T;scanf("%d",&T);
    int a,b,k,n,m;
    int x,i;
    for (i=0;i<T;i++){
        scanf("%d %d %d %d %d",&a,&b,&k,&n,&m);
        x = pow(a,n)*pow(b,m)*f(k)/f(k-n)/f(n);
        printf("case #%d:\n%d\n",i,a);
    }
}