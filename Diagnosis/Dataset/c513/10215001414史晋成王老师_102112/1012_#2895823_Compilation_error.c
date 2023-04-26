#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{char s[100];double a=0,b=0,qr=0,qi=0; int r[500]={0};
scanf("%lld",&a);
if(scanf("%c",&s[0]))
scanf("%lld%c",&b,&s[1]);
if(s[0]=='-') b=-b;
int g=0;
do{ if (a%2==b%2) r[g]=0;
           else r[g]=1;
    qi=(r[g]-a-b)/2;
    qr=(b-a+r[g])/2;
    a=qr;b=qi; g++;
}while(a!=0&&b!=0);
 for(int k=g-1;k>=0;k--)
 printf("%lld",r[k]);
    
    
}