#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct string 
{
    char st[31];
    long long num;
    int li;
}str;
void strm(str *p)
{
    int len=strlen(p->st);
    for(int i = 0; i < len; i++)
        {
            if(p->st[i] >= '0' && p->st[i] <= '9')
            {
                p->li = 1;               
                p->num *= 10;
                p->num += p->st[i] - '0';
            }
            
        }
}
int cmp(const void *q1, const void * q2)
{
    str * p1 = (str *) q1;
    str * p2 = (str *) q2;
    if(p1->li != p2->li)
    {return p1->li - p2->li;}
    else
    {
        if(p1->num != p2->num)
        {return p1->num - p2->num;}
        else
        {return strcmp(p1->st,p2->st);}
    }
}
int main()
{
    str s[101];
    int n=0;
    int cmp(const void *q1, const void * q2);
    void strm(str *p);
    while(scanf("%s",s[n].st)!=EOF)
    {   
        s[n].num=0;
        s[n].li=0;
        n++;
    }
    for(int i=0;i<=n;i++)
    {
        strm(s+i);
    }
    qsort(s,n,sizeof(str),cmp);
    for(int i=0;i<=n;i++)
    {
        printf("%s ",s[i].st);
    }
    printf("\n");
    return 0;
}