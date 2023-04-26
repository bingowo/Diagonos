#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char* c)
{
    int i,j;
    char s;
    for(i=0,j=strlen(c)-1;i<j;i++,j--)
    {
        s=c[i];
        c[i]=c[j];
        c[j]=s;
    }

}

int main()
{
    char s[10000]={'\0'};
    scanf("%s",s);
    long long int a=0,b=0;//a是实数部，b是虚数部
    int i=0,l=0;
    if(s[0]=='0')
        printf("0");
    else
    {
    if(s[0]!='i'&&s[0]!='-')//开头是数字的情况
    {
        for(i=0;s[i];i++)
        {
            if(s[i]=='+'||s[i]=='-')
                l=l+1;
        }
        if(l==0)//没有正负号的情况
        {
            for(i=0;s[i];i++)
            {
                if(s[i]=='i')
                l=l+1;
            }
            if(l==0)//没有i的情况
            {
                for(i=0;s[i];i++)
                    a=10*a+s[i]-48;
                b=0;
            }
            else//有i的情况
            {
                for(i=0;s[i]!='i';i++)
                    b=10*b+s[i]-48;
                a=0;
            }
        }
        else
        {
            int n;
            for(i=0;s[i]!='+'&&s[i]!='-';i++)
                a=10*a+s[i]-'0';
            n=(s[i]=='-')?(-1):1;
            if(s[++i]=='i')//a+i的情况
                b=n;
            else
            {
                for(;s[i]!='i';i++)
                    b=10*b+s[i]-48;
                b=b*n;
            }
        }
    }
    else
    {
        if(s[0]=='i')
        {
            a=0;
            b=1;
        }
        else
        {
            if(s[0]=='-')//开头是负号的情况
            {
                if(s[1]=='i')//-i的情况
                    {
                        a=0;
                        b=-1;
                    }
                else//后面是数字的情况
                {
                    for(i=1;s[i];i++)
                    {
                        if(s[i]=='+'||s[i]=='-')
                            l=l+1;
                    }
                    if(l==0)//后面没有正负号的情况
                    {
                        for(i=1;s[i];i++)
                        {
                            if(s[i]=='i')