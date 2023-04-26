#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int del(char *a,char *b)
{
    if(!*a)return 1;
    char *p=a,*q=a+1,*r=b;
    int flag=0;
    while(*p&&*q)
    {
        if(*p==*q)
        {
            flag=1;
            while(*q&&*p==*q)
                q++;
        }
        else
            *r++=*p;
        p=q++;
    }
    if(*p)*r++=*p;
    *r='\0';
    if(flag&&*b)
        return !del(b,a);
    return 1;
}
int main()
{
    int T;
    scanf("%d", &T);
    char s[110];
    char table[]={'A','B','C'};
    for(int Case=0;Case<T;Case++)
    {
        scanf("%s",s);
        int len=strlen(s);
        int min=len;
        for(int i=0;i<len;i++)
        {
            for(int tt=0;tt<3;tt++)
            {
                int k=0;char t[110];
                for(int j=0;j<i;j++)
                    t[k++]=s[j];
                t[k++]=table[tt];
                for(int j=i;j<len;j++)
                    t[k++]=s[j];
                t[k++]='\0';
                char b[110];
                strcpy(b,t);
                int r=del(t,b);
                if(r)
                    if(strlen(b)<=min)min=strlen(b);
                else
                    if(strlen(t)<=min)min=strlen(t);
            }
        }
        printf("case #%d:\n%d\n",Case,len+1-min);
    }
    return 0;
}
