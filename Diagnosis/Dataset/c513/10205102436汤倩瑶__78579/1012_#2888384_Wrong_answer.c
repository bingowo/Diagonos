#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
char s[100];
scanf("%s",s);
int l=strlen(s);
long long int a=0,b=0;
int flag=1;
long long int sum=0;
int i=0;
if(s[0]=='-')
    {flag=-1;i++;}
for(;i<l&&s[i]!='-'&&s[i]!='+'&&s[i]!='i';i++)
    {
        sum=sum*10+s[i]-'0';
    }
if(i==l)a=sum*flag;
else if(s[i]=='-'){a=sum*flag;flag=-1;sum=0;i++;
if(s[i]=='i'){
    b=flag;
}
else{
for(;s[i]!='i';i++)
    {
        sum=sum*10+s[i]-'0';
    }
    b=sum*flag;}
}
else if(s[i]=='+'){a=sum*flag;flag=1;sum=0;i++;
if(s[i]=='i'){
    b=flag;
}

else{
for(;s[i]!='i';i++)
    {
        sum=sum*10+s[i]-'0';
    }
    b=sum*flag;}
}

//printf("%lld %lld",a,b);
int ans[100]={0};
int cnt=0;
long long int qr,qi;
while(1){int r;
    if(((a+b)%2)==0){ans[cnt++]=0;r=0;}
    else {ans[cnt++]=1;r=1;}
    qi=(a+b-r)/(-2);
    qr=(a-b-r)/(-2);
    a=qr;b=qi;
    if(a==0&&b==0)break;
}
for(int k=cnt-1;k>=0;k--)
printf("%d",ans[k]);


}
