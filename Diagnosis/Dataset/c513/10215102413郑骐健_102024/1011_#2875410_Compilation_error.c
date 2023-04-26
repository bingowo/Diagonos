#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

typedef struct comple
{
    long long int r, i;
}Complex;
//每次的乘法
void reverse(Complex* c, long long int o)
{
    long long int g;
    g =(c->i) * (-1) + (c->r) ;
    c->r = (c->r) * (-1) - (c->i)+ o;       //注意：对同一个结构下的两个数做相关运算取好第三者，避免因先后关系发生错误
    c->i = g;
}
// 将16进制转化为二进制
//使用结构体记录复数的各位整数
//每读取一位对上一位进行乘法操作直到最后一位，
//输出
int main()
{
    Complex res;
    Complex* pres;
    pres = &res;
    res.i = 0;
    res.r = 0;
    char* p = (char*)malloc(sizeof(char) * 1e8);
    scanf("%s", p);
    char* p_ = p;
    p_ += 2;
    while (*p_ != '\0')
    {
        long long int mid, flag = 1;
        if ((*p_ < '9' +1)&&(*p >'0'-1))
        {
            mid = *p_ - '0';
        }
        else mid = *p_ - 'A' + 10;
        for (int i = 3;i > -1;i--)
        {
            if (mid & (flag << i))
            {
                reverse(pres, 1);
            }
            else reverse(pres, 0);
        }
        p_++;
    }
    if (res.i == 0)
    {   
        printf("%lld", res.r);
    }
    else if (res.r == 0)
    {
        if (i == 1)printf("i");
        else if (i == -1)printf("-i");
        else printf("%lldi", res.i);
    }
    else if (res.i == -1)
    {
        printf("%lld-i", res.r);
    }
    else if(res.i ==1)printf("%lld+i", res.r);
    else if (res.i > 0)printf("%lld+%lldi", res.r, res.i);
    else printf("%lld%lldi", res.r, res.i);
    free(p);
    return 0;
}
