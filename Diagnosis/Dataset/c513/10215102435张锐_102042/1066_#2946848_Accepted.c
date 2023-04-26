#include <stdio.h>
#include <stdlib.h>
int f(int n,int p,int m,int t)
{
    int num=0;
    if(m==0&&p==t) return 1;
    if(m==0&&p!=t) return 0;
    if(m>0&&p!=1&&p!=n) return f(n,p-1,m-1,t)+f(n,p+1,m-1,t);
    if(m>0&&p==1) return f(n,2,m-1,t);
    if(m>0&&p==n) return f(n,n-1,m-1,t);
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int n,p,m,t;
        scanf("%d%d%d%d",&n,&p,&m,&t);
        printf("%d\n",f(n,p,m,t));
    }
    return 0;
}
