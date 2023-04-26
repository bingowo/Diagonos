#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define N 502
void mul(int a[],int b)
{
    int i,carry = 0;
    for(i = 0;i < N;i++)
    {
        a[i] = a[i] * b + carry;
        carry = a[i] / 10;
        a[i] %= 10;
    }
}

int main()
{
    int i,len;
    char word[1001];
    int outcome[N] = {1};
    scanf("%s",word);
    len = strlen(word);
    for(i = 0;i < len;i++)
    {
        int cnt = 0;
        if(i == 0)
        {
            if(word[i] != word[i + 1])
                cnt = 2;
            else cnt = 1;
        }
        else if(i == len - 1)
        {
            if(word[i] != word[i - 1])
                cnt = 2;
            else 
                cnt = 1;
        }
        else
        {
            for(int j = 'a';j <= 'z';j++)
            {
                if(j == word[i] || j == word[i - 1] || j == word[i + 1])
                    cnt++;
            }
        }
        mul(outcome,cnt);
    }
    int flag = 1;
    for(i = N - 1;i >= 0;i--)
    {
        if(flag && outcome[i] == 0)
            continue;
        else
        {
            flag = 0;
            printf("%d",outcome[i]);
        }
    }
    putchar('\n');
}