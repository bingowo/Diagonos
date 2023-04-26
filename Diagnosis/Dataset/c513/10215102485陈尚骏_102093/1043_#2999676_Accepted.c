#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<stdbool.h>

int elim(char*a,char*b)
{
    if(!*a) return 1;
    char *p=a;
    char *q=a+1;
    char *r=b;
    bool flag=false;
    while(*p&&*q)
    {
        if(*p==*q)
        {
            flag=true;
            while(*q&&*p==*q)
                q++;
        }
        else *r++=*p;
        p=q++;
    }
    if(*p) *r++=*p;
    *r='\0';
    if(flag&&*b) return !elim(b,a);
    return 1;
}

int main()
{
    int T;
    scanf("%d",&T);
    char s[110];
    char tbl[]={'A','B','C'};
    for(int i=0;i<T;i++)
    {
        scanf("%s",s);
        int len=strlen(s);
        int min=len;
        for(int j=0;j<len;j++)
        {
            for(int k=0;k<3;k++)
            {
                int l=0;
                char t[110];
                for(int x=0;x<j;x++)
                {
                    t[l++]=s[x];
                }
                t[l++]=tbl[k];
                for(int x=j;x<len;x++)
                {
                    t[l++]=s[x];
                }
                t[l++]='\0';
                char b[110];
                strcpy(b,t);
                int r=elim(t,b);
                if(r)
                {
                    if(strlen(b)<=min) min=strlen(b);
                }
                else
                {
                    if(strlen(t)<=min) min=strlen(t);
                }
            }
        }
        printf("case #%d:\n",i);
        printf("%d\n",len+1-min);
    }
    return 0;
}
