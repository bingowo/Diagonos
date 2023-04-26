#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define state1 0
#define state2 1
#define state3 2

typedef unsigned long long int LLU;

//字符串处理函数
int StrProcess(char a[],LLU*b,LLU*c,LLU*d);

LLU GCD(LLU x,LLU y)
{
    if(x < y)
    {
        LLU temp = y;
        y = x;
        x = temp;
    }
    LLU re = x % y;
    while(re != 0)
    {
        x = y;
        y = re;
        re = x % y;
    }
    return y;
}

int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i < T;i++)
    {
        char input[17];
        scanf("%s",input);

        LLU interger = 0,base = 1,loop = 0;

        int cnt = StrProcess(input,&interger,&base,&loop);

        LLU up,down,base_loop = 0;

        LLU common;

        printf("case #%d:\n",i);
        if(loop == 0)
        {
            common = GCD(interger,base);
            printf("%llu/%llu\n",interger/common,base/common);
        }
        else
        {
            for(int j = 0;j < cnt;j++)
                base_loop = base_loop * 10 + 9;
            base_loop *= base;
            common = GCD(loop,base_loop);
            loop /= common,base_loop /= common;
            common = GCD(interger,base);
            interger /= common,base /= common;
            up = interger * base_loop + loop * base;
            down = base_loop * base;
            common = GCD(up,down);
            printf("%llu/%llu\n",up/common,down/common);
        }
    }
    return 0;
}

int StrProcess(char a[],LLU*b,LLU*c,LLU*d)
{
    int len = strlen(a),j;
    int state = state1;
    int cnt = 0;

    for(j = 0;j < len;j++)
    {
        if(a[j] == '.')
        {
            state = state2;
            continue;
        }
        else if(a[j] == '[')
        {
            state = state3;
            continue;
        }
        else if(a[j] == ']')
            break;
        switch(state)
        {
        case state1:
            *b = *b * 10 + a[j] - '0';
            break;
        case state2:
            *b = *b * 10 + a[j] - '0';
            *c *= 10;
            break;
        case state3:
            *d = *d * 10 + a[j] - '0';
            cnt++;
            break;
        }
    }
    return cnt;
}
