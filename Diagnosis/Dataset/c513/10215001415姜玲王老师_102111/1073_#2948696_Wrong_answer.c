#include <stdlib.h>
#include<string.h>
long long f(char*a)
{long long sum=0;
for(int i=0;i<strlen(a);i++)
{sum=sum*9+a[i]-'0';}
return sum+1;}
long long h(char*a)
{long long sum=0;
for(int i=0;i<strlen(a);i++)
{sum=sum*10+a[i]-'0';}
return sum;}
long long g(long long c,long long f2)
{long long x0;
x0=f2%9;
long long n=0;
for(int i=0;i<x0;i++)
{char str[20]={0};
sprintf(str,"%lld",c-x0);
if(strchr(str,'9')) {x0++;continue;}
if((c-x0)%9) n++;
}
return n;}
int main()
{char a[20],b[20];
long long f1,f2,answer,c,d;
scanf("%s%s",a,b);
c=h(a);
d=h(b);
f1=f(a);
f2=f(b);
answer=(f2/9)*8+g(d,f2)-(f1/9)*8-g(c,f1)+1;
printf("%lld",answer);

}
