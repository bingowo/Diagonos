#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char rule[30];
    char s[26];
}F;
int cmp(const void *a,const void *b)
{
    F s1=*(F *)a,s2=*(F *)b;
    int i=0;
    for(;i<strlen(s1.s)&&i<strlen(s2.s);i++)
    {
        if(s1.s[i]!=s2.s[i]) break;
    }
    if(i==strlen(s1.s)) return -1;
    else if(i==strlen(s2.s)) return 1;
    else
    {
        int i1=0,i2=0;
        for(;i1<26;i1++)
        {
            if(s1.s[i]==s1.rule[i1]||s1.s[i]==s1.rule[i1]+32) break;
        }
        for(;i2<26;i2++)
        {
            if(s2.s[i]==s2.rule[i2]||s2.s[i]==s2.rule[i2]+32) break;
        }
        if(i1>i2) return 1;
        else return -1;
    }
}
int main()
{
    char s[26];
    while(scanf("%s",s)!=EOF)
    {
        F *p=(F *) malloc(100*sizeof(F));
        int i=0;
        do{
            strcpy(p[i].rule,s);
            scanf("%s",&p[i++].s);
        }while(getchar()!='\n');
        qsort(p,i,sizeof(p[0]),cmp);
        for(int j=0;j<i;j++)
        {
            if(j!=i-1) printf("%s ",p[j].s);
            else if(j==i-1) printf("%s\n",p[j].s);
        }
        free(p);
    }
    return 0;
}
