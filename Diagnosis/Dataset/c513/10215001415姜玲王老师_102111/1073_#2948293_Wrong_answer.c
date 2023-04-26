#include <stdio.h>
#include <stdlib.h>
long long f(long long a)
{long long sum=0;
while(a)
{sum=sum*9+a%10;
a/=10;}
return sum+1;

}
long long g(long long a,long long b)
{int n=0;
for(int i=a;i<=b;i--)
{if(a%9) n++;}
return n;
}
int main()
{long long a,b,f1,f2,answer;
scanf("%lld%lld",&a,&b);
f1=f(b);
f2=f(a);
answer=f1/9*8+g(f1,f1-f1%10)-f2/9*8-g(f2,f2-f2%10)+1;
printf("%lld",answer);

}
