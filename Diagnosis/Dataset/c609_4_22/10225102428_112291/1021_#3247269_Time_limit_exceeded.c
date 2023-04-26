#include <stdio.h>
#include <stdlib.h>
int p[26];

int cmp(const void *a, const void *b)
{
    char *s1 = (char *)a;
    char *s2 = (char *)b;
    char ch1, ch2;
    while (*s1 && *s2)
    {
        ch1 = (*s1) >= 'a' ? *s1 - 32 : *s1;//转换成小写
        ch2 = (*s2) >= 'a' ? *s2 - 32 : *s2;
        if (p[ch1 - 'A'] != p[ch2 - 'A'])
            return p[ch1 - 'A'] - p[ch2 - 'A'];
        else
        {
            s1++;
            s2++;
        }
    }
}

int main()
{

    char s[27];
    int i, count, j;
    while (scanf("%s\n", s) != EOF)
    {
        for (i = 0; i < 26; i++)
            p[s[i] - 'A'] = i;
        char str[2100];
        char a[100][50];
        int k=0;
        while(scanf("%s",str)!='\n'){
            k++;
        }
        count = 0;
        i = 0;
        while (1)
        {
            j = 0;
            while (str[i] != ' ' && j<k)a[count][j++] = str[i++];
            a[count][j] = '\0';
            count++;
            if(!str[i])break;
            else i++;
        }
        qsort(a, count, sizeof(a[0]), cmp);
        for (i = 0; i < count - 1; i++)printf("%s ",a[i]);
        printf("%s",a[i]);
 }
     return 0;
}
