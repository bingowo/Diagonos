#include <stdio.h>
#include <stdlib.h>
int miao(int x)
{
    int b=0;
    while(x)
    {
        if(x-(x/10)*10==9) {b=1;break;}
        x=x/10;
    }
    if(b==1) return 0;
    else return 1;
}
int main()
{
    long long unsigned a,b;
    scanf("%llu%llu",&a,&b);
    long long unsigned num=0;
    for(long long unsigned i=a;i<=b;i++)
    {
        if(i%9==0) num++;
        else if(miao(i)) num++;
    }
    printf("%llu",num);
    return 0;
}
