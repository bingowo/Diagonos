#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define L 1000

typedef struct 
{
    int v[L],cnt,signal;
}BIGINT;

BIGINT sub(BIGINT S,BIGINT T);

BIGINT sub1(BIGINT S,BIGINT T);

BIGINT add(BIGINT S,BIGINT T);

BIGINT add1(BIGINT S,int a);

int cmp(BIGINT S,BIGINT T);

void output(BIGINT S,BIGINT T);

int main()
{
    char input[10];
    char*table[256];
    table['0'] = "0000",table['1'] = "0001",table['2'] = "0010";
    table['3'] = "0011",table['4'] = "0100",table['5'] = "0101";
    table['6'] = "0110",table['7'] = "0111",table['8'] = "1000";
    table['9'] = "1001",table['A'] = "1010",table['B'] = "1011";
    table['C'] = "1100",table['D'] = "1101",table['E'] = "1110";
    table['F'] = "1111";
    char bi[L] = {0},*pt;
    scanf("%s",input);
    pt = strchr(input,'x');
    pt++;
    while(*pt)
    {
        strcat(bi,table[*pt]);
        pt++;
    }
    int i,len = strlen(bi);
    BIGINT re = {{0},1,0},im = {{0},1,0};
    BIGINT temp_re = {{0},1,0},temp_im = {{0},1,0};
    for(i = 0;i < len;i++)
    {
        //temp_im = re - im;
        temp_im = sub(re,im);
        //temp_re = -re - im + bi[i] - '0';
        temp_re = add(re,im);
        temp_re.signal = -temp_re.signal;
        temp_re = add1(temp_re,bi[i] - '0');
        //re = temp_re;
        memcpy(re.v,temp_re.v,sizeof(int) * temp_re.cnt);
        re.cnt = temp_re.cnt;
        //im = temp_im;
        memcpy(im.v,temp_im.v,sizeof(int) * temp_im.cnt);
        im.cnt = temp_im.cnt;
    }
    output(re,im);
    return 0;
}

int cmp(BIGINT S,BIGINT T)
{
    int i,len_max;
    if(S.cnt > T.cnt)
        return 1;
    else if(S.cnt < T.cnt)
        return -1;
    else
    {
        for(i = S.cnt - 1;i >= 0;i--)
        {
            if(S.v[i] > T.v[i])
                return 1;
            else if(S.v[i] < T.v[i])
                return -1;
            else
                continue;
        }
    }
    return 0;
}

BIGINT sub(BIGINT S,BIGINT T)
{
    BIGINT R = {{0},1,0};
    if(S.signal == -1 && T.signal == 1)
    {
        R = add(S,T);
        R.signal = -1;
    }
    else if(S.signal == -1 && T.signal == -1)
    {
        if(cmp(S,T) < 0)
        {
            R = sub1(T,S);
            R.signal = 1;
        }
        else if(cmp(S,T) > 0)
        {
            R = sub1(S,T);
            R.signal = -1;
        }
        else
            ;
    }
    else if(S.signal == 1 && T.signal == -1)
    {
        R = add(S,T);
        R.signal = S.signal;
    }
    else if(S.signal == 1&& T.signal == 1)
    {
        if(cmp(S,T) > 0)
        {
            R = sub1(S,T);
            R.signal = 1;
        }
        else if(cmp(S,T) < 0)
        {
            R = sub1(T,S);
            R.signal = -1;
        }
        else
            ;  
        return R;
    }
    else if(S.signal == 0 && T.signal == 0)
    {
        ;
    }
    else if(S.signal == 0)
    {
        R = T;
        R.signal = -T.signal;
    }
    else if(T.signal == 0)
    {
        R = S;
        R.signal = S.signal;
    }
    return R;
}

BIGINT sub1(BIGINT S,BIGINT T)
{
    int i;
    BIGINT R = {{0},S.cnt,0};
    for(i = 0;i < S.cnt;i++)
    {
        R.v[i] = S.v[i] - T.v[i] + R.v[i];
        if(R.v[i] < 0)
        {
            R.v[i] += 10;
            R.v[i + 1]--;
        }
    }
    for(i = R.cnt - 1;i >= 0;i--)
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
    int i,carry = 0,len_max;
    BIGINT R = {{0},1,0};
    len_max = (S.cnt > T.cnt)?S.cnt:T.cnt;
    if(S.signal * T.signal > 0)
    {
        for(i = 0;i < len_max;i++)
        {
            R.v[i] = S.v[i] + T.v[i] + carry;
            carry = R.v[i] / 10;
            R.v[i] %= 10;
        }
        if(carry)
        {
            R.v[i] += carry;
            R.cnt = len_max + 1;
        }
        else
        {
            R.cnt = len_max;
        }
        R.signal = S.signal;
    }
    else if(S.signal > 0 && T.signal <0)
    {
        if(cmp(S,T) > 0)
        {
            R = sub1(S,T);
            R.signal = 1;
        }
        else if(cmp(S,T) < 0)
        {
            R = sub1(T,S);
            R.signal = -1;
        }
        else
            ;
    }
    else if(S.signal < 0 && T.signal > 0)
    {
        if(cmp(S,T) > 0)
        {
            R = sub1(S,T);
            R.signal = -1;
        }
        else if(cmp(S,T) < 0)
        {
            R = sub1(T,S);
            R.signal = 1;
        }
        else
            ;
    }
    else if(S.signal * T.signal == 0)
    {
        if(S.signal == 0)
        {
            R = T;
        }
        else
        {
            R = S;
        }
    }
    return R;
}

