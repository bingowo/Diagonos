#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
void read(int n,int p,int m,int dep,int t,int a[])
{
    if(m==dep&&t==p)  {a[0]++;return;}
    else if(m==dep)
            {
                return;
            }
    else
    {
        if(p==n)
            read(n,p-1,m,dep+1,t,a);
        else if(p==1)
            read(n,p+1,m,dep+1,t,a);
        else
        {
            read(n,p-1,m,dep+1,t,a);
            read(n,p+1,m,dep+1,t,a);
        }
    }
}
int main()
{   int a[3];
    int cas,n,p,m,t;
    scanf("%d",&cas);
    for(int i=0;i<cas;i++)
    {   a[0]=0;
        scanf("%d %d %d %d",&n,&p,&m,&t);
        read(n,p,m,0,t,a);
        printf("%d\n",a[0]);
    }
}
