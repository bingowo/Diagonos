#include <stdio.h>
#include <stdlib.h>
long long int step(int x)
{
    if(x==1) return 1;
    else if(x==2) return 2;
    else if(x==3) return 4;
    else if(x==4) return 8;
    else return step(x-1)+step(x-2)+step(x-3)+step(x-4);
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