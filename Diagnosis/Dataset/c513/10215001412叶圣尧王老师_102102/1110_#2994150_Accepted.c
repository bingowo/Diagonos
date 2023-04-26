#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    double dx=0,dy=0;char s[81],c;
    scanf("%s",s);int i,j,k,x;
    for(i=0;i<strlen(s);i++)
        if(s[i]=='=')k=i;
        else if(!isdigit(s[i])&&s[i]!='+'&&s[i]!='-')c=s[i];
    for(i=0;i<k;i++)
    {
        if(s[i]=='+')
        {
            if(!isdigit(s[i+1]))x=1;
            else
            {
                x=0;
                for(j=i+1;isdigit(s[j]);j++)
                    x=x*10+s[j]-'0';
                i=j-1;
            }
            if(s[i+1]==c)dx+=x;
            else dy+=x;
        }
        else if(s[i]=='-')
        {
            if(!isdigit(s[i+1]))x=1;
            else
            {
                x=0;
                for(j=i+1;isdigit(s[j]);j++)
                    x=x*10+s[j]-'0';
                i=j-1;
            }
            if(s[i+1]==c)dx-=x;
            else dy-=x;
        }
        else if(isdigit(s[i]))
        {
            x=0;
            for(j=i;isdigit(s[j]);j++)
                x=x*10+s[j]-'0';
            i=j-1;
            if(s[i+1]==c)dx+=x;
            else dy+=x;
        }
    }
    for(i=k+1;i<strlen(s);i++)
    {
        if(s[i]=='+')
        {
            if(!isdigit(s[i+1]))x=-1;
            else
            {
                x=0;
                for(j=i+1;isdigit(s[j]);j++)
                    x=x*10+s[j]-'0';
                i=j-1;
            }
            if(s[i+1]==c)dx-=x;
            else dy-=x;
        }
        else if(s[i]=='-')
        {
            if(!isdigit(s[i+1]))x=1;
            else
            {
                x=0;
                for(j=i+1;isdigit(s[j]);j++)
                    x=x*10+s[j]-'0';
                i=j-1;
            }
            if(s[i+1]==c)dx+=x;
            else dy+=x;
        }
        else if(isdigit(s[i]))
        {
            x=0;
            for(j=i;isdigit(s[j])&&j<strlen(s);j++)
                x=x*10+s[j]-'0';
            i=j-1;
            if(s[i+1]==c)dx-=x;
            else dy-=x;
        }
    }
    if(dy!=0)dy=dy*-1;
    if(dx==0)printf("%c=%.3f",c,dy);
    else printf("%c=%.3f",c,dy/dx);
}