#include <stdio.h>
#include <stdlib.h>
#define N 101
int Exp(int a[],int b)
{
    int carry = 0,i;
    for(i = 0;i < N;i++)
    {
        a[i] = a[i]*b + carry;
        carry = a[i] / 10;
        a[i] = a[i] % 10;
    }
    return carry;
}

int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i < T;i++)
    {
        int a,n,carry,flag = 1;
        scanf("%d %d",&a,&n);
        if(n == 0)
        {
            printf("case #%d:\n1\n");
            continue;
        }
        int output[N] = {a};
        for(int j = 0;j < n - 1;j++)
        {
            carry = Exp(output,a);
        }
        printf("case #%d:\n",i);
        for(int j = N - 1;j >= 0;j--)
        {
            if(carry)
            {
                printf("%d",carry);
                carry = 0;
            }
            else if(flag && output[j] == 0)
                continue;
            else
            {
                flag = 0;
                printf("%d",output[j]);
            }
        }
        putchar('\n');
    }
    return 0;
}