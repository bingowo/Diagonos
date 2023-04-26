#include<stdio.h>
#include<string.h>
#include<math.h>

int fg(int n,int p,int m,int t)
{
    int cha=p-t;
    if(abs(cha)>m) return 0;
    else if(m==0&&p==t) return 1;
    if(p==1) return fg(n,p+1,m-1,t);
    else if(p==n) return fg(n,p-1,m-1,t);
    else return fg(n,p-1,m-1,t)+fg(n,p+1,m-1,t);
}

int main()
{
    int cas,i,n,p,m,t,data;
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        scanf("%d%d%d%d",&n,&p,&m,&t);
        data=fg(n,p,m,t);
        printf("%d\n",data);
    }
    return 0;
}
