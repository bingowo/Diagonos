#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void readpoly(char* s, int* co)
{
    while(*s)
    {
        int sign = 1;
        int c = 0;
        int d = 0;
        //判断符号
        if(*s == '+')s++;
        else if(*s == '-')
        {
            sign = -1;
            s++;
        }
        //获取数字
        while(isdigit(*s))
        {
            c = c*10 + *s-'0';
            s++;
        }
        if(c == 0) c = 1;
        //常数项
        if(*s != 'x')
        {
            co[0] = c*sign;
            return;
        }
        else s++;
        //非常数项
        if(*s == '^') s++;
        while(isdigit(*s))
        {
            d = d*10 + *s - '0';
            s++;
        }
        if(d == 0) d = 1;
        co[d] = c*sign;
    }
}

int main()
{
    char s1[50] = {0};
    char s2[50] = {0};

    while(scanf("%s %s", s1, s2) != EOF)
    {
        int co1[50] = {0};
        int co2[50] = {0};
        readpoly(s1, co1);
        readpoly(s2, co2);

        int result[100] = {0};
        for(int i = 0; i<50; i++)
            for(int j = 0; j<50; j++)
                result[i+j] += co1[i]*co2[j];
        int flag = 0;
        for(int i = 99; i>=0; i--)
        {
            if(result[i])
            {
                flag?printf(" %d", result[i]):printf("%d", result[i]);
                flag = 1;
            }
        }
        printf("\n");
    }
    return 0;
}
