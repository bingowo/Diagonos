#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    char s[100];
    scanf("%s",s);
    int i=0;
    double a=0,b=0;
    double flag=1,tmp=0;
    char c;
    while(s[i]!='=')
    {
        if(s[i]=='-') flag=-1;
        else if(s[i]=='+') flag=1;
        else if(s[i]>='0'&&s[i]<='9')
        {
            tmp=tmp*10+s[i]-48;
            if(s[i+1]=='+'||s[i+1]=='-'||s[i+1]=='=') {b+=tmp*flag;tmp=0;}
        }

        else if(s[i]>='a'&&s[i]<='z')
        {
            c=s[i];
            if(tmp==0) a+=flag;
            else a+=flag*tmp;
            tmp=0;
        }
        i++;
    }
    while(s[i]!='\0')
    {
        if(s[i]=='-') flag=-1;
        else if(s[i]=='+') flag=1;
        else if(s[i]>='0'&&s[i]<='9')
        {
            tmp=tmp*10+s[i]-48;
            if(s[i+1]=='+'||s[i+1]=='-'||s[i+1]=='\0') {b-=tmp*flag;tmp=0;}
        }

        else if(s[i]>='a'&&s[i]<='z')
        {
            if(tmp==0) a-=flag;
            else a-=flag*tmp;
            tmp=0;
        }
        i++;
    }
    b=-b;
    double ans=b/a;
    printf("%c=%.3f",c,ans);

    return 0;
}
