#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char getBasechar(int a);
void tento2(int a, int* dest);
int twoto10(int* temp);
int main()
{
    int i, x, T, temp1[1000], len;
    char s[101], res[1000];
    scanf("%d", &T);
    for (x = 0;x < T;x++)
    {
        scanf("%s", s);
        for (i = 0;i < strlen(s);i++)
        {
            tento2((int)s[i], temp1 + i * 8);        //每进行一次，temp里就会多8位
        }
        len = 8 * strlen(s);                        //temp元素个数
        if (strlen(s) % 3 != 0)
        {
            for (i = 0;i < (6 - (8 * strlen(s) % 6));i++)      //加6-（8*strlen(s)%6)位
            {
                temp1[8 * strlen(s) + i] = 0;
            }
            len += 6 - (len % 6);
        }
        //(len/6)即为temp里可转换的元素个数
        for (i = 0;i < len / 6;i++)
        {
            res[i] = getBasechar(twoto10(temp1 + i * 6));
        }
        res[len / 6] = 0;
        if ((len / 6) < 4)
        {
            for (i = 0;i < 4 - (len / 6);i++)
                res[len / 6 + i] = '=';
            res[4] = 0;
        }
        printf("case #%d:\n", x);
        puts(res);
    }

    return 0;
}
char getBasechar(int a)
{
    char c;
    if (a >= 0 && a <= 25)
        c = 'A' + a;
    else if (a >= 26 && a <= 51)
        c = 'a' + (a - 26);
    else if (a >= 52 && a <= 61)
        c = '0' + (a - 52);
    else if (a == 62)
        c = '+';
    else
        c = '/';
    return c;
}
void tento2(int a, int* dest)
{
    int pos = 7;
    while (pos > -1)
    {
        dest[pos] = a % 2;
        a = a / 2;
        pos--;
    }
}
int twoto10(int* temp)
{
    int i, res;
    res = 0;
    for (i = 0;i < 6;i++)
        res = res * 2 + temp[i];
    return res;
}

