#include <stdio.h>
#include <stdlib.h>

int f(int n,int p,int m,int t)
{
    if(m==0){
        if(p==t) return 1;
        else return 0;
    }
    if(p==1) return f(n,p+1,m-1,t);
    else if(p==n) return f(n,p-1,m-1,t);
    else return f(n,p+1,m-1,t)+f(n,p-1,m-1,t);
}

int main()
{
    int T=0;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int n=0,p=0,m=0,t=0,ans=0;//n为最大楼号数,p为开始楼号，m为时间，t为最后楼号数
        scanf("%d %d %d %d",&n,&p,&m,&t);
        ans=f(n,p,m,t);
        printf("%d\n",ans);
    }
    return 0;
}
