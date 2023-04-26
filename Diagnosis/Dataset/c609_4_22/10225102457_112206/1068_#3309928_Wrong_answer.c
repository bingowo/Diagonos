#include<stdio.h>
#include<stdlib.h>

long long mov(int n, int p, int m, int t){
    static long long a[21][100];
    if(abs(p-t) > m) return 0;
    if(p == t && m == 0) return a[m][p] += 1;
    if(a[m][p]) return a[m][p];
    if(p == 1) return a[m][p] += mov(n, p+1, m-1, t);
    if(p == n) return a[m][p] += mov(n, p-1, m-1, t);
    return a[m][p] += mov(n, p+1, m-1, t) + mov(n, p-1, m-1, t);
}

int main(void)
{
    int T;
    scanf("%d",&T);
    for(int i = 0; i<T; i++){
        int n,p,m,t;
        scanf("%d%d%d%d",&n,&p,&m,&t);

        printf("%lld\n", mov(n,p,m,t));
    }
    return 0;
}