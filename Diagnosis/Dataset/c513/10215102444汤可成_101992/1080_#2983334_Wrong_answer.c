#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct num
{
    int cnt;
    int v[101];
}num;

void DIV2(num* n)
{
    int carry = 0;
    int i = 0;
    if(n->v[n->cnt-1]<2) //最高位为1, 除2后位数变少
    {
        n->cnt--;
        carry = 1;
    }
    for(i = n->cnt-1; i>=0; i--)
    {
        int t = 10*carry + n->v[i];
        n->v[i] = t/2;
        carry = t%2;
    }
}

void MUL2ADD(num *n, int d)
{
    int carry = d,i;
    for(i = 0; i<n->cnt; i++)
    {
        int t = carry+n->v[i]*2;
        n->v[i] = t%10;
        carry = t/10;
    }
    if(carry>0) n->v[n->cnt++] = carry;
}

int main()
{
    int T = 0;
    scanf("%d", &T);
    int i = 0;
    for(i = 0; i<T; i++)
    {
        num n = {0};
        char line[102] = {0};

        //输入
        scanf("%s", line);
        n.cnt = strlen(line);
        for(int j = 0; j<n.cnt; j++)  //由低位至高位存放
        {
            n.v[j] = line[n.cnt-i-1] - '0';
        }
        int bin[334] = {0};
        int cnt = 0;

        //十变二
        while(n.cnt>0)
        {
            bin[cnt++] = n.v[0]%2;
            DIV2(&n);
        }

        //二变十
        for(int j = 0; j<cnt; j++)
        {
            MUL2ADD(&n, bin[j]);
        }

        //输出
        printf("case #%d:\n", i);
        if(n.cnt == 0) n.cnt++;
        for(int j = n.cnt-1; j>=0; j--)
        {
            printf("%d", n.v[j]);
        }
        printf("\n");
    }
    return 0;
}
