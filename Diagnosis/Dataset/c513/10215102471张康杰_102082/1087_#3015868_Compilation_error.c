#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define L 1100

typedef struct 
{
    int v[L],cnt;
}BIGINT;

void add(BIGINT*S,int pos);

void repeat(BIGINT*S);

int location(BIGINT S);

int judege(BIGINT S);

int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i < T;i++)
    {
        char input[L];
        BIGINT big = {{0},1};
        big.cnt = strlen(input);
        for(int j = 0;j < big.cnt;j++)
        {
            big.v[j] = input[big.cnt - j - 1] - '0';
        }
        repeat(&big);
        printf("case #%d:\n",i);
        for(int j = big.cnt - 1;j >= 0;j--)
            printf("%d",big.v[j]);
        putchar('\n');
    }
    return 0;
}

void add(BIGINT*S,int pos)
{
    S->v[pos]++;
    int i,carry = 0;
    for(i = pos;i < S->cnt;i++)
    {
        S->v[i] = S->v[i] + carry;
        if(S->v[i] < 10)
            break;
        carry = S->v[i] / 10;
        S->v[i] %= 10;
    }
    if(carry)
    {
        S->v[i] += carry;
        S->cnt++;
    }
}

void repeat(BIGINT*S)
{
    add(S,0);
    while(judege(*S) == 0)
    {
        int pos = location(*S),cnt = 0;
        add(S,pos);
        for(int i = pos - 1;i >= 0;i--)
        {
            if(cnt % 2 == 0)
                S->v[i] = 0;
            else
                S->v[i] = 1;
            cnt++;
        }
    }
}

int location(BIGINT S)
{
    int pos;
    for(int i = 1;i < S.cnt;i++)
    {
        if(S.v[i] == S.v[i - 1])
            continue;
        else
        {
            return i;
        }
    }
}

int judge(BIGINT S)
{
    for(int i = 1;i < S.cnt;i++)
    {
        if(S.v[i] == S.v[i - 1])
            return 0;
    }
    return 1;
}