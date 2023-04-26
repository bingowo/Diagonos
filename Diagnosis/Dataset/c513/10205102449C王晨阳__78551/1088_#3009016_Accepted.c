#include <stdio.h>

long long cnm(int n, int m)
{
    int i;long long a;
    if(m+m>n) m=n-m;//be faster
    for(i=1,a=1;i<=m;i++,n--) a=a*n/i;
    return a;
}

int main() {
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int n,m;
        scanf("%d %d",&n,&m);
        printf("case #%d:\n%lld\n",i,cnm(n,m));
    }
    return 0;
}
