#include <stdio.h>
#include <stdlib.h>
unsigned long long ans[10000][10000];
unsigned long long f(unsigned long long n,unsigned long long m)
{
    if(n<m) return 0;
    if(n==m) return 1;
    if(!ans[n][m])
    {
        ans[n][m]=2*f(n-1,m)-f(n-m-1,m)+(1<<(n-m-1));
    }
    return ans[n][m];
}
int main()
{
    unsigned long long n,m;
    scanf("%llu %llu",&n,&m);
    while(n!=-1&&m!=-1){
    unsigned long long a=f(n,m);
    printf("%llu\n",a);
    return 0;
    }
}
