#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char sord[30];
    char *str[100];
}str_sort;

int find(char *s,char c)
{
    for(int i=0;s[i];i++)
    {
        if(s[i]==c||s[i]==c-'a'+'A')return i;
        else continue;
    }
    return -1;
}

int cmp(const void *e1, const void *e2)
{
    str_sort *p=(str_sort *)e1,*q=(str_sort *)e2;
    char *s1=*(p->str),*s2=*(q->str);
    while(s1==s2||s1-'a'+'A'==s2||s2-'a'+'A'==s1)
        {s1++;s2++;}
    return find(p->sord,*s1)-find(q->sord,*s2);
}

int main()
{
    char c1;
    //printf("%c",c1=getchar());
    while((c1=getchar()!='\n')&&(c1!=EOF))
    {
        ungetc(c1,stdin);
        str_sort s;
        fgets(s.sord,30,stdin);
        int i=0;
        char c2;
        while((c2=getchar())!='\n')
        {
            ungetc(c2,stdin);
            scanf("%s",s.str[i]);
            i++;
        }
        qsort(s.str,i,sizeof(s.str[0]),cmp);
        for(int j=0;j<i;j++)printf("%s",s.str[j]);
    }
    return 0;
}

