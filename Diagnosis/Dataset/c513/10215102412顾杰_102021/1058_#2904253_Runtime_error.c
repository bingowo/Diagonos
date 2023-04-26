#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<malloc.h>
int notcent(char*p,char*s)
{
    int i=1,f=0;
    while(p-i>=s)
    {
        if(*(p-i)=='"'){f++;break;}
        else if(*(p-i)=='\n')return 1;
        i++;}
    i=1;
    while(*(p+i))
    {
        if(*(p+i)=='"'){f++;break;}
        else if(*(p+i)=='\n')return 1;
        i++;}
    if(f==2)return 0;
    return 1;
}
int main()
{
    int i=0;
    char *s,c,*p=s,*p0;
    s=(char*)malloc(1000000000);
    while((c=getchar())!=EOF)s[i++]=c;
    s[i++]='\n';s[i]=0;
    while(*p)
    {
        if(*p=='/'&&notcent(p,s))
        {
            if(*(p+1)=='/')
                {*p=0;
                p0=p;
                while(*p!='\n')p++;
                strcat(s,p);
                p=p0;
                }
            if(*(p+1)=='*')
                {*p=0;
                p0=p;
                while(*p!='*'||*(p+1)!='/')p++;
                p+=2;
                strcat(s,p);
                p=p0;
                }
        }
        else p++;
    }
    printf("%s",s);
    free(s);
    return 0;
}
