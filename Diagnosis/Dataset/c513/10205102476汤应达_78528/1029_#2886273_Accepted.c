#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct cha{
    char c;int p;
}cha;

int cmp(const void*a,const void*b)
{return (*(cha*)a).c-(*(cha*)b).c;}

int main()
{
    int T,l,p1;scanf("%d",&T);
    getchar();
    for(int i=0;i<T;i++)
    {
        char s[201];gets(s);
        l=strlen(s);p1=0;
        char res[201]={'\0'};cha word[201];
        for(int t=0;t<l;t++)
        {
            if(isalpha(s[t])) {word[p1].c=s[t];word[p1].p=t;p1++;}
            else res[t]=s[t];
        }
        qsort(word,p1,sizeof(word[0]),cmp);p1=0;
        for(int t=0;t<l;t++) if(res[t]=='\0') res[t]=word[p1++].c;
        printf("case #%d:\n",i);
        for(int t=0;t<l;t++) printf("%c",res[t]);
        printf("\n");
    }

    return 0;
}