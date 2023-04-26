#include <stdio.h>
#include <stdlib.h>
int count,t,n;
int main()
{
    int cas(int p,int m);
    int minute,q,a,i;
    scanf("%d",&a);
    for(i=1;i<=a;i++)
    {
        count=0;
        scanf("%d %d %d %d",&n,&q,&minute,&t);
        cas(q,minute);
        printf("%d\n",count);
    }
    return 0;
}
int cas(int p,int m)
{
    if(m<=0)
    {
        if(p==t)
        {
            count++;
            return 0;
        }
        else if(p!=t)
            return 0;
    }
    if(p==1)
        cas(2,m-1);
    else
    {
        if(p==n)
            cas(n-1,m-1);
        else
        {
            cas(p+1,m-1);
            cas(p-1,m-1);
        }
    }
}
