#include <stdio.h>
#include <stdlib.h>
#define L 301

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
        int bigint[L] = {0},j,cnt = 0;
        char input[1001];
        int a = atoi(input);
        scanf("%s",input);
        for(j = strlen(input) - 1;j >= 0;j--)
        {
            bigint[cnt++] = input[j] - '0';
        }
        for(j = 1;j < a;j++)
        {
            Mutiple(bigint,j);
        }
        int flag = 1;
        for(j = L - 1;j >= 0;j--)
        {
            if(flag && bigint[j] == 0)
                continue;
            else
            {
                flag = 0;
                printf("%d",bigint[j]);
            }
        }
        putchar('\n');
        return 0;

    }
}