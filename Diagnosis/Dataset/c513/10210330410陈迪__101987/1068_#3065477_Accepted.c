#include <stdio.h>

int solve(int n, int m)
{
    if(n<m){
        return 0;
    }
    if(n==m){
        return 1;
    }
    return 2*solve(n-1,m)-solve(n-m-1,m)+(1<<(n-m-1));
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    while(n!=-1&&m!=-1)
    {
        int x;
        x=solve(n,m);
        printf("%d\n",x);
        scanf("%d%d",&n,&m);
    }
    return 0;
}
