#include <stdio.h>

int calc(int n)
{
    int m,i=0,a;
    m=fact(n);
    a = m/10;
    while (m==a*10){
        m = a;
        a = a/10;
        i++;
    }
    return i;
}

int fact(int n)
{
    int m=1,i;
    for (i=1;i<=n;i++){
        m *= i;
    }
    return m;
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
