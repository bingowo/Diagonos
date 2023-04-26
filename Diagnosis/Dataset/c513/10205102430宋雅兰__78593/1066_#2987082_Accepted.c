#include<stdio.h>
#include<math.h>
int func(int n,int p,int m,int t)
{
    if(m<abs(t-p))return 0;
    if(m==0&&p==t)return 1;
    else if(m==0&&p!=t) return 0;
    if(m>0&&t==1)return func(n,p,m-1,2);
    else if(m>0&&t==n)return func(n,p,m-1,n-1);
    else if(m>0&&t>1&&t<n)return func(n,p,m-1,t-1)+func(n,p,m-1,t+1);
}
int main()
{
    int cas;
    scanf("%d",&cas);
    for(int i=0;i<cas;i++)
    {
        int n,p,m,t;
        scanf("%d%d%d%d",&n,&p,&m,&t);
        printf("%d\n",func(n,p,m,t));
    }
    return 0;
}