#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int p[26];
int cmp (const void*a, const void *b)
{
    char *s1, *s2;
    char ch1, ch2;
    s1 = *(char(*)[21])a;
    s2 = *(char(*)[21])b;
    while (*s1 && *s2)
    {
        ch1 = (*s1) >= 'a' ? *s1-32 : *s1;
        ch2 = (*s2) >= 'a' ? *s2-32 : *s2;
        if (p[ch1-'A'] != p[ch2-'A']) return p[ch1-'A'] - p[ch2-'A'];
        else
        {
            s1++; s2++;
        }
    }
    if (*s1 == 0) return -1;
    else return 1;
}
int main()
{
    char alpha[27];
    while ((scanf("%s",alpha)) != EOF)
    {
        //对字符排序进行赋值
        for (int i = 0; i < 26; i++)
        {
            p[alpha[i] - 'A'] = i;
        }
        getchar();//把换行符吃掉

        //将单词存放
        char a[101][21];//存放单词
        char c;
        int cont = 0, k = 0;
        do
        {
            c = getchar();
            if (c != ' ' && c != '\n')//如果c是字符
            {
                a[cont][k] = c;
                k++;
            }
            else if (c == ' ')//如果c是空格，说明该单词输入结束
            {
                a[cont][k] = '\0';
                cont++;
                k = 0;
            }
        } while (c != '\n');//如果是换行符，该行单词输入结束
        qsort(a,cont,sizeof(a[0]),cmp);
        for (int i = 0; i < cont; i++)
        {
            printf("%s%c",a[cont],i != cont ? ' ' : '\n');
        }
    }


}