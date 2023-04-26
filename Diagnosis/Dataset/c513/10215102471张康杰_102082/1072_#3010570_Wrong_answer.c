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

LLD llpow(LLD a,LLD b)
{
    LLD result = 1;
    for(int i = 0;i < b;i++)
        result *= a;
    return result;
}

void Path(LLD x,LLD y,LLD steps)
{
    if(steps == 0)
        return;
    if(llabs(x) > llabs(y))
    {
        if(x > 0)
        {
            Path(x - llpow(2,steps - 1),y,steps - 1);
            putchar('E');
        }
        else
        {
            Path(x + llpow(2,steps - 1),y,steps - 1);
            putchar('W');
        }
    }
    else
    {
        if(y > 0)
        {
            Path(x,y - llpow(1,steps - 1),steps - 1);
            putchar('N');
        }
        else
        {
            Path(x,y + llpow(1,steps - 1),steps - 1);
            putchar('S');
        }
    }
}

int main()
{
    LLD x,y,dis,temp = 1,steps = 0;
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
        steps++;
    }
    printf("%lld\n",steps);
    Path(x,y,steps);
    putchar('\n');
    return 0;
}