#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char sord[28];
    char *str[100];
}str_sort;
int find(char *s,char c);
int cmp(const void *e1, const void *e2);
int main()
{
    char c1;
    while(c1=getchar()!='\n'&&c!=EOF)
    {
        ungetc(c1,stdin);
        //char sord[28];
        str_sort s;
        fgets(s.sord,28,stdin);
        int i=0;
        char c2;
        while(getchar()!='\n')
        {
            ungetch(c2,stdin);
            scanf("%s",s.str[i]);
            i++;
        }
        qsort(s.str,i,sizeof(s.str[0]),cmp);
    }
    return 0;
}
int find(char *s,char c)
{
    for(int i=0;s[i];i++)
    {
        if(s[i]==c||s[i]==c-'a'+'A')return i;
        else continue;
    }
}
int cmp(const void *e1, const void *e2)
{
    str_sort *p=(str_sort *)e1,*q=(str_sort *)e2;
    char *s1=p->str,*s2=q->str;
    while(s1==s2||s1-'a'+'A'==s2||s2-'a'+'A'==s1)
        {s1++;s2++;}
    return find(p->sord,s1)-find(q->sord,s2);
}
