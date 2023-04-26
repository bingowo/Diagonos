#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100
typedef struct {
    int cnt;// 存位数
    int v[N];
}BIGINT;

// 大整数*大整数
BIGINT mul(BIGINT S, BIGINT T)
{
    BIGINT R = { S.cnt + T.cnt,{0} };
    //printf("R.cnt   %d\n",R.cnt);
    for (int i = 0; i < T.cnt; ++i)
    {
        int t, k, j;
        int carry = 0;
        for (j = 0; j < S.cnt; ++j)
        {
            t = S.v[j] * T.v[i] + carry + R.v[i + j];
            R.v[i + j] = t % 10;
            carry = t / 10;
        }
        k = i + j;
        while (carry > 0)
        {
            t = carry + R.v[k];
            R.v[k] = t % 10;
            carry = t / 10;
            k++;
        }
    }
    if (R.v[S.cnt + T.cnt - 1] == 0)  R.cnt--;
    return R;
}

// int 转化为bigint！！！！！！倒着存！！！！！！！
BIGINT int2BIG(int x)
{
    BIGINT R = { 0,{0} }; // 0 的特殊表示
    do {
        R.v[R.cnt++] = x % 10;
        x = x / 10;
    } while (x > 0);
    return R;
}

void DIV2(BIGINT* n)
{
    int carry = 0;
    if (n->v[n->cnt - 1] < 2) n->cnt--, carry = 1;
    for (int i = n->cnt - 1; i >= 0; i--)
    {
        int t = 10 * carry + n->v[i];
        n->v[i] = t / 2;
        carry = t % 2;
    }
}

BIGINT ADD(BIGINT n, int a)
{
    int b = n.v[0] + a;
    int i = 0;
    while (n.v[i] == 9) ++i;
    n.v[i] = b / 10;
    n.v[0] = b % 10;
    if (i >= n.cnt) n.cnt++;
    return n;
}

int main()
{ 
    int T;
    scanf("%d", &T);
    BIGINT two = { 1,{2} };
    for (int cas = 0; cas < T; ++cas)
    {
        BIGINT ans = { 0,{0} };
        char num[105] = { 0 };
        BIGINT NUM;
        scanf("%s", num);
        if (num[0] == '0')
        {
            printf("case #%d:\n", cas);
            printf("0\n");
            continue;
        }
        NUM.cnt = strlen(num);
        int BIR[335] = { 0 };
        for (int i = NUM.cnt-1,j = 0; i >= 0; --i,++j)  NUM.v[i] = num[j] - '0';
        int d = 0;
        while (NUM.cnt != 0)
        {
            if (NUM.v[0]%2 == 1)  BIR[d] = 1;
            DIV2(&NUM);
            d++;
        }
        int m = 0;
        while (BIR[m] == 0) ++m;
        for (int i = m-1; i <d ; ++i)
        {
            ans = mul(two, ans);
            ans = ADD(ans, BIR[i]);
        }
        printf("case #%d:\n", cas);
        for (int i = ans.cnt - 1; i >= 0; --i)
            printf("%d", ans.v[i]);
        printf("\n");
    }
    return 0;
 }
