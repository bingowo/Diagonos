#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000020

int main()
{
    char c; int i,n; int flag=0;
    char s[MAX]={0};
    for (i=0;i<MAX && (c=getchar())!=EOF ;i++)
    {
        s[i]=c;
    }
    n=i; i=0;
    while (i<n)
    {
        if ((int)s[i]==39)
        {
            printf("%c",s[i++]);
            while (!((int)s[i]==39 && (s[i+1]==';' || s[i+1]==' ' || s[i+1]=='\n' || s[i+1]=='}')) && i<n-1)
            {
                printf("%c",s[i++]);

            }
        }
        else if (s[i]=='"')
        {
            printf("%c",s[i++]);
            while (!(s[i]=='"' && (s[i+1]==';' || s[i+1]==' ' || s[i+1]=='\n' || s[i+1]=='}' || s[i+1]=='/')) && i<n-1)
            {
                printf("%c",s[i++]);

            }
        }
        else if (s[i]=='/')
        {
            if (s[i+1]=='/')
            {
                i+=2;
                while (s[i]!='\n' && i<n-1)
                    i++;
                if (i==n-2)
                    flag=1;
            }
            if (s[i+1]=='*')
            {
                i+=2;
                while (!(s[i]=='*' && s[i+1]=='/') && i<n-1)
                    i++;
                if (s[i]=='*' && s[i+1]=='/')
                {
                    i+=2;
                    if (i==n-2)
                    flag=1;
                    continue;
                }
            }
        }
        if (flag==0)
            printf("%c",s[i]);
        i++;
    }
    return 0;
}
