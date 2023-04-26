#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define L 4000

typedef struct 
{
    int v[L],cnt,signal;
}BIGINT;

typedef struct 
{
    BIGINT re;
    BIGINT im;
}Complex;

void Strprocess(Complex*T,char input[]);

Complex pow_Complex(Complex T,int n);

Complex Muti_Complex(Complex a,Complex b);

BIGINT mul_bigint(BIGINT S,BIGINT T);

BIGINT add_bigint(BIGINT S,BIGINT T);

BIGINT add(BIGINT S,BIGINT T);

BIGINT sub(BIGINT S,BIGINT T);

int cmp(BIGINT S,BIGINT T);

int main()
{
    char input[L];
    int n;
    scanf("%s %d",input,&n);
    Complex T = {{{0},0,1},{{0},0,1}};
    Strprocess(&T,input);
    T = pow_Complex(T,n);
    int flag = 1,flag1 = 0,flag2 = 0,i;
    if(n == 0)
    {
        putchar('1');
        putchar('\n');
        return 0;
    }
    if(T.re.signal == -1)
        putchar('-');
    for(i = T.re.cnt - 1;i >= 0;i--)
    {
        if(flag && T.re.v[i] == 0)
            continue;
        else
        {
            flag = 0;
            flag1 = 1;
            printf("%d",T.re.v[i]);
        }
    }
    flag = 1;
    if(T.im.signal == -1)
        putchar('-');
    else if(T.im.signal == 1 && flag1 != 0)
        putchar('+');
    for(i = T.im.cnt - 1;i >= 0;i--)
    {
        if(flag && T.im.v[i] == 0)
            continue;
        else
        {
            if(flag == 1 && i == 0 && T.im.v[0] == 1);
            else
                printf("%d",T.im.v[i]);
            flag = 0;
            flag2 = 1;
            if(i == 0)
                putchar('i');
        }
    }
    if(flag1 == 0 && flag2 == 0)
        putchar('0');
    putchar('\n');
    return 0;
}

void Strprocess(Complex*T,char input[])
{
    int len,i;
    int cnt = 0,cnt1 = 0;
    char state = 'r',state1 = 'd';
    len = strlen(input);
    for(i = len - 1;i >= 0;i--)
    {
        switch(input[i])
        {
            case 'i':
            state = 'i';
            break;
            case '+':
            if(state1 == 'd')
            {
                if(state == 'i')
                {
                    T->im.signal = 1;
                    T->im.v[cnt++] = 1;
                }
                else if(state == 'r')
                {
                    T->re.signal = 1;
                }
            }
            else if(state1 == 'g')
            {
                if(state == 'i')
                {
                    T->im.signal = 1;
                }
                else if(state == 'r')
                {
                    T->re.signal = 1;
                }
            }  
            state = 'r';
            break;
            case '-':
            if(state1 == 'd')
            {
                if(state == 'i')
                {
                    T->im.signal = -1;
                    T->im.v[cnt++] = 1;
                }
                else if(state == 'r')
                {
                    T->re.signal = -1;
                }
            }
            else if(state1 == 'g')
            {
                if(state == 'i')
                {
                    T->im.signal = -1;
                }
                else if(state == 'r')
                {
                    T->re.signal = -1;
                }
            }
            state = 'r';
            break;
            default:
            if(state == 'i')
            {
                state1 = 'g';
                T->im.v[cnt++] = input[i] - '0';
            }
            else if(state == 'r')
                T->re.v[cnt1++] = input[i] - '0'; 
        }
    }
    if(state == 'i' && state1 == 'd')
        T->im.v[cnt++] = 1;
    T->im.cnt = cnt;
    T->re.cnt = cnt1;
    if(T->im.cnt == 0)
        T->im.signal = 0;
    if(T->re.cnt == 0)
        T->re.signal = 0;
}

Complex pow_Complex(Complex T,int n)
{
    int i;
    Complex S = T;
    for(i = 0;i < n - 1;i++)
    {
        S = Muti_Complex(S,T);
    }
    return S;
}

Complex Muti_Complex(Complex a,Complex b)
{
    Complex outcome;
    BIGINT temp = mul_bigint(a.im,b.im);
    temp.signal = - temp.signal;
    outcome.im = add_bigint(mul_bigint(a.im,b.re),mul_bigint(a.re,b.im));
    outcome.re = add_bigint(temp,mul_bigint(a.re,b.re));
    return outcome;
}

BIGINT mul_bigint(BIGINT S,BIGINT T)
{
    BIGINT R = {{0},S.cnt + T.cnt,0};
    for(int i = 0;i < T.cnt;i++)
    {
        int t,k,j;
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
    //最高位0不统计在一个大整数的位数中
    R.signal = S.signal * T.signal;
    return R;
}

int cmp(BIGINT S,BIGINT T)
{
    if(S.cnt > T.cnt)
        return 1;
    else if(S.cnt < T.cnt)
        return -1;
    else
    {
        int i;
        for(i = S.cnt - 1;i >=0;i--)
        {
            if(S.v[i] > T.v[i])
                return 1;
            else if(S.v[i] < T.v[i])
                return -1;
            else
                continue;
        }
        return 0;
    }
}

BIGINT sub(BIGINT S,BIGINT T)
{
    BIGINT R = {{0},1,1};
    int i;
    for(i = 0;i < S.cnt;i++)
    {
        R.v[i] = S.v[i] - T.v[i] + R.v[i];
        if(R.v[i] < 0)
        {
            R.v[i] += 10;
            R.v[i + 1]--;
        }
    }
    R.cnt = S.cnt;
    for(i = S.cnt - 1;i >= 0;i--)
    {
        if(R.v[i] == 0)
            R.cnt--;
        else
            break;
    }
    return R;
}

BIGINT add(BIGINT S,BIGINT T)
{
    BIGINT R = {{0},1,1};
    int i,carry = 0;
    R.cnt = (S.cnt > T.cnt)?S.cnt:T.cnt;
    for(i = 0;i < R.cnt;i++)
    {
        R.v[i] = S.v[i] + T.v[i] + R.v[i] + carry;
        carry = R.v[i] / 10;
        R.v[i] %= 10;
    }
    if(carry > 0)
    {
        R.cnt++;
        R.v[i] += carry;
    }
    return R;
}

BIGINT add_bigint(BIGINT S,BIGINT T)
{
    BIGINT R = {{0},1,1};
    if(S.signal * T.signal < 0)
    {
        if(cmp(S,T) > 0)
        {
            R = sub(S,T);
            R.signal = S.signal;
            return R;
        }
        else if(cmp(S,T) < 0)
        {
            R = sub(T,S);
            R.signal = T.signal;
            return R;
        }
        else
        {
            R.signal = 0;
            return R;
        }
    }
    else
    {
        R = add(S,T);
        R.signal = (S.signal == 0)?T.signal:S.signal;
    }
    return R;
}