#include <stdio.h>
#include <stdlib.h>

void swap(int*p1,int*p2)
{
    int tmp;
    tmp=*p1;
    *p1=*p2;
    *p2=tmp;
}

int main()
{
    long long x,y;
    scanf("%lld %lld",&x,&y);
    if(x>y)swap(x,y);
    long long ans=0;
    while(x){long long a=y/x;ans+=4*x*a;y%=x;swap(x,y);}
    printf("%lld",ans);
    return 0;
}
