#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print(char* z1, char* x1, int N)
{
    int cnt = 0;
    while((*z1 == '0' || *z1 == 0) && cnt<=501)
    {
        z1++;
        cnt++;
    }
    if(cnt == 502) printf("0.");
    else
    {
        while(cnt<=500)
        {
            printf("%c", *z1);
            cnt++;
        }
        printf(".");
    }
    for(cnt = 0; cnt<N; cnt++)
    {
        printf("%c", x1[cnt]);
    }
}

void sub(char* s1, char* s2, int N, int t)
{
    int flag = 1;
    if(s1[0] == '-')
    {
        s1++;
        s2++;
        flag = -1;
    }
    else if(s2[0] == '-')
    {
        s2++;
        flag = 0;
    }
    char* p = s1;
    char* q = s2;
    int cnt = 0;
    while(*p != '.' && cnt <500)
    {
        p++;
        cnt++;
    }
    if(cnt == 500)
    {
        if(flag == -1) p = s1+499;
        else p = s1+500;
    }
    cnt = 0;
    while(*q != '.' && cnt<500)
    {
        q++;
        cnt++;
    }
    if(cnt == 500)
    {
        if(flag == 1) q = s2+500;
        else q = s2+499;
    }
    char z1[501] = {0}, z2[501] = {0};
    char x1[51] = {0}, x2[51] = {0};
    char* i = s1;
    int j = 500;

    while(i != p)
    {
        z1[j] = *i;
        j--;
        i++;
    }
    i++;
    j = 0;
    while(*i != 0)
    {
        x1[j] = *i;
        i++;
        j++;
    }
    j = 500;
    i = s2;
    while(i != q)
    {
        z2[j] = *i;
        j--;
        i++;
    }
    j = 0;
    i++;
    while(*i != 0)
    {
        x2[j] = *i;
        i++;
        j++;
    }

    if(flag == 1)
    {
        //小数
        char z = 0;
        for(j = 50; j>=0; j--)
        {
            if(x1[j] <= 0) x1[j] += '0';
            if(x2[j] <= 0) x2[j] += '0';
            if(x1[j]>=x2[j]) x1[j] = x1[j] - x2[j] + '0';
            else
            {
                if(j>0) x1[j-1]--;
                else z = -1;
                x1[j] = x1[j] + 10 - x2[j] + '0';
            }
        }

        //整数
        if(z == -1) z1[500]--;
        for(j = 500; j>=0; j--)
        {
            if(z1[j] <= 0) z1[j] += '0';
            if(z2[j] <= 0) z2[j] += '0';
            if(z1[j] >= z2[j]) z1[j] = z1[j] - z2[j] + '0';
            else
            {
                z1[j-1]--;
                z1[j] = z1[j] + 10 - z2[j] + '0';
            }
        }
        //四舍五入
        int carry = 0;
        if(x1[N] >='5')
        {
            carry = 1;
        }
        if(carry)
        {
            for(j = N-1; j>=0; j--)
        {
            x1[j] += carry;
            if(x1[j]>'9')
            {
                x1[j] = '0';
                carry = 1;
            }
            else
            {
                carry = 0;
                break;
            }
        }
        if(carry == 1)
        {
            for(j = 500; j>=0; j--)
            {
                z1[j] += carry;
                if(z1[j] > '9')
                {
                    z1[j] = '0';
                    carry = 1;
                }
                else
                {
                    carry = 0;
                    break;
                }
            }
        }
        }

        //输出
        print(z1, x1, N);
    }

    else
    {
        int carry = 0;
        //小数
        for(j = 50; j>=0; j--)
        {
            if(x1[j]<=0)x1[j] += '0';
            if(x2[j]<=0)x2[j] += '0';
            x1[j] += x2[j]-'0';
            if(x1[j]>'9')
            {
                x1[j] = x1[j] - '9'+'0';
                if(j > 0)x1[j-1]++;
                else carry = 1;
            }
        }
        //整数
        for(j = 500; j>=0; j--)
        {
            if(z1[j]<=0)z1[j] += '0';
            if(z2[j]<=0)z2[j] += '0';
            if(j == 500) z1[j] += carry;
            z1[j] += z2[j]-'0';
            if(z1[j]>'9')
            {
                z1[j] = z1[j] - '9' + '0';
                z1[j-1]++;
            }
        }
        //四舍五入
        carry = 0;
        if(x1[N] >='5')
        {
            carry = 1;
        }
        if(carry)
        {
            for(j = N-1; j>=0; j--)
        {
            x1[j] += carry;
            if(x1[j]>'9')
            {
                x1[j] = '0';
                carry = 1;
            }
            else
            {
                carry = 0;
                break;
            }
        }
        if(carry == 1)
        {
            for(j = 500; j>=0; j--)
            {
                z1[j] += carry;
                if(z1[j] > '9')
                {
                    z1[j] = '0';
                    carry = 1;
                }
                else
                {
                    carry = 0;
                    break;
                }
            }
        }
        }
        //输出
        if(flag == -1 && t == 1) printf("-");
        print(z1, x1, N);
    }
}

int main()
{
    char s1[501] = {0}, s2[501] = {0};
    int N = 0;
    scanf("%s %s %d", s1, s2, &N);
    if(strcmp(s1, s2) > 0)
    {
        sub(s1, s2, N, 1);
    }
    else if(strcmp(s1, s2) == 0) printf("0\n");
    else
    {
        printf("-");
        sub(s2, s1, N, -1);
    }
    return 0;
}
