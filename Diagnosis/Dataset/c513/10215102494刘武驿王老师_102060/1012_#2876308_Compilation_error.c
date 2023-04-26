#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    long long a=0,b=0;
    char str[100];
    scanf("%s",str);
    int i,flag1=0,flag2=0,len=strlen(str);
    for(i=0;i<len;i++)
    {
        if(str[i]=='-'||str[i]=='+') flag1=i;
        if(str[i]=='i') flag2=i;
    }
    if(flag1!=0) for(i=flag1-1;i>=0;i--) a+=pow(10,flag1-i-1);
    if(flag2!=0) for(i=flag2-1;i>flag1;i--) a+=pow(10,flag2-i-1);
    int res[1000],i=1000,resi;
    long long tempa tempb;
    while(a!=0&&b!=0)
    {
        resi=(a%2+b%2)%2;
        res[i--]=resi;
        tempa=(b-a)/2;
        tempb=(-b-a)/2;
        a=tempa;
        b=tempb;
    }
    i++;
    for(;i<1000;i++) printf("%d",res[i]);
}