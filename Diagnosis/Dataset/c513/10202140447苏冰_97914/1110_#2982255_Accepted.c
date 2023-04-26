#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    char s[81];
    scanf("%s",s);
    int a=0,b=0,c=0,d=0;
    int flag=1,sign=0;
    int i=0;
    char ch;
    while(s[i]!='=')
    {
        sign=0;
        if(s[i]=='+')
        {
            flag=1;i++;
        }
        else if(s[i]=='-')
        {
            flag=-1;i++;
        }
        int cnt=0;
        while(isdigit(s[i]))
        {
            cnt=cnt*10+(s[i]-'0');
            i++;
            sign=1;
        }
        cnt=cnt*flag;
        if(s[i]>='a' && s[i]<='z')
        {
            ch=s[i];
            if(sign==0) cnt=flag;
            a+=cnt;
            i++;
        }
        else b+=cnt;
    }
    i++;
    flag=1;
    while(s[i]!='\0')
    {
        sign=0;
        if(s[i]=='+')
        {
            flag=1;i++;
        }
        else if(s[i]=='-')
        {
            flag=-1;i++;
        }
        int cnt=0;
        while(isdigit(s[i]))
        {
            cnt=cnt*10+(s[i]-'0');
            sign=1;
            i++;
        }
        cnt=cnt*flag;
        if(s[i]>='a' && s[i]<='z')
        {
            ch=s[i];
            if(sign==0) cnt=flag;
            c+=cnt;
            i++;
        }
        else d+=cnt;
    }
    a=a-c;
    b=d-b;
    printf("%c=%.3f",ch,b*1.0/a);
    return 0;
}
