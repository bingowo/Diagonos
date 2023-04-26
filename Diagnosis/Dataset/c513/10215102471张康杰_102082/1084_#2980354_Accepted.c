#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define L 15

void Mutiple(int a[],int b)
{
    int i,carry = 0;
    for(i = 0;i < L;i++)
    {
        a[i]  = a[i]*b + carry;
        carry = a[i] / 10;
        a[i] %= 10;
    }
}

int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i < T;i++)
    {
        int N;
        scanf("%d",&N);
        if(N == 0)
        {
            printf("case #%d:\n1\n",i);
            continue;
        }
        int output[L] = {2};
        for(int j = 0;j < N - 1;j++)
        {
            Mutiple(output,2);
        }
        int flag = 1;
        printf("case #%d:\n",i);
        for(int j = L - 1;j >= 0;j--)
        {
            if(flag && output[j] == 0)
                continue;
            else
            {
                flag = 0;
                printf("%d",output[j]);
            }
        }
        putchar('\n');

    }
}