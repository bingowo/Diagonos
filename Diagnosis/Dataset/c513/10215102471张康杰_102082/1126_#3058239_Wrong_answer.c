#include <stdio.h>
#include <stdlib.h>
#define L 30
typedef unsigned long long int LLU;

typedef struct
{
    int v[L],cnt;
}BIGINT;


int cmp(const void*a,const void*b)
{
    return *(LLU*)a - *(LLU*)b;
}

BIGINT Llu2Str(LLU a);

BIGINT BigAdd(BIGINT S,BIGINT T);

int main()
{
    int n,i;
    scanf("%d",&n);
    LLU ar[n],temp;
    for(i = 0;i < n;i++)
        scanf("%llu",&ar[i]);
    temp = ar[0];
    for(i = 1;i < n;i++)
        temp ^= ar[i];
    if(temp != 0)
    {
        printf("-1");
        return 0;
    }
    qsort(ar,n,sizeof(LLU),cmp);
    BIGINT sum = {{0},0};
    for(i = 1;i < n;i++)
    {
        sum = BigAdd(sum,Llu2Str(ar[i]));
    }
    for(i = sum.cnt - 1;i >= 0;i--)
        printf("%d",sum.v[i]);
    return 0;
}

BIGINT Llu2Str(LLU a)
{
    BIGINT temp = {{0},0};
    int remain;
    while(a != 0)
    {
        remain = a % 10;
        a /= 10;
        temp.v[temp.cnt++] = remain;
    }
    return temp;
}

BIGINT BigAdd(BIGINT a,BIGINT b)
{
    int i,carry = 0,cnt = (a.cnt > b.cnt)?a.cnt:b.cnt;
    BIGINT temp = {{0},cnt};
    for(i = 0;i < cnt;i++)
    {
        temp.v[i] = a.v[i] + b.v[i] + carry;
        carry = temp.v[i] / 10;
        temp.v[i] /= 10;
    }
    if(carry)
    {
        temp.v[i] += carry;
        temp.cnt++;
    }
    return temp;
}
