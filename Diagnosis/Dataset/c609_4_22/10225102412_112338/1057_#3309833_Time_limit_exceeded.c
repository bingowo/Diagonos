#include <stdio.h>

long long fact(int n)
{
    long long m=1;
    int i;
    if (n==0){
        return 1;
    }
    for (i=1;i<=n;i++){
        m *= i;
    }
    return m;
}

int calc(int n)
{
    long long m,a;
    int i=0;
    m=fact(n);
    a = m/10;
    while (m==a*10){
        m = a;
        a = a/10;
        i++;
    }
    return i;
}

int main()
{
    int T,i,N;
    scanf("%d",&T);
    for (i=0;i<T;i++){
        scanf("%d",&N);
        printf("case #%d:\n%d",i,calc(N));
    }
    return 0;
}
