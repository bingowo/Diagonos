#include <stdio.h>
#include <stdlib.h>

int ans[32][32]={0};

int f(int n,int m)
{
    if(!ans[n][m])
    {
        if(n<m) return ans[n][m]=0;
        if(n==m) return ans[n][m]=1;
        return ans[n][m]=2*f(n-1,m)-f(n-m-1,m)+(1<<(n-m-1));
    }
}

int main()
{
    int n,m;
    while(1)
    {
        scanf("%d%d",&n,&m);
        if(n==-1 && m==-1) break;
        printf("%d\n",f(n,m));
    }
    return 0;
}
