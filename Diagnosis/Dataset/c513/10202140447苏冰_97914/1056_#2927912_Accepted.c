#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
char s[4001][18];
char x[5005];
int cmp(const void*p,const void*q)
{
    char* a=(char*)p;
    char* b=(char*)q;
    int len1=strlen(a);
    int len2=strlen(b);
    return (len1>len2?-1:1);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",s[i]);
    }
    scanf("%s",x);
    qsort(s,n,sizeof(s[0]),cmp);
    char* p=x,*q=x;
    int flag=0;char t[20];
    while(*p!='\0')
    {
        int i;
        for(i=0;i<n;i++)
        {
            q=p;
            int j=0;
            for(j=0;j<strlen(s[i]);j++)
            {
                t[j]=*q;q++;
            }
            t[j]='\0';
            if(strcmp(t,s[i])==0)
            {
                if(flag==0)
                {
                    printf("%s",s[i]);flag=1;
                }
                else printf(" %s",s[i]);
                p=p+strlen(s[i]);
                break;
            }
        }
        if(i>=n)//说明没有找到
        {
            if(flag==0)
            {
                printf("%c",*p);flag=1;
            }
            else printf(" %c",*p);
            p++;
        }
    }
    return 0;
}
