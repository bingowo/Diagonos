#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void conver(char a[])
{
    int i;char b[121];
    for(i=0;i<strlen(a);i++)
        b[strlen(a)-1-i]=a[i];
    b[i]='\0';
    strcpy(a,b);
}

void cmp(char*s,char*max_s,char*min_s)
{
    if(s[0]!='-')
    {
        if(max_s[0]!='-')
        {
            if(strlen(s)>strlen(max_s))strcpy(max_s,s);
            else if(strlen(s)<strlen(max_s));
            else
                if(strcmp(s,max_s)>0)strcpy(max_s,s);
        }
        else
            strcpy(max_s,s);
    }
    else
    {
        if(max_s[0]=='-')
        {
            if(strlen(s)>strlen(max_s));
            else if(strlen(s)<strlen(max_s))strcpy(max_s,s);
            else
                if(strcmp(s,max_s)<0)strcpy(max_s,s);
        }
    }
    if(s[0]!='-')
    {
        if(min_s[0]!='-')
        {
            if(strlen(s)<strlen(min_s))strcpy(min_s,s);
            else if(strlen(s)>strlen(min_s));
            else
                if(strcmp(s,min_s)<0)strcpy(min_s,s);
        }
    }
    else
    {
        if(min_s[0]!='-')strcpy(min_s,s);
        else
        {
            if(strlen(s)>strlen(min_s))strcpy(min_s,s);
            else if(strlen(s)<strlen(min_s));
            else
                if(strcmp(s,min_s)>0)strcpy(min_s,s);
        }
    }
}

void val1(char a[],char b[])
{
    conver(a);conver(b);
    int i,carry=0;char c[121];
    for(i=0;i<strlen(b);i++)
    {
        int t=a[i]-b[i]+10-carry;
        c[i]=t%10+'0';
        carry=1-t/10;
    }
    for(i=strlen(b);i<strlen(a);i++)
    {
        int t=a[i]-'0'+10-carry;
        c[i]=t%10+'0';
        carry=1-t/10;
    }
    for(int j=i-1;j>=0;j--)
        printf("%c",c[j]);
}

void val2(char a[],char b[])
{
    conver(a);conver(b);char e[121]={'\0'};
    if(strlen(a)<strlen(b)){strcpy(e,b);strcpy(b,a);strcpy(a,e);}
    int i,carry=0;char c[121]={'\0'};
    for(i=0;i<strlen(b);i++)
    {
        int t=a[i]-'0'+b[i]-'0'+carry;
        c[i]=t%10+'0';
        carry=t/10;
    }
    for(;i<strlen(a);i++)
    {
        int t=a[i]-'0'+carry;
        c[i]=t%10+'0';
        carry=t/10;
    }
    if(carry==1){c[i]=1;i++;}
    for(int j=i-1;j>=0;j--)printf("%c",c[j]);
}

void minus(char a[],char b[])
{
    if(a[0]!='-')
    {
        if(b[0]!='-')val1(a,b);
        else val2(a,b+1);
    }
    else
    {
        val1(b+1,a+1);
    }
}

int main()
{
    int n;scanf("%d",&n);char s[121]={'\0'},max_s[121]={'\0'},min_s[121]={'\0'};
    scanf("%s",s);strcpy(max_s,s);strcpy(min_s,s);
    for(int t=1;t<n;t++)
    {
        scanf("%s",s);
        cmp(s,max_s,min_s);
    }
    minus(max_s,min_s);
}