#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define L 50
//迭代法
typedef struct
{
    int v[50],cnt;
}BIGINT;

void Add(BIGINT*a,BIGINT*b)
{
    int i,carry = 0;
    for(i = 0;i < (a->cnt > b->cnt)?a->cnt:b->cnt;i++)
    {
        a->v[i] = a->v[i] + b->v[i] + carry;
        carry = a->v[i] / 10;
        a->v[i] %= 10;
    }
    if(carry != 0)
    {
        a->v[i] += carry;
        a->cnt = (a->cnt > b->cnt)?a->cnt:b->cnt + 1;
    }
    else
        a->cnt = (a->cnt > b->cnt)?a->cnt:b->cnt + 1;
}

int main()
{
    int k,n,i;
    scanf("%d %d",&k,&n);
    BIGINT ar[n + 10];
    memset(ar,0,sizeof(BIGINT) * (n + 10));
    ar[11].v[0] = 1;
    ar[11].cnt = 1;
    for(i = 10;i <= n + 9;i++)
    {
        for(int j = 1;j <= k;j++)
            Add(&ar[i],&ar[i - j]);
    }
    int flag = 1;
    for(i = ar[n + 9].cnt - 1;i > 0;i--)
    {
        if(flag && ar[n + 9].v[i] == 0)
            continue;
        else
            printf("%d",ar[n + 9].v[i]);
    }
    printf("%d\n",ar[n + 9].v[0]);
    return 0;
}