#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{char s[100];long long int a=0,b=0,qr=0,qi=0,n; int r[500]={0},i=1,j=0;
s[0]="f";
scanf("%lld",&n);
scanf("%s",s);
if(s[0]=='+')
{ a=n;
    if (s[1]=='i') b=1;
else{
  while(s[i]) i++;
 for(j=1;j<i-1;j++)
 { b+=pow(10,i-2-j)*(s[j]-'0');
 }
}i=0;
}
else if(s[0]=='-')
{ a=n;
    if (s[1]=='i') b=-1;
else{
  while(s[i]) i++;
 for(j=1;j<i-1;j++)
 { b+=pow(10,i-2-j)*(s[j]-'0');
 } b=-b;
}
}
else if(s[0]=='i')
{a=0;b=n;}
else if(s[0]=='f')
{a=n;b=0;}
int g=0;
while((a!=0)||(b!=0))
{ if (abs(a%2)==abs(b%2)) r[g]=0;
           else r[g]=1;
    qi=(r[g]-a-b)/2;
    qr=(b-a+r[g])/2;
    a=qr;b=qi; g++;
}
 for(int k=g-1;k>=0;k--)
 printf("%d",r[k]);
return 0;
    
}