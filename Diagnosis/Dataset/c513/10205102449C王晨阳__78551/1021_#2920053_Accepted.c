#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int p[26];

int cmp(const void *a, const void *b)
{
    char *s1, *s2; char ch1, ch2;
    s1 = (char *)a; s2 = (char *)b;
    while(*s1 && *s2)
    {
        ch1 = (*s1)>='a'? *s1-32:*s1;
        ch2 = (*s2)>='a'? *s2-32:*s2;
        if(p[ch1-'A']!=p[ch2-'A']) return p[ch1-'A']-p[ch2-'A'];
        else {s1++;s2++;}
    }
    if(*s1==0) return -1;
    else return 1;
}

void mygets(char *s)
{
    int i=0;
    char a;
    while((a= getchar())!=EOF && i<2001)
    {
        s[i++]=a;
        if(a=='\n')
            break;
    }
    s[--i]='\0';
}

int main()
{
    char s[27];
    while(scanf("%s\n",s)!=EOF)
    {
        for(int i=0;i<26;i++)
            p[s[i]-'A'] = i;
        char a[100][21]; int count;char str[2001];
        mygets(str);
        count = 0; int i= 0;
        while(1)
        {
            int j = 0;
            while(str[i] != ' ' && str[i]) a[count][j++] = str[i++];
            a[count][j] = '\0';
            count++;
            if(!str[i]) break;
            else i++;
        }
        qsort(a, count, sizeof(a[0]), cmp);
        for(i=0;i<count-1;i++) printf("%s ",a[i]);
        printf("%s\n",a[i]);
    }
    return 0;
}