#include <stdio.h>
#include <string.h>

typedef struct
{
    int cnt;//位数计数器
    int v[334];
}BIGINT;

void DIV2(BIGINT *n)//十进制转二进制
{
    int a = 0;
    if(n->v[n->cnt-1] < 2)
    {
        n->cnt--;
        a = 1;
    }
    for(int i = n->cnt-1; i >= 0; i--)
    {
        int t = 10 * a + n->v[i];
        n->v[i] = t / 2;
        a = t % 2;
    }
}
void MUL2ADD(BIGINT *n, int d)//二进制转十进制
{
    int carry = d;
    for(int i = 0; i < n->cnt; i++)
    {
        int t = carry + n->v[i] * 2;
        n->v[i] = t % 10;
        carry = t / 10;
    }
    if(carry > 0) n->v[n->cnt++] = carry;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int z = 0; z < t; z++)
    {
        char s0[334];
        BIGINT n;
        scanf("%s",s0);
        n.cnt = strlen(s0);
        for(int i = 0; i < n.cnt; i++)
            n.v[i] = s0[n.cnt - i - 1] - '0';//将字符转化为整数存储起来
        int s[334],cnt = 0;
        while(n.cnt > 0)//n.cnt!=cnt
        {
            s[cnt++] = n.v[0] % 2;
            DIV2(&n);
        }
        for(int i = 0; i < cnt; i++) MUL2ADD(&n,s[i]);
        if(n.cnt == 0)
        {
            n.cnt++;
        }
        printf("case #%d:\n",z);
        for(int i = n.cnt - 1; i >= 0; i--)
        {
            printf("%d",n.v[i]);
        }
        printf("\n");
    }
    return 0;
}
