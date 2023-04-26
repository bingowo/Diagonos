#include<stdio.h>
#include<stdlib.h>

long long mov(int n, int p, int m, int t){
    if(abs(p-t) > m) return 0LL;
    if(abs(p-t) == m) return 1LL;
    if(p == 1) return mov(n, p+1, m-1, t);
    if(p == n) return mov(n, p-1, m-1, t);
    return mov(n, p+1, m-1, t) + mov(n, p-1, m-1, t);
}

int main(void)
{
    int T;
    scanf("%d",&T);
    for(int i = 0; i < T; i++){
        int n,p,m,t;
        scanf("%d%d%d%d",&n,&p,&m,&t);
        if(i >= 80) printf("%d,%d,%d,%d\n",n,p,m,t);
        //printf("%lld\n", mov(n,p,m,t));
    }
    return 0;
}
