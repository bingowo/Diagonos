#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    long long a=0,b=0,qr=0,qi=0;int r[500],k=0,i,e=1,sign;char s[40];
    for(i=0;scanf("%c",&s[i])!=EOF;i++)
    {
        if(s[i]=='+'){s[i]='\0';a=atol(s);s[i]=='+';sign=i;}
        else if(s[i]=='-'){s[i]='\0';a=atol(s);s[i]=='-';sign=i;}
        if(s[i]=='i'&&s[i-1]=='+')b=1;
        else if(s[i]=='i'&&s[i-1]=='-')b=-1;
        else if(s[i]=='i'&&(s[i-1]>'0'&&s[i-1]<'9')){s[i]='\0';b=atol(s+sign);}
    }

    while(a!=0||b!=0)
    {
        if(a%2==b%2)r[k]=0;
        else r[k]=1;
        qr=(b-a+r[k])/2;
        qi=-(a+b-r[k])/2;
        a=qr;
        b=qi;
        k++;
    }
    for(i=k-1;i>=0;i--)printf("%d",r[i]);


}
