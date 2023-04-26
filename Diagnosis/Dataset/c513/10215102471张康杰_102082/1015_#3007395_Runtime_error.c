#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define L 27

int Strprocess(char a[],int b[])
{
    int i,len = strlen(a),cnt = 0;
    for(i = len - 1;i >= 0;i--)
    {
        if(a[i] == ',')
            continue;
        else
            b[cnt++] = a[i] - '0';
    }
    return cnt;
}

int main()
{
    int T,i;
    scanf("%d",&T);
    int table[26] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    for(i = 0;i < T;i++)
    {
        char input1[L],input2[L];
        int digit1[L] = {0},digit2[L] = {0};
        scanf("%s %s",input1,input2);
        int len1 = Strprocess(input1,digit1);
        int len2 = Strprocess(input2,digit2);
        int len_max = (len1 > len2)?len1:len2,carry = 0,j;
        for(j = 0;j < len_max;j++)
        {
            digit1[j] = digit1[j] + digit2[j] + carry;
            carry = digit1[j] / table[j];
            digit1[j] %= table[j];
        }
        if(carry > 0)
        {
            digit1[j] += carry;
            len_max++;
        }
        printf("case #%d:\n",i);
        for(j = len_max - 1;j >= 0;j--)
            printf("%d%c",digit1[j],(j == 0)?'\n':',');
    }
    return 0;
}