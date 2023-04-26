#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int sum;
int n,p,m,t;
void dfs(int p,int cnt)
{
    if(p==t&&cnt==m){sum++;return;}
    else if(cnt>=m)return;
    else if(p==1) dfs(p+1,cnt+1);
    else if(p==n) dfs(p-1,cnt+1);
    else
    {
        dfs(p+1,cnt+1);
        dfs(p-1,cnt+1);
    }
}

int main()
{
    ,cas; scanf("%d",&cas);
    for(int i=0;i<cas;i++)
    {
        scanf("%d %d %d %d",&n,&p,&m,&t);
        sum=0;
        dfs(p,0);
        printf("%d\n",sum);
    }
}