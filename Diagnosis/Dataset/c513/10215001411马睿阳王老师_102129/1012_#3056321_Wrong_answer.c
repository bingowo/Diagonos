#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{
    long long  a=0,b=0,qi=0,qr=0,c[100000];
    char s[100000];
    int i=0,k=0,j=0,l=0;
    long long sign1=1,sign2=1;
    scanf("%s",s);
    memset(c,0,sizeof(c));
    l=strlen(s);
    if(s[0]=='-')
    {
        sign1=-1;
        k=1;
    }
    for(i=k;i<l&&isdigit(s[i]);i++)
    {
        a=a*10+s[i]-'0';
    }
    a*=sign1;
    if(s[i]=='i'&&a) b=a,a=0;
    else if(s[i]=='i'&&a==0) b=1*sign1,a=0;
    else if(s[i]=='+') sign2=1;
    else if(s[i]=='-') sign2=-1;
    if(s[i+1]=='i') b=1;
    else
    {
        for(i+=1;i<l&&isdigit(s[i]);i++)
            b=b*10+s[i]-'0';
    }
    if(a!=0) b*=sign2;
    //奇偶用除以2的余数的绝对值判断
    if(abs(a%2)==abs(b%2)) c[0]=0;
    else if(abs(a%2)!=abs(b%2)) c[0]=1;
    qr=(c[0]+b-a)/2;
    qi=(c[0]-a-b)/2;
    i=1;
    while(qi||qr)
    {
        if(abs(qr%2)==abs(qi%2)) c[0]=0;
        else if(abs(qr%2)!=abs(qi%2)) c[0]=1;
        a=qr;
        b=qi;
        qr=(c[i]+b-a)/2;
        qi=(c[i]-b-a)/2;
        i++;
    }
    for(j=i-1;j>=0;j--)
        printf("%lld",c[i]);
    return 0;
}
