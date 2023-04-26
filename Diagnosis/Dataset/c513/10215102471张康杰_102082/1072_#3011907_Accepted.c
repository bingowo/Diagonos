#include <stdio.h>
#include <stdlib.h>

typedef long long int LLD;

typedef unsigned long long int ULL;

typedef struct
{
    int x[50],y[50];
}STEP;

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
    STEP steps = {{0},{0}};
    LLD total = llabs(x) + llabs(y);
    int bi[100] = {0},i,cnt1 = 0;
    while(total != 0)
    {
        bi[cnt1++] = total & 1;;
        total = (ULL)total >> 1;
    }
    for(i = cnt1 - 1;i >= 0;i--)
    {
        if(bi[i] == 1)
            continue;
        else
        {
            bi[i--] = 1;
            for(i;i >= 0;i--)
            {
                if(bi[i] == 0)
                    bi[i] = -1;
                else
                {
                    bi[i] = -1;
                    break;
                }
            }
        }
    }
    LLD temp_x = llabs(x),temp_y = llabs(y);
    i = 0;
    while(temp_x != 0)
    {
        if(temp_x % llpow(2,i + 1) == 0)
            steps.x[i] = 0;
        else
        {
            steps.x[i] = bi[i];
            temp_x = temp_x - llpow(2,i) * bi[i]; 
        }
        i++;
    }
    i = 0;
    while(temp_y != 0)
    {
        if(temp_y % llpow(2,i + 1) == 0)
            steps.y[i] = 0;
        else
        {
            steps.y[i] = bi[i];
            temp_y = temp_y - llpow(2,i) * bi[i]; 
        }
        i++;
    }
    for(i = 0;i < cnt1;i++)
    {
        if(x >= 0 && y >= 0)
        {
            if(steps.x[i] == 0)
            {
                if(steps.y[i] == 1)
                    putchar('N');
                else
                    putchar('S');
            }
            else if(steps.x[i] == 1)
                putchar('E');
            else
                putchar('W');
        }
        else if(x >= 0 && y <= 0)
        {
            if(steps.x[i] == 0)
            {
                if(steps.y[i] == 1)
                    putchar('S');
                else
                    putchar('N');
            }
            else if(steps.x[i] == 1)
                putchar('E');
            else
                putchar('W');
        }
        else if(x <= 0 && y >= 0)
        {
            if(steps.x[i] == 0)
            {
                if(steps.y[i] == 1)
                    putchar('N');
                else
                    putchar('S');
            }
            else if(steps.x[i] == 1)
                putchar('W');
            else
                putchar('E');
        }
        else if(x <= 0 && y <= 0)
        {
            if(steps.x[i] == 0)
            {
                if(steps.y[i] == 1)
                    putchar('S');
                else
                    putchar('N');
            }
            else if(steps.x[i] == 1)
                putchar('W');
            else
                putchar('E');
        }
    }
    putchar('\n');
    return 0;
}