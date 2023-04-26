#include <stdio.h>
#include <stdlib.h>

int count(int n,int m)
{
    int a=0,i;
    if(m==1)
    {
        for(i=1;i<=n;i++)
        {
            a=n/i+a;
        }
        return a;
    }
    else
    {
        for(i=1;i<=n-m+1;i++)
            a=count(n-i,m-1)+a;
        return a;
    }
}

int main()
{
    int n,m,result;
    scanf("%d %d",&n,&m);
    while(n!=-1&&m!=-1)
    {
        result=count(n,m);
        printf("%d\n",result);
        scanf("%d %d",&n,&m);
    }
    return 0;
}
