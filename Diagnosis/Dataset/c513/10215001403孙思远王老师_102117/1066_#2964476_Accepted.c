#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int bu(int n,int p,int m,int t,int all)
{
    if(m)
    {
        if(p==n)
            all+=bu(n,p-1,m-1,t,all);
        else if(p==1)
            all+=bu(n,p+1,m-1,t,all);
        else
        {
            all+=bu(n,p-1,m-1,t,all)+bu(n,p+1,m-1,t,all);
        }
    }
    else
    {
        if(p==t)
            all++;
    }
    return all;
}
int main()
{
    int t,T;
    scanf("%d",&T);
    for(t=0;t<T;t++)
    {
        int n,p,m,t,all=0;
        scanf("%d%d%d%d",&n,&p,&m,&t);
        if((m-abs(p-t))%2==1)
            printf("0\n");
        else
        {
            all=bu(n,p,m,t,all);
            printf("%d\n",all);
        }
    }
    return 0;
}
