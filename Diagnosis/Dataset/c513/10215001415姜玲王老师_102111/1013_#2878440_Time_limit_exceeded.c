#include <stdio.h>
#include <stdlib.h>
#include<string.h>
long long int GCD(long long int a,long long int b)
{long long int c;
    while(a%b)
{c=a%b;
a=b;
b=c;
}
return b;}
int main()
{long long int A=0,B=0,C=1,t;
char s[31];
scanf("%s",s);
int p=0;
while(p<strlen(s))
{if(s[p]=='.') {p++;break;}
A*=3;
if(s[p]=='1') A++;
if(s[p]=='2') A--;
p++;}
while(p<strlen(s))
{B*=3;C*=3;
if(s[p]=='1')  B++;
if(s[p]=='2') B--;}
if(A)
{if(A>0&&B<0){A--;B=C+B;}
if(A<0&&B>0){A++;B=C-B;}
printf("%lld ",A);}
if(B)
{t=GCD(C,B);
printf("%lld %lld",B/t,C/t);}}

