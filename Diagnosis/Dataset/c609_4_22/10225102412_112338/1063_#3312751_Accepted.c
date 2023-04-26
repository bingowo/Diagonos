#include <stdio.h>
#include <math.h>

long long f(int n)
{
    long long m,a=1,b=2,c=4,d=8;
    int i;
    if (n<=4) m = pow(2,n-1);
    else{
        for (i=4;i<n;i++){
            m = a+b+c+d;
            a = b;
            b = c;
            c = d;
            d = m;
        }
    }
    return m;
}

int main()
{
    int T,i,n;
    scanf("%d",&T);
    for (i=0;i<T;i++){
        scanf("%d",&n);
        printf("case #%d:\n%lld\n",i,f(n));
    }
    return 0;
}