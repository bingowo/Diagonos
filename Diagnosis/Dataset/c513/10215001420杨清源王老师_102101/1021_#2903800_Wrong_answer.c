#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int p[26];//创建一个新的字母顺序表

int cmp(const void *a, const void *b);

int main()
{
    char s[100];
    int i, j, count;  //用count记录字符串的个数
    while(scanf("%s\n",s) != EOF)
    {
        for( i = 0 ; i < 26 ; i++)
            p[s[i] - 'A'] = i;
        char str[2500];//读取第二行的字符串
        gets(str);
        char a[100][50];//用二维数组储存每一组的每一个经排序后的字符串用作输出
        count = 0 ;
        i = 0;

        while(1)
        {
            j = 0;
            while(str[i] != ' ' && str[i])
                a[count][j++] = str[i++];
            a[count][j] = '\0';
            count ++;//此时在第一个字符串已经被录入在a[count]下
            if( !str[i] )
                break;//如果此时没有字符串则跳出循环
            else i++;
        }

        qsort(a,count,sizeof(a[0]),cmp);

        for( i = 0 ; i < count - 1 ; i++)
            printf("%s ", a[i]);
        printf("%s\n", a[i]);
    }
}

int cmp(const void *a, const void *b)
{
    char *s1, *s2;
    s1 = (char *)a;
    s2 = (char *)b;
    char ch1 , ch2;
    while( *s1 && *s2)
    {
        ch1 = (*s1) >= 'a' ? *s1 - 32 : *s1;
        ch2 = (*s2) >= 'a' ? *s2 - 32 : *s2;//转换为大写字母
        if( p[ch1 - 'A'] != p[ch2 - 'A'])
            return p[ch1 - 'A'] - p[ch2 - 'A'];
        else
        {
            s1++;
            s2++;
        }
        if( *s1 == 0 )
            return -1;
        else
            return 1;
    }
}
