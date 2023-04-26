#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct
{
    int cnt,
    v[101];
}BIGINT;

void DIV2(BIGINT *n)
{
    int carry=0,i;
    if (n->v[n->cnt-1]<2)
    {
        n->cnt--;
        carry=1;
    }
    for (i=n->cnt-1;i>=0;i--)
    {
        int t=10*carry+n->v[i];
        n->v[i]=t/2;
        carry=t%2;
    }
}
void MUL2ADD(BIGINT *n, int d)
{
    int carry=d,i;
    for (i=0;i<n->cnt;i++)
    {
        int t=carry+n->v[i]*2;
        n->v[i]=t%10;
        carry=t/10;
    }
    if (carry>0) n->v[n->cnt++]=carry;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int b=0;b<t;b++)
    {
        char line[102];
        int i;
        BIGINT n;
        scanf("%s", line);
        n.cnt = strlen(line);
        for (i = 0; i < n.cnt; i++)
            n.v[i] = line[n.cnt - i - 1] - '0';
        int bin[334], cnt = 0;
        printf("case #%d:\n",b);
        while (n.cnt > 0)
        {
            bin[cnt++] = n.v[0] % 2;
            DIV2(&n);
        }
        for (i = 0; i < cnt; i++)
            MUL2ADD(&n, bin[i]);
        if (n.cnt == 0)
        {
            n.cnt++;
        }
        for (i = n.cnt - 1; i >= 0; i--)
        {
            printf("%d", n.v[i]);
        }
        printf("\n");

    }
}
