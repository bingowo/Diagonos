#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Complex.h>
int main()
{char s[100];long long int a=0,b=0,qr=0,qi=0; int r[500]={0};
scanf("%lld%c%lldi",&a,&s[0],&b);
if(s[0]=='-') b=-b;
int g=0;
while((a!=0)&&(b!=0))
{ if (a%2==b%2) r[g]=0;
           else r[g]=1;
    qi=(r[g]-a-b)/2;
    qr=(b-a+r[g])/2;
    a=qr;b=qi; g++;
}
 for(int k=g-1;k>=0;k--)
 printf("%lld",r[k]);
return 0;
    
}