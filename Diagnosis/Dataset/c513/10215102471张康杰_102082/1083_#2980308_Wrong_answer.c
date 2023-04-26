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
        int bigint[L] = {0},j,cnt = 0,num = 0;
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
        printf("%case #%d:\n",i);
        for(j = 0;j < L;j++)
        {
            if(bigint[j] == 0)
            {
                cnt++;
            }
            else
            {
                break;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}