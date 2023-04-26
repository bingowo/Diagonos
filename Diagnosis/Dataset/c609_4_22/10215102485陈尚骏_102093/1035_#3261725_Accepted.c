#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int elim(char*a,char*b)
{
    if(!*a) return 1;
    char *p=a;
    char *q=a+1;
    char *r=b;
    int flag=0;
    while(*p&&*q)
    {
        if(*p==*q)
        {
            flag=1;
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
                char a[110],b[110];
                for(int x=0;x<j;x++)
                {
                    a[l++]=s[x];
                }
                a[l++]=tbl[k];
                for(int x=j;x<len;x++)
                {
                    a[l++]=s[x];
                }
                a[l++]='\0';
                strcpy(b,a);
                int r=elim(a,b);
                if(r)
                {
                    if(strlen(b)<=min) min=strlen(b);
                }
                else
                {
                    if(strlen(a)<=min) min=strlen(a);
                }
            }
        }
        printf("case #%d:\n",i);
        printf("%d\n",len-min+1);
    }
    return 0;
}
