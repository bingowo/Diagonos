#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char s[100];
    scanf("%s",s);
    int len=strlen(s);int p;char c;
    for(int i=0;i<len;i++)
    {
        if(isalpha(s[i])) c=s[i];
        if(s[i]=='=') p=i;
    }
    int xa=0,xb=0;
    for(int i=0;i<len;i++)
    {
        if(i==p) continue;
        int t=1;int temp=0;
        if(s[i]=='-') t=-1,i++;
        if(s[i]=='+') i++;
        while(isdigit(s[i])) temp=temp*10+(s[i++]-'0');
        if((s[i]!=c||i==len)&&i<=p) xb-=temp*t,i--;
        if((s[i]!=c||i==len)&&i>p) xb+=temp*t,i--;
        if(s[i]==c&&temp!=0&&i<p) xa+=temp*t;
        if(s[i]==c&&temp!=0&&i>p) xa-=temp*t;
        if(s[i]==c&&temp==0&&i<p) xa+=1*t;
        if(s[i]==c&&temp==0&&i>p) xa-=1*t;
    }
    double shu=(double)xb/xa;
    printf("%c=%.3f",c,shu);
    return 0;
}
