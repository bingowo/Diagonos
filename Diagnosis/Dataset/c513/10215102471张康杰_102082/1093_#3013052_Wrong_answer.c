#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define L 102

typedef struct
{
    int v[L],cnt;
}BIGINT;


int main()
{
    char input[L];
    scanf("%s",input);
    BIGINT big = {{0},1};
    int len = strlen(input),i,sum = 0,carry = 0,flag = 1;
    for(i = 0;i < len;i++)
    {
        big.v[i] = input[len - i - 1] - '0';
        sum += big.v[i];
    }
    big.cnt = len;
    big.v[0] += 1;
    sum += 1;
    if(sum % 9 != 0)
    {
        for(i = 0;i < big.cnt;i++)
        {
            if(big.v[i] != 9);
            else
            {
                flag = 0;
                break;
            }
        }
        if(flag)
        {
            for(i = big.cnt - 1;i >= 0;i--)
                printf("%d",big.v[i]);
            putchar('\n');
            return 0;
        }
    }
    sum = 0;
    int pos;
    for(i = big.cnt - 1;i >= 0;i--)
    {
        /* big.v[i] += carry;
        carry = big.v[i] / 9;
        big.v[i] %= 9; */
        if(big.v[i] == 9)
        {
            big.v[i] = 0;
            big.v[i + 1] += 1;
            pos = i + 1;
            if(pos == big.cnt)
                big.cnt++;
        }
    }
    for(i = 0;i < pos;i++)
        big.v[i] = 0;
    for(i = 0;i < big.cnt;i++)
        sum += big.v[i];
    if(sum % 9 != 0)
    {
        for(i = big.cnt - 1;i >= 0;i--)
            printf("%d",big.v[i]);
        putchar('\n');
        return 0;
    }
    else
    {
        while(sum % 9 == 0)
        {
            big.v[0] += 1;
            sum += 1;
            if(big.v[0] == 9)
            {
                for(i = 0;i < big.cnt;i++)
                {
                    big.v[i] += carry;
                    if(big.v[i] < 9)
                    {
                        carry = 0;
                        break;
                    }
                    carry = big.v[i] / 9;
                    big.v[i] %= 9;
                }
                if(carry)
                {
                    big.v[i] += carry;
                    big.cnt++;
                }
            }
            sum = 0;
            for(i = 0;i < big.cnt;i++)
                sum += big.v[i];
        }
        for(i = big.cnt - 1;i >= 0;i--)
            printf("%d",big.v[i]);
        putchar('\n');
    }
    return 0;
}