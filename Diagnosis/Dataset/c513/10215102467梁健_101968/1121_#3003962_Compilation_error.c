#include<stdio.h>
const int N = 11,M = 10000;
int w[N];
int st[3]={-1,0,1};
int n,ans;

void dfs(int u,int res)
{
    if(u==n)
    {
        res=(res>=0?res:-res);
        if(res&&!((ans>>(res-1))&1))
        ans+=(1<<(res-1));
    }
    else
    {
        for(int i=0;i<3;++i){
            dfs(u+1,res+w[u]*st[i]);
        }
    }
}

void print()
{
    char str[M];
    int len=0;
    while(ans)
    {
        if(ans&1)str[len++]='1';
        else str[len++]='0';
        ans>>=1;
    }
    for(int i=0;i<len;++i)putchar(str[i]);
}

int main()
{
    
    scanf("%d",&n);
    for(int i=0;i<n;++i)scanf("%d",&w[i]);
    dfs(0,0);
    print();
    return 0;
}