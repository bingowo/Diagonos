#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000020

int main()
{
    char c; int i,n;
    char s[MAX]={0};
    for (i=0;i<MAX && (c=getchar())!=EOF ;i++)
    {
        s[i]=c;
    }
    n=i;
    for (i=0;i<n-1;i++)
    {
        if ((int)s[i]==39)
        {
            printf("%c",s[i++]);
            while ((int)s[i]!=39)
            {
                printf("%c",s[i++]);

            }
            printf("%c",s[i]);
        }
        else if (s[i]=='"')
        {
            printf("%c",s[i++]);
            while (!(s[i]=='"' && (s[i+1]==';' || s[i+1]==' ')))
            {
                printf("%c",s[i++]);

            }
            printf("%c",s[i]);
        }
        else if (s[i]=='/')
        {
            if (s[i+1]=='/')
            {
                i+=2;
                while (s[i]!='\n')
                    i++;
                printf("%c",s[i]);
            }
            if (s[i+1]=='*')
            {
                i+=2;
                while (!(s[i]=='*' && s[i+1]=='/'))
                    i++;
                if (s[i]=='*' && s[i+1]=='/')
                {
                    i++;
                }


            }


        }
        else
            printf("%c",s[i]);
    }
    printf("%c",s[i]);
    return 0;
}
