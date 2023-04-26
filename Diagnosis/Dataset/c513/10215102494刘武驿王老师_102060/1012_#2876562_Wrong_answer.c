#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    long long a=0,b=0;
    char str[100];
    scanf("%s",str);
    int i,flag0=-1,flag1=0,flag2=0,len=strlen(str),sig1=1,sig2=1;
    if(str[0]=='-') flag0=0;
    for(i=1;i<len;i++)
    {
        if(str[i]=='-'||str[i]=='+') flag1=i;
        if(str[i]=='i') flag2=i;
    }
    if(flag1!=0) for(i=flag1-1;i>=flag0+1;i--) a+=pow(10,flag1-i-1)*(str[i]-'0');
    if(flag1!=0&&flag2!=0) for(i=flag2-1;i>flag1;i--) b+=pow(10,flag2-i-1)*(str[i]-'0');
    if(flag2==flag1+1)
    {b=1;

    }
    if(str[flag1]=='-') b=-b;
    if(str[0]=='-') a=-a;
    if(flag1==0&&flag2==0)
    {
        i--;
        for(int j=i;j>=flag0+1;j--) a+=pow(10,i-j)*(str[i]-'0');
        if(flag0==0) a=-a;
    }
    if(flag1==0&&flag2!=0)
    {
        for(i=flag2-1;i>=flag0+1;i--) b+=pow(10,flag2-i-1)*(str[i]-'0');
        if(flag0==0) b=-b;
        if(flag2==flag0+1) b=-1;
    }
    if(str[0]=='i')
    {b=1;
    a=0;
    }
    if(str[0]==0)
    {
        a=0;
        b=0;
    }
    int res[1000],resi;
    i=999;
    long long tempa,tempb;
    while(a!=0||b!=0)
    {
        resi=abs((a%2+b%2)%2);
        if(resi==1) a--;
        res[i--]=resi;
        tempa=(b-a)/2;
        tempb=(-b-a)/2;
        a=tempa;
        b=tempb;
    }
    i++;
    for(;i<1000;i++) printf("%d",res[i]);
}
