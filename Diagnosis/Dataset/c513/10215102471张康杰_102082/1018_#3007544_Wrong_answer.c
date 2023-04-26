#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define L 100
typedef struct
{
    int v[100],cnt;
}BIGINT;

int Strprocess(char a[],int b[]);

//void reverse(int a[],int len);

BIGINT mul(BIGINT S,BIGINT T);

BIGINT add(BIGINT S,int a);

void mul1(BIGINT S,int a);

int main()
{
    char input[L];
    int digit[L] = {0};
    int table[] = {1,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    scanf("%s",input);
    int len = Strprocess(input,digit);
    //reverse(digit,len);
    BIGINT base = {{1},1};
    BIGINT result = {{0},0};
    for(int i = 0;i < len;i++)
    {
        result = add(mul(result,base),digit[i]);
        mul1(base,table[i]);
    }
    for(int i = result.cnt - 1;i >= 0;i++)
        printf("%d",result.v[i]);
    putchar('\n');
    return 0;
}

int Strprocess(char a[],int b[])
{
    int i,len = strlen(a),cnt = 0;
    for(i = 0;i < len;i++)
    {
        if(a[i] == ',')
        {
            cnt++;
            continue;
        }
        else
            b[cnt] = b[cnt] * 10 + a[i] - '0';
    }
    cnt++;
    return cnt;
}

/* void reverse(int a[],int len)
{
    int i = 0,j = len - 1,temp;
    while(i < j)
    {
        temp = a[j];
        a[j] = a[i];
        a[i] = temp;
        i++;
        j--;
    }
} */

BIGINT mul(BIGINT S,BIGINT T)
{
    BIGINT R = {{0},S.cnt + T.cnt};
    for(int i = 0;i < T.cnt;i++)
    {
        int t,j,k;
        int carry = 0;
        for(j = 0;j < S.cnt;j++)
        {
            t = S.v[j] * T.v[i] + carry + R.v[i + j];
            R.v[i + j] = t % 10;
            carry = t / 10;
        }
        k = i + j;
        while(carry > 0)
        {
            t = carry + R.v[k];
            R.v[k] = t % 10;
            carry = t / 10;
            k++;
        }
    }
    if(R.v[S.cnt + T.cnt - 1] == 0)
        R.cnt--;
    return R;
}

void mul1(BIGINT S,int a)
{
    int i,carry = 0;
    for(i = 0;i < S.cnt;i++)
    {
        S.v[i] = S.v[i] * a + carry;
        carry = S.v[i] / 10;
        S.v[i] %= 10;
    }
    while(carry)
    {
        S.v[i] = S.v[i] + carry;
        carry = S.v[i] / 10;
        S.v[i] %= 10;
        i++;
        S.cnt++;
    }
}

BIGINT add(BIGINT S,int a)
{
    BIGINT R = {{0},0};
    int i,carry = 0,len = S.cnt;
    R.cnt = len;
    R.v[0] += a;
    for(i = 0;i < len;i++)
    {
        R.v[i] = R.v[i] + S.v[i]  + carry;
        carry = R.v[i] / 10;
        R.v[i] %= 10; 
    }
    while(carry)
    {
        R.v[i] += carry;
        carry = R.v[i] / 10;
        R.v[i] %= 10;
        i++;
        R.cnt++;
    }
    return R;
}