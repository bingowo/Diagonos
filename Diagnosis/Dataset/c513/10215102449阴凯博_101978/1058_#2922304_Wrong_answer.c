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
        if (s[i]=='"')
        {
            printf("%c",s[i++]);
            while (s[i]!='"')
            {
                printf("%c",s[i++]);
            }
        }
        else if (s[i]=='/')
        {
            i++;
            if (s[i]=='/')
            {
                i++;
                while (s[i]!='\n')
                    i++;
            }
            if (s[i]=='*')
            {
                i++;
                while (s[i]!='*' )
                    i++;
                while (s[i]=='*' && s[i+1]!='/')
                    i++;
                if (s[i+1]=='/' && s[i]=='*')
                    i+=2;
            }


        }
        printf("%c",s[i]);
    }
    printf("%c",s[i]);

    return 0;
}
