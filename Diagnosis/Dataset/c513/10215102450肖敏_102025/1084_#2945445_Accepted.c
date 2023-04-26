#include <stdio.h>
long long fun(int n)
{
    return 1<<n;
}
int main() {
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int n;
        scanf("%d",&n);
        long long sum;
        sum= fun(n);
        printf("case #%d:\n%lld\n",i,sum);
    }
    return 0;
}
