#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char str[100];
    scanf("%s",str);
    if(str[0]=='0') printf("0");
    int start=0,rsig=1,isig=1;
    if(str[0]=='-')
    {
        start=1;
        rsig=-1;//还可能是-__i
    }
    long long tmp=0,a,b;
    while(str[start]!='+'&&str[start]!='-'&&str[start]!='\0'&&str[start]!='i')
    {
        tmp=tmp*10+str[start]-'0';
        start++;
    }
    if(str[start]=='i')
    {
        if(tmp==0) b=rsig*1;
        else b=tmp*rsig;
    }
    else
    {
        a=rsig*tmp;
        if(str[start]=='-')
        {
            isig=-1;
        }
        start+=1;
        tmp=0;
        while(str[start]!='\0'&&str[start]!='i')
        {
            tmp=tmp*10+str[start++]-'0';
        }
        if(!tmp) b=1*isig;
        else b=isig*tmp;
    }
    long long qr,qi,i,k;
    int r[500];
    while(a!=0||b!=0)
    {
        if(abs())
    }
    return 0;
}
