#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 501

int Substract(int ar1[],int ar2[],int len)
{
    int i,carry = 0;
    for(i = 0;i < len;i++)
    {
        ar1[i] = ar1[i] - ar2[i];
        if(ar1[i] < 0)
        {
            ar1[i] += 10;
            ar1[i + 1]--;
        }
    }
    if(ar1[len] < 0)
        return 1;
    else
        return 0;
}

int main()
{
    char num1[N],num2[N];
    while(scanf("%s %s",num1,num2) != EOF)
    {
        int i;
        int length1 = strlen(num1),length2 = strlen(num2);
        int ar1[N] = {0},ar2[N] = {0};
        for(i = 0;i < length1;i++)
        {
            ar1[i] = num1[length1 - i - 1] - '0';
        }
        for(i = 0;i < length2;i++)
        {
            ar2[i] = num2[length2 - i - 1] - '0';
        }
        int len;
        if(length1 > length2)
            len = length1;
        else
            len = length2;
        int flag = Substract(ar1,ar2,len);
        if(flag)
        {
            printf("-");
            for(i = 0;i < len;i++)
                ar1[i] = 0;
            ar1[len] = 1;
            Substract(ar1,ar2,len);
        }
        int flag1 = 1;
        for(i = len;i >= 0;i--)
        {
            if(ar1[i] == 0 && flag1)
                continue;
            else
            {
                printf("%d",ar1[i]);
                flag1 = 0;
            }
        }
        putchar('\n');
    }
    return 0;
}