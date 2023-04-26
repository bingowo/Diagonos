#include <stdio.h>
#include <stdlib.h>
long long int f(int n,int m)
{
    if(n<m) return 0;
    if(n==m) return 1;
    else return 2*f(n-1,m)-f(n-m-1,m)+(1<<(n-m-1));
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    while(m!=-1&&n!=-1)
    {
        long long int ans=f(n,m);
        printf("%lld\n",ans);
        scanf("%d%d",&n,&m);
    }
    return 0;
}
