#include <stdio.h>
#include <stdlib.h>

long long F(int n)
{
    if(n==0) return 0;
    if(n==1) return 1;
    if(n==2) return 1;
    if(n>2) return F(n-1)+F(n-2);
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;++i)
    {
        int n;
        scanf("%d",&n);
        printf("case #%d:\n",i);
        printf("%lld\n",F(n));
    }
    return 0;
}
