#include <stdio.h>

long long f(int n,int p,int m,int t) {
    if (m==0&&p==t) return 1;
    if (m==0&&p!=t) return 0;
    if (m>0&&p==1) return f(n,p + 1,m-1,t);
    if (m>0&&p==n) return f(n,p - 1,m-1,t);
    else return f(n,p + 1,m-1,t)+f(n,p + 1,m-1,t);
}

int main () {
    int cas,i;
    int n,p,m,t;
    scanf ("%d", &cas);
    for (i=0;i<cas;i++) {
        scanf ("%d%d%d%d", &n,&p,&m,&t);
        // memset(f, -1, sizeof(f));
        if (t>n) printf("%d\n", 0);
        else printf("%lld\n", f(n,p,m,t));
    }
    return 0;
}