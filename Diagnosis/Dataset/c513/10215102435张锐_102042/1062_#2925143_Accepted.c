#include <stdio.h>
#include <stdlib.h>
long long int step(int x)
{
    if(x==1) return 1;
    else if(x==2) return 2;
    else if(x==3) return 4;
    else if(x==4) return 8;
    else
    {
        long long int x1=1,x2=2,x3=4,x4=8;
        for(int i=4;i<x;i++)
        {
            long long int x0=x1;
            x1=x2;
            x2=x3;
            x3=x4;
            x4=x0+x1+x2+x3;
        }
        return x4;//迭代return step(n-1)+step(n-2)+step(n-3)+step(n-4)
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int x;
        scanf("%d",&x);
        long long int n=0;
        n=step(x);
        printf("case #%d:\n",i);
        printf("%lld\n",n);
    }
}