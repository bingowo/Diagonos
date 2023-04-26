#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 501

void Substract(int ar1[],int ar2[],int len)
{
    int i,carry = 0,flag;
    for(i = len;i >= 0;i--)
        {
            if(ar1[i] > ar2[i])
            {
                flag = 1;
                break;
            }
            else if(ar1[i] == ar2[i])
                continue;
            else
            {
                flag = 0;
                break;
            }            
        }
    if(i == -1)
        flag = 1;
    if(flag)
    {
        for(i = 0;i < len;i++)
        {
            ar1[i] = ar1[i] - ar2[i];
            if(ar1[i] < 0)
            {
                ar1[i] += 10;
                ar1[i + 1]--;
            }
        }
    }
    else
    {
        putchar('-');
        for(i = 0;i < len;i++)
        {
            ar1[i] = ar2[i] - ar1[i];
            if(ar1[i] < 0)
            {
                ar1[i] += 10;
                ar1[i + 1]--;
            }
        }
    }
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
        {
            len = length1;
        }
        else
        {
            len = length2;
        }
        Substract(ar1,ar2,len);
        int flag1 = 1; 
        for(i = len;i > 0;i--)
        {
            if(ar1[i] == 0 && flag1)
                continue;
            else
            {
                printf("%d",ar1[i]);
                flag1 = 0;
            }
        }
        printf("%d",ar1[0]);
        putchar('\n');
    }
    return 0;
}