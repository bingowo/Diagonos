#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define N 101

//存放大数据
typedef struct
{
    int sign;
    int cnt;
    int v[N];
}BigInt;

//转换
BigInt trim(char*s)
{
    BigInt R = {1,0,{0}};
    int i = 0;
    if(s[i] == '-')
    {
        R.sign = -1;
        i++;
    }
    int len = strlen(s);
    int x = 0;
    for(int j = len - 1;j >= i;j--)
    {
        R.v[x++] = s[j] - '0';
        R.cnt++;
    }
    return R;
}
//除以2
void chuer(BigInt* R)
{
    int carry = 0;
    if(R->v[R->cnt - 1] < 2)
    {
        carry = 1;
        R->cnt--;
    }
    for(int i = R->cnt - 1;i >= 0;i--)
    {
        int t = carry*10 + R->v[i];
        R->v[i] = t / 2;
        carry = t % 2;
    }
}

//加一
void addone(BigInt* R)
{
    int carry = 0,i = 1;
    R->v[0] = R->v[0] + 1;
    carry = R->v[0] / 10;
    R->v[0] = R->v[0] % 10;

    while(carry != 0 && i < R->cnt)
    {
        R->v[i] = carry + R->v[i];
        carry = R->v[i] / 10;
        R->v[i] = R->v[i] % 10;
        i++;
    }
    if(carry != 0)
    {
        R->v[i] = carry;
        R->cnt++;
    }
}


int main()
{
    char s[N];
    int p[400] = {0};
    scanf("%s",s);
    BigInt R = trim(s);
    int state = (R.sign > 0) ? 1 : -1;
    int i = 0;
    while(R.cnt > 0)
    {
        int temp = R.v[0] % 2;
        p[i++] = temp;
        chuer(&R);
        if(state == -1 && temp)
        {
            if(R.cnt == 0)
            {
                R.cnt++;
                R.v[0] = 1;
            }
            else
                addone(&R);
        }
        state = -state;
    }


    for(int j = i - 1;j >= 0;j--)
    {
        printf("%d",p[j]);
    }

    return 0;
}
