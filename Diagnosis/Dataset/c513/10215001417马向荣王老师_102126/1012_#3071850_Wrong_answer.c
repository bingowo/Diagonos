#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char str[100]={'\0'};
    scanf("%s",str);
    if(str[0]=='0'&&str[1]=='\0') printf("0");
    int start=0,rsig=1,isig=1;
    if(str[0]=='-')
    {
        start=1;
        rsig=-1;//还可能是-__i
    }
    long long tmp=0,a=0,b=0;
    while(str[start]!='+'&&str[start]!='-'&&str[start]!='\0'&&str[start]!='i')
    {
        tmp=tmp*10+str[start]-'0';
        start++;
    }
    if(str[start]=='i')
    {
        if(!tmp) b=rsig*1;
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
        if(str[start]=='i')
        {
            if(!tmp) b=1*isig;
            else b=isig*tmp;
        }
    }
    long long qr,qi;int i,k=0;
    int r[200];
    while(a!=0||b!=0)
    {
        if(abs(a)%2==abs(b)%2) r[k]=0;
        else r[k]=1;
        qr=(b-a+r[k])/2;
        qi=(a+b-r[k])/2;
        a=qr;
        b=qi;
        k++;
    }
    for(i=k-1;i>=0;i--)
    {
        printf("%d",r[i]);
    }
    return 0;
}
