#include <stdio.h>
#include <stdlib.h>
int p[26];//给定顺序？为什么是int?

int cmp(const void *a, const void *b)
{
    char *s1 = (char *)a;
    char *s2 = (char *)b;
    char ch1, ch2;
    while (*s1 && *s2)
    {
        ch1 = (*s1) >= 'a' ? *s1 - 32 : *s1;//转换成大写
        ch2 = (*s2) >= 'a' ? *s2 - 32 : *s2;
        if (p[ch1 - 'A'] != p[ch2 - 'A'])
            return p[ch1 - 'A'] - p[ch2 - 'A'];
        else
        {
            s1++;//相等的话看下一个字符串
            s2++;
        }
    }
}

int main()
{

    char s[27];
    int i,count=0;
    while (scanf("%s\n", s) != EOF)
    {
        for (i = 0; i < 26; i++)
            p[s[i] - 'A'] = i;//转换成整形数的顺序
        char a[100][51];
        char ch;
        i = 0;
        while (1)
        {
            scanf("%s",a[i]);
            i++;
            count++;
            ch=getchar();
            if(ch=='\n')break;
        }
        qsort(a, count, sizeof(a[0]), cmp);
        for (i = 0; i < count - 1; i++)printf("%s ",a[i]);
        printf("%s",a[i]);
 }
     return 0;
}


