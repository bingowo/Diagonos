#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 105
typedef struct {
    int cnt;// 存位数
    int flat;
    int v[N];
}BIGINT;

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
    if (n->cnt == 0) n->v[0] = 0;
}

BIGINT ADD(BIGINT n, int a)
{
    //int b = n.v[0] + a;
    int i = 0;
    int carry = a;
    while (carry > 0) {
        int b = n.v[i] + carry;
        n.v[i] = b % 10;
        carry = b / 10;
        ++i;
    }
    if (i > n.cnt) n.cnt++;
    return n;
}

int main()
{
    BIGINT two = { 1,1,{2} };
    BIGINT ans = { 0,{0} };
    char num[105] = { 0 };
    BIGINT NUM;
    scanf("%s", num);
    if (num[0] == '0') {
        printf("0\n");
        return 0;
    }
    NUM.cnt = strlen(num);
    if (num[0] == '-') NUM.flat = -1, NUM.cnt--;
    else NUM.flat = 1;
    int BIR[335] = { 0 };
    for (int i = 0, j = strlen(num)-1;i<NUM.cnt; ++i, --j)  NUM.v[i] = num[j] - '0';
    int d = 0;
    while (NUM.cnt != 0)
    {
        if (NUM.v[0] % 2 == 1) BIR[d] = 1;
        DIV2(&NUM);
        d++;
        NUM.flat = 0 - NUM.flat;
        if (BIR[d-1] == 1)
        {
            if (NUM.flat == 1) NUM = ADD(NUM, 1);
        }
        if (NUM.cnt == 0) break;
    }
    for (int i = d-1; i >= 0; --i)
        printf("%d", BIR[i]);
    printf("\n");
    return 0;
}
