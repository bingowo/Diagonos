#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
    char s[31];
    long long a=0,b=0,c=1;
    int i,j;
    scanf("%s",s);
    for(i=0;i<strlen(s)&&s[i]!='.';i++)
    {
            if(s[i]=='2') a=a*3-1;
            else a=a*3+s[i]-'0';
    }
    if(s[i]=='.')
    {
        j=i+1;
        for(;j<strlen(s);j++)
        {
            c*=3;
            if(s[j]=='2') b=b*3-1;
            else b=b*3+s[j]-'0';
        }
        if(a>0&&b<0)
        {
            a=a-1;
            b=c+b;
        }
        else if(a<0)
        {
            a=a+1;
            b=c-b;
        }
    }
    if(a)
        printf("%lld",a);
    if(a!=0&&b!=0) printf(" ");
    if(b)
        printf("%lld %lld",b,c);
    return 0;
}