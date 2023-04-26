#include <stdio.h>
#include <stdlib.h>
int miao(int x)
{
    if(x%9==0) return 0;
    while(x)
    {
        if(x%10==9) {return 0;break;}
        x=x/10;
    }
    return 1;
}
int main()
{
    long long unsigned a,b;
    scanf("%llu%llu",&a,&b);
    long long unsigned num=0;
    for(long long unsigned i=a;i<=b;i++)
    {
        if(miao(i)) num++;
    }
    printf("%llu",num);
    return 0;
}
