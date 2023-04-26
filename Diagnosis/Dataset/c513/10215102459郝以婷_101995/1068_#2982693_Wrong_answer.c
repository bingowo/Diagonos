#include <stdio.h>
#include <stdlib.h>

int count(int n,int m)
{
    if(m==n)
        return 1;
    if(n<m)
        return 0;
    if(n>m)
        return 2*count(n-1,m)+count(n-1-m,m)+(1<<(n-m-1));
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
