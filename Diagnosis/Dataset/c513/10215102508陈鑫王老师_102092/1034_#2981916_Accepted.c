#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct
{
    double num;
}jia;
jia ret[26];
int cmp(const void*a,const void*b)
{
    char x=*(char*)a;
    char y=*(char*)b;
    char h=toupper(x),t=toupper(y);
    double m=ret[h-'A'].num,n=ret[t-'A'].num;
    if(h==t) return x>y?-1:1;
    else if(m==n) h<t?-1:1;
    else return m>n?-1:1;

}
int main()
{
    int t;
    scanf("%d",&t);

    for(int i=0;i<t;i++)
    {
        for(int k=0;k<26;k++)
        {
           scanf("%lf",&ret[k].num);
        }
        char s[101];
        scanf("%s",s);
        int n=strlen(s);
        qsort(s,n,sizeof(char),cmp);
        printf("case #%d:\n",i);
        printf("%s\n",s);
    }
}
