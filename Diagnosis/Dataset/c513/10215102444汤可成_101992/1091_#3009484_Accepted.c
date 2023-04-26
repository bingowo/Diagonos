#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5000

//定义大整数类型的结构体
typedef struct
{
    int cnt, v[N], sign;
}BIGINT;

//负数类型的结构体
typedef struct
{
    BIGINT re, im;
}COMPLEX;

//输入
void init(COMPLEX *data, char *s)
{
    int len = strlen(s);
    int j = len-1;
    if(s[j] == 'i')  //有虚部
    {
        if(j == 0)  //只有i
        {
            data->im.v[0] = 1;
            data->im.cnt = 1;
            data->im.sign = 1;
            return;
        }
        j--;
        if(s[j] == '-' || s[j] == '+')
        {
            data->im.v[0] = 1;
            data->im.cnt = 1;
            if(s[j] == '-') data->im.sign = -1;
            else data->im.sign = 1;
            j--;
        }
        else
        {
            while(j>=0&&s[j]>='0' && s[j]<='9')
            {
                data->im.v[data->im.cnt++] = s[j--] - '0';
            }
        }
    }
    if(s[j] == '-' || s[j] == '+')
        {
            if(s[j] == '-') data->im.sign = -1;
            else data->im.sign = 1;
            j--;
        }
    while(j>=0 && s[j]>='0'&&s[j]<='9')
    {
        data->re.v[data->re.cnt++] = s[j--] - '0';
    }
    if(j>=0)
    {
        if(s[j] == '-')
            data->re.sign = -1;
    }
}

//输出
void print(COMPLEX* ret)
{
    if(ret->re.cnt != 0)  //有实部
    {
        if(ret->re.sign == -1) printf("-");
        for(int i = ret->re.cnt-1; i>=0; i--)
        {
            printf("%d", ret->re.v[i]);
        }
        if(ret->im.cnt!=0 && ret->im.sign != -1) printf("+");
    }
    if(ret->im.cnt != 0)
    {
        if(ret->im.sign == -1) printf("-");
        if(ret->im.cnt == 1 && ret->im.v[0] == 1) printf("i\n");
        else
        {
            for(int i = ret->im.cnt-1; i>=0; i--)
            {
                printf("%d", ret->im.v[i]);
            }
            printf("i\n");
        }
    }
}

//大整数比较
int cmp(BIGINT a, BIGINT b)
{
    int n = (a.cnt>b.cnt)?a.cnt:b.cnt;
    for(int i = n-1; i>=0; i--)
    {
        if(a.v[i] > b.v[i]) return 1;
        else if(a.v[i] < b.v[i]) return -1;
    }
    return 0;
}

//减法
void SUB(BIGINT* a, BIGINT* b, BIGINT* c)
{
    int n = (a->cnt > b->cnt)?a->cnt:b->cnt;
    c->cnt = n;
    int carry = 0, i = 0;
    for(i = 0; i<n; i++)
    {
        if((a->v[i]+carry)<b->v[i])
        {
            c->v[i] = 10+a->v[i]+carry-b->v[i];
            carry = -1;
        }
        else
        {
            c->v[i] = a->v[i] + carry - b->v[i];
            carry = 0;
        }
    }
    for(int i = n-1; i>=0 && c->v[i] == 0; i--) c->cnt--;
}

//大整数减法
BIGINT BIGSUB(BIGINT a, BIGINT b)
{
    BIGINT R = {0,{0},1};
    if(cmp(a,b)>=0)
    {
        R.sign = 1;
        SUB(&a, &b, &R);
    }
    else
    {
        R.sign = -1;
        SUB(&b, &a, &R);
    }
    return R;
}

//大整数加法
BIGINT BIGADD(BIGINT a, BIGINT b)
{
    if(a.cnt == 0) return b;
    if(b.cnt == 0) return a;
    BIGINT R = {0,{0},1};
    if(a.sign*b.sign<0)
    {
        if(a.sign == -1) R = BIGSUB(b,a);
        else R = BIGSUB(a,b);
    }
    else
    {
        R.sign = a.sign;
        int i = 0, carry = 0;
        for(i = 0; i<a.cnt && i<b.cnt; i++)
        {
            int tmp = (a.v[i]+b.v[i]+carry);
            R.v[i] =tmp%10;
            carry = tmp/10;
        }
        while(i<a.cnt)
        {
            int tmp = a.v[i]+carry;
            R.v[i++] = tmp%10;
            carry = tmp/10;
        }
        while(i<b.cnt)
        {
            int tmp = b.v[i]+carry;
            R.v[i++] = tmp%10;
            carry = tmp/10;
        }
        if(carry)
        {
            R.v[i++] = carry%10;
        }
        R.cnt = i;
    }
    return R;
}

//大整数乘法
BIGINT BIGMUL(BIGINT a, BIGINT b)
{
    BIGINT R = {0,{0},1};
    if(a.cnt == 0 || b.cnt == 0) return R;
    R.cnt = a.cnt+b.cnt;
    R.sign = a.sign*b.sign;
    for(int i = 0; i<b.cnt; i++)
    {
        int t = 0, k = 0, j = 0;
        int carry = 0;
        for(j = 0; j<a.cnt; j++)
        {
            t = a.v[j]*b.v[i]+carry+R.v[i+j];
            R.v[i+j] = t%10;
            carry = t/10;
        }
        k = i+j;
        while(carry>0)
        {
            t = carry+R.v[k];
            R.v[k++] = t%10;
            carry = t/10;
        }
    }
    if(R.v[a.cnt+b.cnt-1]==0) R.cnt--;
    return R;
}

//复数乘法
COMPLEX mul(COMPLEX a, COMPLEX b)
{
    COMPLEX ret = {{0,{0},1},{0,{0},1}};

    BIGINT re1 = BIGMUL(a.re, b.re);
    BIGINT re2 = BIGMUL(a.im, b.im);
    re2.sign = -re2.sign;

    BIGINT im1 = BIGMUL(a.re,b.im);
    BIGINT im2 = BIGMUL(a.im,b.re);
    ret.re = BIGADD(re1, re2);
    ret.im = BIGADD(im1, im2);
    return ret;
}

//负数幂运算
void pow_comp(COMPLEX* data, int n)
{
    COMPLEX p = {{1,{1},1},{0,{0},1}};
    for(int i = 1; i<=n; i++)
    {
        p = mul(p, *data);
    }
    *data = p;
}

int main()
{
     char s[20];
     int n;
     scanf("%s %d", s, &n);
     COMPLEX data = {{0,{0},1},{0,{0},1}};
     //输入
     init(&data,s);
     //输出
     if(n == 0) printf("1\n");
     else if(n == 1)print(&data);
     else
     {
         pow_comp(&data,n);
         print(&data);
     }
     return 0;
}
