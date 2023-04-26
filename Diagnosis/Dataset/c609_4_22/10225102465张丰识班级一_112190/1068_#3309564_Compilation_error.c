#include <stdio.h>
int f(int n,int p,int m,int t) {
    if (m==0&&p==t) return 1;
    if (m==0&&p!=t) return 0;
    if (m>0&&t==1) return f(n,p,m-1,t+1);
    if (m>0&&t==n) return f(n,p,m-1,t-1);
    else return f(n,p,m-1,t+1)+f(n,p,m-1,t+1);
}
int main () {
    int cas,i;
    int n,p,m,t;
    scanf ("%d", &cas);
    for (i=0;i<cas;i++) {
        scanf ("%d%d%d%d", &n,&p,&m,&t);
        if (t>n) printf("%d\n", 0);
        else printf("%d", f(n,p,m,t))
    }
    return 0;
}