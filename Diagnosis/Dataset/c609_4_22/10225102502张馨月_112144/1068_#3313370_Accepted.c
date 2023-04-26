#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int f(int n,int p,int m,int t)//n为总楼数；p是开始的楼数；过了m分钟；到达t号楼
{
    if(m==0&&p!=t) return 0;
    if(m==0&&p==t) return 1;
    if(m>0&&t==1) return f(n,p,m-1,t+1);
    if(m>0&&t==n) return f(n,p,m-1,t-1);
    else return f(n,p,m-1,t+1)+f(n,p,m-1,t-1);
}
int main()
{
    int cas,k;
    scanf("%d",&cas);
    int n,p,m,t;
    for(k=0;k<cas;k++)
    {
        scanf("%d %d %d %d",&n,&p,&m,&t);
        if(t>n) printf("0\n");
        else printf("%d\n",f(n,p,m,t));
    }
    return 0;
}