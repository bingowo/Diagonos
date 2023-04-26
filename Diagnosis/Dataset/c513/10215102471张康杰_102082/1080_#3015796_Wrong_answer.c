#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    int cnt;
    int v[100];
}BIGINT;

void Div(BIGINT*a)
{
    int i,carry = 0,b = a->cnt,temp;
    for(i = b - 1;i > 0;i--)
    {
        temp = a->v[i] * 10 / 2;
        a->v[i] = temp / 10 + carry;
        carry = temp % 10;
    }
    a->v[0] = a->v[0] / 2 + carry;
    if(a->v[a->cnt - 1] == 0)
        a->cnt--;
}

void Mutiple(BIGINT*a,int b)
{
    int carry = 0,i;
    for(i = 0;i < a->cnt;i++)
    {
        a->v[i] = a->v[i]*2;
    }
    a->v[0] += b;
    for(i = 0;i < a->cnt;i++)
    {
        a->v[i] = (a->v[i] + carry) % 10;
        carry = a->v[i] / 10;
    }
    if(carry)
    {
        a->v[i] += carry;
        a->cnt++;
    }
}

int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i < T;i++)
    {
        char line[101];
        int bin[334] = {0},cnt = 0,len;
        BIGINT big = {0,{0}};
        scanf("%s",line);
        len = strlen(line);
        for(int j = 0;j < len;j++)
        {
            big.v[j] = line[len - j - 1] - '0';
        }
        big.cnt = len;
        while(big.cnt > 0)
        {
            bin[cnt] = big.v[0] % 2;
            cnt++;
            Div(&big); 
        }   
        BIGINT output = {1,{0}};
        int j;
        for(j = 0;j < cnt;j++)
        { 
            Mutiple(&output,bin[j]);   
        }
        printf("case #%d:\n",i);
        for(j = output.cnt - 1;j >= 0;j--)
        {
            printf("%d",output.v[j]);
        }
        putchar('\n');
    }
    return 0;
}