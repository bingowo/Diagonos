#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define L 31

typedef long long int LLD;

LLD GCD(LLD x,LLD y)
{
    LLD temp,r;
    if(x < y)
    {
        temp = x;
        x = y;
        y = temp;
    }
    r = x % y;
    while(r != 0)
    {
        x = y;
        y = r;
        r = x % y;
    }
    return y;
}

LLD llabs(LLD a)
{
    if(a < 0)
        a = -a;
    return a;
}

int main()
{
    char input[L];
    scanf("%s",input);
    int i,len = strlen(input);
    char state = 'l';
    LLD part1 = 0,part2 = 0,base = 1;
    for(i = 0;i < len;i++)
    {
        if(input[i] == '.')
        {
            state = 'r';
            continue;
        }
        if(state == 'l')
        {
            if(input[i] == '0' || input[i] == '1')
                part1 = part1 * 3 + input[i] - '0';
            else if(input[i] == '2')
                part1 = part1 * 3 - 1;
        }
        else if(state == 'r')
        {
            if(input[i] == '0' || input[i] == '1')
                part2 = part2 * 3 + input[i] - '0';
            else if(input[i] == '2')
                part2 = part2 * 3 - 1;
            base *= 3;
        }
    }
    LLD common;
    if(part2 != 0)
        common = GCD(llabs(part2),llabs(base));
    if(part1 > 0)
    {
        if(part2 > 0)
            printf("%lld %lld %lld",part1,part2/common,base/common);
        else if(part2 == 0)
            printf("%lld",part1);
        else if(part2 < 0)
        {
            if(part2 == 1)
                printf("%lld %lld",base/common - part2/common,base/common);
            else
                printf("%lld %lld %lld",part1 - 1,base/common + part2/common,base/common);
        }
    }
    else if(part1 == 0)
    {
        if(part2 == 0)
            printf("0");
        else
            printf("%lld %lld",part2/common,base/common);
    }
    else if(part1 < 0)
    {
        if(part2 < 0)
            printf("%lld %lld %lld",part1,-part2/common,base/common);
        else if(part2 == 0)
            printf("%lld",part1);
        else if(part2 > 0)
        {
            if(part1 == -1)
                printf("%lld %lld",part2/common - base/common,base/common);
            else
                printf("%lld %lld %lld",part1 + 1,base/common - part2/common,base/common);
        }
    }
    putchar('\n');
    return 0;
}