#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    int cnt;
    int v[100];
}BIGINT;

void Div(BIGINT*a)
{
    int i,carry,temp,b = a->cnt;
    for(i = 0;i < b;i++)
    {
        if(a->v[i] <2)
        {
            a->v[i] = 0;
            temp = a->v[i]*10 + a->v[i+1];
            carry = (temp % 2) * 5;
            a->v[i++] = temp / 2;
            if(i == a->cnt - 1)
                carry = 0;
            a->v[i+1] += carry;
            a->cnt--;
        }
        else
        {
            carry = a->v[i] % 2;
            a->v[i] /= 2;
            if(i == a->cnt - 1)
                carry = 0;
            a->v[i+1] += carry;
        }
    }

}

void Mutiple(int a[],int b,int length1)
{
    int carry = b,i;
    for(i = 0;i < length1;i++)
    {
        a[i] = a[i]*2 + carry;
        carry = a[i] / 10;
        a[i] = a[i] % 10;
    }
}

void Reverse(int a[],int b)
{
    int temp,i = 0,j = b - 1;
    while(i > j)
    {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        i++,j--;
    }
}

int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i < T;i++)
    {
        char line[101];
        int bin[334] = {0},cnt = 0;
        BIGINT big;
        scanf("%s",line);
        for(big.cnt = 0;big.cnt < strlen(line);big.cnt++)
        {
            big.v[big.cnt] = line[big.cnt] - '0';
        }
        while(big.cnt > 0)
        {
            bin[cnt++] = big.v[big.cnt - 1] % 2;
            Div(&big); 
        }
        Reverse(bin,cnt);       
        int output[100] = {0},carry;
        int j;
        for(j = 0;j < cnt;j++)
        { 
            Mutiple(output,bin[j],100);   
        }
        printf("case #%d:\n");
        int flag = 1;
        for(j = 99;j >= 0;j--)
        {
            if(output[j] == 0 && flag)
            {
                continue;
            }
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