#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define L 121

int cmp(const void*s1,const void*s2)
{
    if(**(char(*)[L])s1 == '-' && **(char(*)[L])s2 == '-')
        return strcmp(*(char(*)[L])s2 + 1,*(char(*)[L])s1 + 1);
    else if(**(char(*)[L])s1 == '-' || **(char(*)[L])s2 == '-')
        return **(char(*)[L])s1 - **(char(*)[L])s2;    
    else
        return strcmp(*(char(*)[L])s1,*(char(*)[L])s2);
}

void Sub(int output[],char a[],char b[])
{
    int i;
    int len1 = strlen(a),len2 = strlen(b);
    int num1[121] = {0},num2[121] = {0};
    for(i = 0;i < len1 - 1;i++)
    {
        num1[i] = a[len1 - i - 1] - '0'; 
    }
    if(a[len1 - 1] == '-')
        num1[i] == 0;
    else
        num1[i] == a[0] - '0';
    for(i = 0;i < len2 - 1;i++)
    {
        num2[i] == b[len2 - i - 1] - '0';
    }
    if(b[len1 - 1] == '-')
        num2[i] == 0;
    else
        num2[i] == b[0] - '0';
    if(a[0] == '-' && b[0] == '-')
    {
        for(i = 0;i < L;i++)
        {
            output[i] = output[i] + num2[i] - num1[i];
            if(output[i] < 0)
            {
                output[i] += 10;
                output[i + 1]--;
            }
        }
    }
    else if(a[0] != '-' && b[0] != '-')
    {
        for(i = 0;i < L;i++)
        {
            output[i] = output[i] + num1[i] - num2[i];
            if(output > 0)
            {
                output[i] += 10;
                output[i + 1]--;
            }
        }
    }
    else
    {
        int carry = 0;
        for(i = 0;i < L;i++)
        {
            output[i] = output[i] + num1[i] + num2[i] + carry;
            carry = output[i] / 10;
            output[i] %= 10;
        }
    }
}

int main()
{
    int n,i;
    scanf("%d",&n);
    char input[50][L];  
    for(i = 0;i < n;i++)
    {
        scanf("%s",input[i]);
    }
    qsort(input,n,sizeof(char(*)[L]),cmp);
    int output[L] = {0};
    Sub(output,input[n - 1],input[0]);
    int flag = 1;
    for(i = L - 1;i >= 0;i--)
    {
        if(flag && output[i] == 0)
            continue;
        else
        {
            flag = 0;
            printf("%d",output[i]);
        }
    }
    putchar('\n');
    return 0;
}