#include <stdio.h>
#include <stdlib.h>

typedef long long int LLD;

LLD llabs(LLD a)
{
    if(a < 0)
        return -a;
    else
        return a;
}

int main()
{
    LLD x,y,dis,temp = 1,cnt = 0;
    scanf("%lld %lld",&x,&y);
    dis = llabs(x) + llabs(y);
    if(dis % 2 == 0 && dis != 0)
    {
        printf("-1\n");
        return 0;
    }
    while(temp < dis)
    {
        temp *= 2;
        cnt++;
    }
    printf("%lld\n",cnt);
    return 0;
}