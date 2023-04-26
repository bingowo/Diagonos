#include <stdio.h>
#include <stdlib.h>

long long re(int n)
{
    if(n==1)
        return 1;
    else if(n==2)
        return 2;
    else if(n==3)
        return 6;
    else if(n==4)
        return 8;
    else
        return re(n-1)+re(n-2);
}

int main()
{
    int T,i,n;
    long long ret;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d",&n);
        ret=re(n);
        printf("case #%d:\n",i);
        printf("%lld\n",ret);
    }
    return 0;
}
