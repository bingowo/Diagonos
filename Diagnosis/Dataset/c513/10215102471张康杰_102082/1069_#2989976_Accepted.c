#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define L 7
void reverse(int a[],int b[],int len)
{
    int i;
    for(i = 0;i < len;i++)
    {
        b[i] = a[len - i - 1];
    }
}

int cmp(int a[],int b[])
{
    int i;
    for(i = 0;i < L;i++)
    {
        if(a[i] != b[i])
            return 0;
    }
    return 1;
}

int add(int a[],int b[],int len)
{
    int i,carry = 0;
    for(i = 0;i < len;i++)
    {
        a[i] = a[i] + b[i] + carry;
        carry = a[i] / 10;
        a[i] %= 10;
    }
    if(carry)
    {
        len++;
        a[i] += carry;
    }
    return len;
}

int main()
{
    int ar[L] = {0},ar_rev[L] = {0};
    char input[L];
    int cnt = 0,i;
    scanf("%s",input);
    int len = strlen(input);
    for(i = 0;i < len;i++)
    {
        ar[i] = input[len - i - 1] - '0';
        ar_rev[i] = input[i] - '0';
    }
    while(!cmp(ar,ar_rev))
    {

        len = add(ar,ar_rev,len);
        cnt++;
        reverse(ar,ar_rev,len);
    }
    printf("%d ",cnt);
    int flag = 1;
    for(i = L - 1;i >= 0;i--)
    {
        if(ar[i] == 0 && flag)
            continue;
        else
        {
            flag = 0;
            printf("%d",ar[i]);
        }
    }
    putchar('\n');
    return 0;

}