#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int p[26];

int cmp(const void *a, const void *b);

int main()
{
    char s[100];
    int i, j, count;  
    while(scanf("%s\n",s) != EOF)
    {
        for( i = 0 ; i < 26 ; i++)
            p[s[i] - 'A'] = i;
        char str[2500];
        gets(str);
        char a[100][50];
        count = 0 ;
        i = 0;

        while(1)
        {
            j = 0;
            while(str[i] != ' ' && str[i])
                a[count][j++] = str[i++];
            a[count][j] = '\0';
            count ++;
            if( !str[i] )
                break;
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
        ch2 = (*s2) >= 'a' ? *s2 - 32 : *s2;
        if( p[ch1 - 'A'] != p[ch2 - 'A'])
            return p[ch1 - 'A'] - p[ch2 - 'A'];
        else
        {
            s1++;
            s2++;
        }
    }
     if( *s1 == 0 )
            return -1;
    else
            return 1;
}