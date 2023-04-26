
#include <stdio.h>
#include <stdlib.h>
long long int cal(int m)
{
    if(m==1)
        return 1;
    else if(m==2)
        return 2;
    else if(m==3)
        return 4;
    else if(m==4)
        return 8;
    else
    {
        return cal(m-1)+cal(m-2)+cal(m-3)+cal(m-4);
    }
}
int main()
{
    int m;
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        long long int n;
        scanf("%lld",&n);
        n=cal(n);
        printf("case #%d:\n%lld\n",i,n);
    }
    return 0;
}
