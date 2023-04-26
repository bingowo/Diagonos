#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define L 9001

typedef struct
{
    int cnt;
    int num[L];
    int cnt1;
    int output[L];
}BIG;

void Mutiple(BIG*a)
{
    int i,j,carry = 0;
    for(i = 0;i < a->cnt;i++)
    {
        for(j = 0;j < a->cnt1;j++)
        {
            a->output[i + j] = a->num[i]*a->output[j] + carry;
            carry = a->output[i + j] / 10; 
            a->output[i + j] %= 10;
        }
    }
    if(carry)
    {
        a->output[i + j - 1] += carry;
        a->cnt1 = i + j;        
    }
    else
        a->cnt1 = i + j - 1;
}

int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i < T;i++)
    {
        char A[11];
        int B,N;
        BIG bigint;
        memset(bigint.num,0,sizeof(int)*L);
        memset(bigint.output,0,sizeof(int)*L);
        scanf("%s %d %d",A,&B,&N);
        int j,len = strlen(A);
        bigint.cnt = len;
        bigint.cnt1 = len;
        for(j = 0;j < len;j++)
        {
            bigint.num[j] = A[len - j - 1] - '0';
            bigint.output[j] = A[len - j - 1] - '0';
        }
        for(j = 0;j < B - 1;j++)
            Mutiple(&bigint);
        printf("case #%d:\n",i);
        for(j = 0;j < N;j++)
        {
            printf("%d",bigint.output[j]);
        }
        putchar('\n');
    }
    return 0;   
}