BIGINT add1(BIGINT S,int a)
{
    if(S.signal >= 0)
    {
        int i,carry = 0;
        S.v[0] += a;
        if(S.v[0] < 10)
            return S;
        for(i = 0;i < S.cnt;i++)
        {
            S.v[i] = S.v[i] + carry;
            if(S.v[i] < 10)
                return S;
            carry = S.v[i] / 10;
            S.v[i] %= 10; 
        }
        if(carry)
        {
            S.v[i] += carry;
            S.cnt++;
        }
    }
    else
    {
        int i;
        S.v[0] -= 1;
        for(i = 0;i < S.cnt;i++)
        {
            if(S.v[i] < 0)
            {
                S.v[i] += 10;
                S.v[i + 1]--;
            }
        }
        if(S.v[S.cnt - 1] == 0)
            S.cnt--;
    }
    return S;
}

void output(BIGINT S,BIGINT T)
{
    int i;
    if(S.signal > 0 && T.signal < 0)
    {
        for(i = S.cnt - 1;i >= 0;i--)
            printf("%d",S.v[i]);
        putchar('-');
        if(T.cnt == 1 && T.v[0] == 1)
            putchar('i');
        else
        {
            for(i = T.cnt - 1;i >= 0;i--)
                printf("%d",T.v[i]);
        }
        putchar('i');
        putchar('\n');
    }
    else if(S.signal < 0 && T.signal > 0)
    {
        putchar('-');
        for(i = S.cnt - 1;i >= 0;i--)
            printf("%d",S.v[i]);
        putchar('+');
        if(T.cnt == 1 && T.v[0] == 1)
            putchar('i');
        else
        {
            for(i = T.cnt - 1;i >= 0;i--)
                printf("%d",T.v[i]);
        } 
        putchar('i');
        putchar('\n');
    }
    else if(S.signal > 0 && T.signal > 0)
    {
        for(i = S.cnt - 1;i >= 0;i--)
            printf("%d",S.v[i]);
        putchar('+');
        if(T.cnt == 1 && T.v[0] == 1)
            putchar('i');
        else
        {
            for(i = T.cnt - 1;i >= 0;i--)
                printf("%d",T.v[i]);
        } 
        putchar('i');
        putchar('\n');
    }
    else if(S.signal < 0 && T.signal < 0)
    {
        putchar('-');
        for(i = S.cnt - 1;i >= 0;i--)
            printf("%d",S.v[i]);
        putchar('-');
        if(T.cnt == 1 && T.v[0] == 1)
            putchar('i');
        else
        {
            for(i = T.cnt - 1;i >= 0;i--)
                printf("%d",T.v[i]);
        }
        putchar('i');
        putchar('\n');
    }
    else if(S.signal * T.signal == 0)
    {
        if(S.signal == 0)
        {
            if(T.signal > 0)
            {
                if(T.cnt == 1 && T.v[i] == 1)
                    putchar('i');
                else
                {
                    for(i = T.cnt - 1;i >= 0;i--)
                        printf("%d",T.v[i]);
                    putchar('i');
                }
            }
            else if(T.signal == 0)
                putchar('0');
            else
            {
                putchar('-');
                if(T.cnt == 1 && T.v[i] == 1)
                    putchar('i');
                else
                {
                    for(i = T.cnt - 1;i >= 0;i--)
                        printf("%d",T.v[i]);
                    putchar('i');
                }
            }
        }
        else
        {
            if(S.signal > 0)
            {
                for(i = S.cnt - 1;i >= 0;i--)
                    printf("%d",S.v[i]);
            }
            else if(S.signal == 0)
                putchar('0');
            else
            {
                putchar('-');
                for(i = S.cnt - 1;i >= 0;i--)
                    printf("%d",S.v[i]);
            }
        }
    }
    putchar('\n');
}