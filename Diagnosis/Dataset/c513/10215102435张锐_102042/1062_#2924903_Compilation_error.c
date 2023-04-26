#include <stdio.h>
#include <stdlib.h>
unsigned long long step(int x)
{
    if(x==1) return 1;
    else if(x==2) return 2;
    else if(x==3) return 4;
    else if(x==4) return 8;
    else return step(n-1)+step(n-2)+step(n-3)+step(n-4);
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int x;
        scanf("%d",&x);
        unsigned long long n=0;
        n=step(x);
        printf("case #%d:\n",i);
        printf("%llu\n",n);
    }
}