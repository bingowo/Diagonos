#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef unsigned long long int LLU;

int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i < T;i++)
    {
        int exp,flag = 0;
        LLU n;
        scanf("%llu",&n);
        if(n == 1)
        {
            printf("1 is powerless.\n");
            continue;
        }
        printf("%llu",n);
        for(exp = 2;exp <= 33;exp++)
        {
            int j;
            for(int i = 2;(int)pow(i,exp) <= n;i++);
            LLU L = 0,R = i,M;
            while(R - L > 1)
            {
                M = (L + R) / 2;
                if((LLU)pow(M,exp) < n)
                {
                    L = M;
                }
                else if((LLU)pow(M,exp) == n)
                {
                    flag = 1;
                    printf("=%llu^%d",M,exp);
                    L = M;
                    break;
                }
                else
                {
                    R = M;
                }
            }
        }
        if(exp == 34 && flag == 1)
            putchar('\n');
        if(!flag)
        {
            printf(" is powerless.\n");
        }
    }
    return 0;
}
