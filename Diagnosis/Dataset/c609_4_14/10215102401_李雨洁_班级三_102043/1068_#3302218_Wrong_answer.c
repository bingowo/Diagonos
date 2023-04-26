#include <stdio.h>
int f(int n,int p,int m,int t)
{
    if(m==0 && p!=t)  return 0;
    if(m==0 && p==t)  return 1;
    if(m>0)
    {
        if(t==1) return f(n,p,m-1,t+1);
        if(t==n) return f(n,p,m-1,t-1);
        else
            return f(n,p,m-1,t-1)+f(n,p,m-1,t+1);
    }
}
int main()//递归实现
{
    int cas,n,p,m,t;
    scanf("%d",&cas);
    int end;
    for(int z=0;z<cas;z++)
    {
        scanf("%d %d %d %d",&n,&p,&m,&t);
        end=f(n,p,m,t);
        printf("%d\n",end);
    }
    return 0;
}
