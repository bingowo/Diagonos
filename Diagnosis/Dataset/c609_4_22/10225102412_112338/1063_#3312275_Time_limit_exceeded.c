#include <stdio.h>
#include <math.h>

long long f(int n)
{
    long long m;
    if (n<=4) m = pow(2,n-1);
    else m = f(n-1)+f(n-2)+f(n-3)+f(n-4);
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