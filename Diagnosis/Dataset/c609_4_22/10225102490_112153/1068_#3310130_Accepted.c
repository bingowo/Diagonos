#include <stdio.h>

int f(int p, int m, int n, int t)
{
    if (m == 0) return p == t;
    if (p == 1) return f(2,m-1,n,t);
    if (p == n) return f(n-1,m-1,n,t);
    return f(p-1, m-1, n, t) + f(p+1, m-1, n, t);
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int I = 0; I < T; I++)
    {
        int n,p,m,t;
        scanf("%d%d%d%d",&n,&p,&m,&t);
        printf("%d\n",f(p,m,n,t));
    }
    return 0;
}
