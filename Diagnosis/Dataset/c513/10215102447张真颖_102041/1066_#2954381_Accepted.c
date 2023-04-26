#include <stdio.h>
#include <stdlib.h>


int count(int p,int m,int t,int n,int num)
{
    if(m==0)
    {
        if(p==t) num+=1;
    }
    else
    {
        if(p<n) num=count(p+1,m-1,t,n,num);
        if(p>1) num=count(p-1,m-1,t,n,num);
    }
    return num;
}

int main()
{
    int cas=0;
    scanf("%d",&cas);
    for(int i=0;i<cas;i++)
    {
        int n=0,p=0,m=0,t=0;
        int num=0;
        scanf("%d%d%d%d",&n,&p,&m,&t);
        num=count(p,m,t,n,num);
        printf("%d\n",num);
    }
    return 0;
}