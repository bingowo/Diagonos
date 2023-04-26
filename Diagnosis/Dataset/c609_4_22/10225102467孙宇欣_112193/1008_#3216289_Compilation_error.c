#include <stdio.h>
#include <ctype.h>
int a2i(char s[])
{
   { 

    int i,n ,sign;
    for (i=0;isspace(s[i]);i++);
    sign=(s[i]=='-')?-1:1;
    if(s[i]=='-'||s[i]=='+')i++;
        for(n=0;isdigit(s[i]);i++)
            n=n*10+s[i]-'0';

    return sign*n;
    int i,j;
    for(i=0,j=strlen(s)-1;i<j;i++,j--)
    {
        charc=s[i];s[i]=s[j];s[j]=c;}
        {
            void resverse char s
            int c,i,j;
            for(i=0,j=strlen(s)-1;i<j;i++
        }
    }
    }
     return 0;
 }
