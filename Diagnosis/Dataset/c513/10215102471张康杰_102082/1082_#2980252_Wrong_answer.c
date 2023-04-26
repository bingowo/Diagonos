#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define L 500
void Parallel(int a[],char b[])
{
    int i,pos,length = strlen(b),l;
    for(pos = 0;pos < length;pos++)
    {
        if(b[pos] == '.')
            break;
    }
    for(i = pos + 1,l = L;i < length;i++)
    {
        a[l++] = b[i] - '0';
    }
    for(i = pos - 1,l = L;i >= 0;i--)
    {
        a[--l] = b[i] - '0';
    }
}

int Add(int a[],int b[],int N)
{
    int i,carry = 0;
    for(i = 2*L;i >= L + N;i--)
    {
        a[i] = a[i] + b[i] + carry;
        carry = a[i] / 10;
        a[i] %= 10;
    }
    if(a[i + 1] >= 5)
    {
        a[i]++;
    }
    for(i;i >= 0;i--)
    {
        a[i] = a[i] + b[i] + carry;
        carry = a[i] / 10;
        a[i] %= 10;
    }
    return carry;
}

int main()
{
    char  A[L],B[L];
    int N;
    scanf("%s %s %d",A,B,&N);
    int A1[2*L + 1] = {0},B1[2*L + 1] = {0},carry,flag = 1;
    Parallel(A1,A);
    Parallel(B1,B);
    carry = Add(A1,B1,N);
    if(carry > 0)
        printf("%d",carry);
    for(int i = 0;i < L + N;i++)
    {
        if(flag && A1[i] == 0)
        {
            continue;
        }
        else if(i == L)
        {
            putchar('.');
            printf("%d",A1[i]);
            flag = 0;
        }
        else
        {
            flag = 0;
            printf("%d",A1[i]);
        }
    }
    putchar('\n');
    return 0;

}