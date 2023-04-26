#include<stdio.h>
#include<string.h>

int main()
{
    int a,b;scanf("%d%d",&a,&b);
    if(a==0)
    {printf("0");return 0;}
    char num[100];
    int zs=a/b,remain=a%b,p=0;
    while(zs!=0)
    {
        num[p++]=zs%3+'0';
        zs/=3;
    }
    if(zs==0) num[p++]='0';
    for(int i=0;i<p/2;i++)
    {
        char c=num[i];
        num[i]=num[p-i-1];
        num[p-i-1]=c;
    }
    int t=p,ex=1;
    if(remain!=0)   
    {
        num[t++]='.';
        while(remain!=0 || ex<b)
        {
            num[t++]=remain%3+'0';
            remain/=3;ex*=3;
        }
        for(int i=p+1;i<p+1+(t-p-1)/2;i++)
        {
            char c=num[i];
            num[i]=num[t-i+p];
            num[t-i+p]=c;
        }
    }
    int carry=0;
    for(int i=t-1;i>=0;i--)
    {
        if(num[i]=='.');
        else
        {        
            int tmp=num[i]-'0'+1+carry;
            if(tmp>3)
            {
                num[i]=tmp%3+'0';
                carry=tmp/3;
            }
            else
            {
                num[i]=tmp+'0';
                carry=0;
            }
        }
    }
    if(carry!=0)
    {
        for(int i=t-1;i>=0;i--) num[i+1]=num[i];
        num[0]=carry+'0';t++;
    }
    for(int i=t-1;i>=0;i--)
    {
        int tmp=num[i]-'0'-1;
        if(tmp==-1) num[i]='2';
        else if(tmp==1) num[i]='1';
        else if(tmp==0) num[i]='0';
    }
    int start=0,end=t-1;
    for(int i=0;i<t;i++)
    {
        if(num[i]!='0' && num[i]!='.') break;
        else if(num[i]=='.') {start--;break;}
        else start++;
    }
    if(a%b!=0)
    {
        for(;end>=0;end--)
        {if(num[end]!='0') break;}
    }
    for(int i=start;i<=end;i++) printf("%c",num[i]);

    return 0;
}